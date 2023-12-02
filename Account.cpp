#include "Account.h"

Account::Account(double initialBalance, double interestRate) {
    balance = initialBalance;
    numDeposits = 0;
    numWithdrawals = 0;
    annualInterestRate = interestRate;
    monthlyServiceCharges = 0;
}

void Account::deposit(double amount) {
    balance += amount;
    depositAmt++;
    numDeposits++;
}

void Account::withdraw(double amount) {
    balance -= amount;
    withdrawalAmt++;
    numWithdrawals++;
}

void Account::calcInt() {
    double monthlyInterestRate = annualInterestRate / 12.0;
    double monthlyInterest = balance * monthlyInterestRate;
    balance += monthlyInterest;
}

void Account::monthlyProc() {
    balance -= monthlyServiceCharges;
    calcInt();
    numDeposits = 0;
    numWithdrawals = 0;
    monthlyServiceCharges = 0;
    depositAmt = 0;
    withdrawalAmt = 0;
    int num = 29;
}


