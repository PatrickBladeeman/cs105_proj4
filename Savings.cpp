// File Name: Savings.cpp
//
// Authors: Bryan Zhao, Regina Zhou
// Date: 12/1/2023
// Assignment Number 4
// CS 105C Fall 2023
// Instructor: Dr. Palacios
//
// Implements Savings account
#include "Savings.h"

//Author: Bryan
// Savings: constructor of Savings class.
// balance current balance
// annualInterestRate annual interest rate
Savings::Savings(double balance, double annualInterestRate) : Account(balance, annualInterestRate) {
    if (balance < 25.0) {status = false;}
}

// Author: Bryan
// withdraw: withdraw amount from savings account
// amount amount of money to withdraw
void Savings::withdraw(double amount) {
    // check status before withdraw
    if (status) {Account::withdraw(amount);}
}

//Author: Bryan & Regina
// deposit: deposit amount to savings account
// amount amount of money to deposit
void Savings::deposit(double amount) {
    
    if (status) {
        Account::deposit(amount);
    }
    else if (!status && (getBalance() + amount) >= 25.0) {
        status = true;
        Account::deposit(amount);
    }
}

//Author: Bryan
// monthlyProc: checks the number of withdrawals and apply monthly service charge
double Savings::monthlyProc() {
    double monthlyFee = (getNumWithdrawals() > 4) ? (double) getNumWithdrawals() - 4 : 0;
    setMonthlyServiceCharges(getMonthlyServiceCharges() + monthlyFee);
    //serviceCharge(monthlyFee);
    if (getBalance() < 25.0) {
        status = false;
    }
    return monthlyFee;
}

