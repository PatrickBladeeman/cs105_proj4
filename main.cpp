#include <fstream>
#include <stdio.h>
#include <iostream>
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
    cout << "initBalance: " << curAccount->getBalance() << endl;
    cout << "initInterest: " << curAccount->getAnnualInterestRate() << endl;

    
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
    } else {
        currentAccount = new Savings(initBalance, initInterest);
    }
   
    return currentAccount;
}