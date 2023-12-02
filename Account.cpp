// File Name: Account.cpp
//
// Authors: Bryan Zhao, Regina Zhou
// Date: 12/1/2023
// Assignment Number 4
// CS 105C Fall 2023
// Instructor: Dr. Palacios
//
// Implements the general account
#include "Account.h"
// Author: Bryan
// Account: constructor of Account class.
// initialbalance balance at the beginning
// interestRate annual interest rate
Account::Account(double initialBalance, double interestRate) {
    balance = initialBalance;
    numDeposits = 0;
    numWithdrawals = 0;
    annualInterestRate = interestRate;
    monthlyServiceCharges = 0;
}
// Author: Bryan
// deposit: deposit amount to account
// amount amount of money to deposit
void Account::deposit(double amount) {
    balance += amount;
    depositAmt += amount;
    numDeposits++;
}
// Author: Regina
// withdraw: withdraw amount from account
// amount amount of money to withdraw
void Account::withdraw(double amount) {
    balance -= amount;
    withdrawalAmt += amount;
    numWithdrawals++;
}
// Author: Regina
// calcInt: updates the balance by: calculating the monthly interest
// earned by the account, and adding this interest to the balance.
void Account::calcInt() {
    double monthlyInterestRate = annualInterestRate / 12.0;
    double monthlyInterest = balance * monthlyInterestRate;
    balance += monthlyInterest;
}
// Author: Bryan & Regina
// monthlyProc: subtracts the monthly service charges from the
// balance, and then sets the variables that hold the number of
// withdrawals, number of deposits, and monthly service charges to zero.
double Account::monthlyProc() {
    balance -= monthlyServiceCharges;
    double temp = monthlyServiceCharges;
    calcInt();
    numDeposits = 0;
    numWithdrawals = 0;
    monthlyServiceCharges = 0;
    depositAmt = 0;
    withdrawalAmt = 0;
    return temp;
}


