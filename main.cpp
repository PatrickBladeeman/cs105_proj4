// File Name: main.cpp
//
// Authors: Bryan Zhao, Regina Zhou
// Date: 12/1/2023
// Assignment Number 4
// CS 105C Fall 2023
// Instructor: Dr. Palacios
//
// Implements chekcing and savings account; manages deposits, withdrawals, and 
// summarize.
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <iomanip>  
#include <iostream>
#include <string>
#include <cmath>
#include <istream>
#include "Account.h"
#include "Savings.h"
#include "Checking.h"
using namespace std;


Account* initAcc(ifstream* inputFile, char accountType);
void displayInfo(Account* curAccount, double initialBalance);

int main() {
    //author: Bryan & Regina
    
    //open txt file
    ifstream inputFile("test1.txt");
    if (!inputFile.is_open()) {
        cerr << "File does not exist." << endl;
        return -1;
    }
   
   //init first account
    char next;
    inputFile >> next;
    Account* curAccount = initAcc(&inputFile, next);
    if (curAccount == nullptr) {
        cerr << "Incorrect Account Type" << endl;
        return -1;
    }

    double curTransaction;
    double initialBalance = curAccount->getBalance();

    //iterate through all lines
    string line = "";
    while(getline(inputFile, line)) {
        std::istringstream iss(line);
        bool isNegative = false;
        char next = line[0];
        //cout << "value: " << next << endl;
        if (next >= '0' && next <= '9' || next == 45) {
            //if here then digit
            if(next == 45){
                isNegative = true;
            }
            iss >> curTransaction;
            if(curTransaction > 0 && !isNegative){
                curAccount->deposit(curTransaction);
                cout << "deposit: $" << curTransaction;
                cout << "   curBalance: $" << curAccount->getBalance() << endl;
            } else {
                curAccount->withdraw(abs(curTransaction));
                cout << "withdraw: $" << curTransaction;
                cout << "   curBalance: $" << curAccount->getBalance() << endl;
            }
        } else if (next == 'C' || next == 'S') {
            //if here then init new Acc
            displayInfo(curAccount, initialBalance);
            cout << endl;
            curAccount = initAcc(&inputFile, next);
            initialBalance = curAccount->getBalance();
        }
        
    }
    return 0;
}

//method to initialize a new account and return the dynamically 
//allocated object pointer
//author: Bryan
Account* initAcc(ifstream* inputFile, char accountType) {
    Account* currentAccount = nullptr;
    double initBalance, initInterest;
    *inputFile >> initBalance >> initInterest;
    if (accountType == 'C') {
        currentAccount = new Checking(initBalance, initInterest);
    } else if (accountType == 'S') {
        currentAccount = new Savings(initBalance, initInterest);
    }    
    return currentAccount;
}

//Display all relevant info on curAccount
//author: Bryan & Regina
void displayInfo(Account* curAccount, double initialBalance) {
    cout << "Monthly Summary: " << endl;
    cout << "Beginning Balance: $" << initialBalance << endl;
    cout << "Total deposits: $" << curAccount->getDeposits() << endl;
    cout << "num deposits: " <<  curAccount->getNumDeposits() << endl;
    cout << "Total withdrawals: $" << curAccount->getWithdrawals() << endl;
    double finalInterest = curAccount->getAnnualInterestRate() / 12.0;
    cout << "Monthly Interest: $" << finalInterest << endl;
    cout << "num of withdraw: " << curAccount->getNumWithdrawals() << endl;
    double finalBalance = curAccount->getBalance();
    double finalFee = curAccount->monthlyProc();
    finalBalance -= (finalFee + finalInterest);
    cout << "Total service charges: $" << finalFee << endl;
    cout << "Ending balance: $" << finalBalance<< endl;
}

