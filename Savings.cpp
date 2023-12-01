#include "Savings.h"

Savings::Savings(double balance, double annualInterestRate) : Account(balance, annualInterestRate) {
    if (balance < 25.0) {status = false;}
}
void Savings::withdraw(double amount) {
    if (status) {Account::withdraw(amount);}
}

void Savings::deposit(double amount) {
    if (status) {
        Account:deposit(amount);
    }
    else if (!status && (getBalance() + amount) >= 25.0) {
        status = true;
        Account:deposit(amount);
    }
}

void Savings::monthlyProc() {
    double monthlyFee = (getNumWithdrawals() > 4) ? (double) getNumWithdrawals() - 4 : 0;
    serviceCharge(monthlyFee);
    if (getBalance() < 25.0) {
        status = false;
    }
}

void Savings::serviceCharge(double amount) {
    setBalance(getBalance() - amount);
    setMonthlyServiceCharges(getMonthlyServiceCharges() + amount);
}
