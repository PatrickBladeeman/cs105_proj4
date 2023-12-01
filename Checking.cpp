// Checking.cpp
#include "Checking.h"

Checking::Checking(double balance, double annualInterestRate) : Account(balance, annualInterestRate){
    setMonthlyServiceCharges(5);
}

//Author: Regina
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
//calculate and charge service fees based on the number
//of withdrawals and then call monthlyProc to update service fee num
void Checking::monthlyProc() {
    // Calculate the monthly fee
    double monthlyFee = 5.0 + 0.10 * getNumWithdrawals();

    // Add the monthly fee to the service charges
    setMonthlyServiceCharges(getMonthlyServiceCharges() + monthlyFee);
    //serviceCharge(monthlyFee);

    // Call the base class function
    Account::monthlyProc();
}

//Author: Bryan
//deduct service charges from the account balance and 
//increment the monthlyServiceCharges member variable
void Checking::serviceCharge(double amount) {
    //setBalance(getBalance() - amount);
    setMonthlyServiceCharges(getMonthlyServiceCharges() + amount);
}




