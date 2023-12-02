// File Name: Checking.cpp
//
// Authors: Bryan Zhao, Regina Zhou
// Date: 12/1/2023
// Assignment Number 4
// CS 105C Fall 2023
// Instructor: Dr. Palacios
//
// Implements the checking account
#include "Checking.h"
#include <stdio.h>
// Checking: constructor of Checking class.
// balance balance of the account
// annualInterestRate annual interest rate
Checking::Checking(double balance, double annualInterestRate) : Account(balance, annualInterestRate){
    setMonthlyServiceCharges(5);
}

//Author: Regina
// withdraw: withdraw amount from Checking account
// amount amount of money to withdraw
void Checking::withdraw(double amount) {
    // Check if withdrawal will cause the balance to go below $0
    if (getBalance() - amount < 0) {
        // Apply a service charge of $15
        serviceCharge(15);
    } else {
        // Call the base class function
        Account::withdraw(amount);
    }
}

//Author: Bryan & Regina
//monthlyProc: calculate and charge service fees based on the number
//of withdrawals and then call monthlyProc to update service fee num
double Checking::monthlyProc() {
    // Calculate the monthly fee
    double monthlyFee = 5.0 + 0.10 * getNumWithdrawals();
    //cout << getNumWithdrawals();
    //cout << "In Checking.monthlyProc, current number of withdraw: " << getNumWithdrawals();
    // Add the monthly fee to the service charges
    setMonthlyServiceCharges(monthlyFee);
    //serviceCharge(monthlyFee);

    // Call the base class function
    return Account::monthlyProc();
}

//Author: Bryan
//serviceCharge: deduct service charges from the account balance and 
//increment the monthlyServiceCharges member variable
void Checking::serviceCharge(double amount) {
    //setBalance(getBalance() - amount);
    setMonthlyServiceCharges(getMonthlyServiceCharges() + amount);
}




