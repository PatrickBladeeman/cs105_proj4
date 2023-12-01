#include "Saving.h"

Saving::Saving(double balance, double annualInterestRate) : Account(balance, annualInterestRate) {
    if (balance < 25.0) {status = false;}
}
void Saving::withdraw(double amount) {
    if (status) {Account::withdraw(amount);}
}

void Saving::deposit(double amount) {
    if (status) {
        Account:deposit(amount);
    }
    else if (!status && (getBalance() + amount) >= 25.0) {
        status = true;
        Account:deposit(amount);
    }
}

void Saving::monthlyProc() {
    double monthlyFee = (getNumWithdrawals() > 4) ? (double) getNumWithdrawals() - 4 : 0;
    serviceCharge(monthlyFee);
    if (getBalance() < 25.0) {
        status = false;
    }
}

void Saving::serviceCharge(double amount) {
    setBalance(getBalance() - amount);
    setMonthlyServiceCharges(getMonthlyServiceCharges() + amount);
}
