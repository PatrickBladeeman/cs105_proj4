#include <fstream>
#include <stdio.h>
#include <iomanip>  
#include <iostream>
#include <string>
#include <cmath>
#include "Account.h"
#include "Savings.h"
#include "Checking.h"
using namespace std;


Account* initAcc(ifstream* inputFile);

int main() {
    cout << "HELLOW HAI" << endl;
    ifstream inputFile("test1.txt");
    if (!inputFile.is_open()) {
        cerr << "File does not exist." << endl;
        return -1;
    }
    cout << "FILE WORKS" << endl;
    // char checkingFlag = 'C';
    // char monthFlag = 'X';
    // char savingsFlag = 'S';
    // char curAccount;
    // double curTransaction;
    // while (input >> curAccount)
    // while (input >> curTransaction) {
    //     if (curTransaction < 0) {
    //         cout << "Withdrawal - " << abs(curTransaction) << "dollars" << endl;
    //     } else if (curTransaction > 0) {
    //         cout << "Deposit - " << curTransaction << "dollars" << endl;
    //     }
    // }
    Account* curAccount = initAcc(&inputFile);
    if (curAccount == nullptr) {
        cerr << "Incorrect Account Type" << endl;
        return -1;
    }

    double curTransaction;
    double initialBalance = curAccount->getBalance();
    // cout << "initBalance: " << curAccount->getBalance() << endl;
    // cout << "initInterest: " << curAccount->getAnnualInterestRate() << endl;
    string line = "";
    while(getline(inputFile, line)){
        int amount = stod(line);
        if(amount > 0){
            curAccount->deposit(amount);
            cout << "deposit: $" << amount << endl;
        } else if (amount < 0) {
            curAccount->withdraw(abs(amount));
            cout << "withdraw: $" << abs(amount) << endl;
        }
    }
//     beginning balance, total dollar amount
// of deposits, total dollar amount of withdrawals, interest dollar amount, service
// charges dollar amount, and ending balance.
    cout << "Monthly Summary: " << endl;
    cout << "Beginning Balance: $" << setprecision(3) << initialBalance << endl;
    cout << "Total deposits: $" << setprecision(3) << curAccount->getDeposits() << endl;
    cout << "Total withdrawals: $" << setprecision(3) << curAccount->getWithdrawals() << endl;
    cout << "Monthly Interest: $" << curAccount->getAnnualInterestRate() / 12.0<< endl;
    cout << "Total service charges: $" << setprecision(3) << curAccount->getMonthlyServiceCharges() << endl;
    cout << "Ending balance: $" << setprecision(3) << curAccount->getBalance()<< endl;
    curAccount->monthlyProc();
    return 0;
}

Account* initAcc(ifstream* inputFile) {
    Account* currentAccount = nullptr;
    double initBalance, initInterest;
    char accountType;

    *inputFile >> accountType >> initBalance >> initInterest;
    //cout << accountType << initBalance << initInterest;
    if (accountType == 'C') {
        currentAccount = new Checking(initBalance, initInterest);
    } else if (accountType == 'S') {
        currentAccount = new Savings(initBalance, initInterest);
    } 
   
    return currentAccount;
}

void processTransactions(ifstream* inputFile) {
    
}

