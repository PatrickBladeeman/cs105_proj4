#include "Savings.h"


//Author: Bryan
Savings::Savings(double balance, double annualInterestRate) : Account(balance, annualInterestRate) {
    if (balance < 25.0) {status = false;}
}

//Author: Bryan
void Savings::withdraw(double amount) {
    // check status before withdraw
    if (status) {Account::withdraw(amount);}
}

//Author: Bryan & Regina
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
void Savings::monthlyProc() {
    double monthlyFee = (getNumWithdrawals() > 4) ? (double) getNumWithdrawals() - 4 : 0;
    setMonthlyServiceCharges(getMonthlyServiceCharges() + monthlyFee);
    //serviceCharge(monthlyFee);
    if (getBalance() < 25.0) {
        status = false;
    }
}

//Author: Regina
void Savings::serviceCharge(double amount) {
    setBalance(getBalance() - amount);
    setMonthlyServiceCharges(getMonthlyServiceCharges() + amount);
}
