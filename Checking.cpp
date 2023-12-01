// Checking.cpp
#include "Checking.h"

Checking::Checking(double balance, double annualInterestRate) : Account(balance, annualInterestRate){
    setMonthlyServiceCharges(5);
}

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

void Checking::monthlyProc() {
    // Calculate the monthly fee
    double monthlyFee = 5.0 + 0.10 * getNumWithdrawals();

    // Add the monthly fee to the service charges
    serviceCharge(monthlyFee);

    // Call the base class function
    Account::monthlyProc();
}

void Checking::serviceCharge(double amount) {
    setBalance(getBalance() - amount);
    setMonthlyServiceCharges(getMonthlyServiceCharges() + amount);
}




