#ifndef SAVINGS_H
#define SAVINGS_H

#include "Account.h"

class Savings : public Account {
private:
    bool status; // active or inactive

public:
    Savings(double initialBalance, double interestRate);

    void withdraw(double amount) override;
    void deposit(double amount) override;
    void monthlyProc() override;
    void serviceCharge(double amount);
};


#endif // SAVINGS_H


