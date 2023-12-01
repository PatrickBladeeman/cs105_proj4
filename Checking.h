#include "Account.h"
#ifndef CHECKING_H
#define CHECKING_H
class Checking : public Account {
    private:
        void serviceCharge(double amount);
    public:
        Checking(double initialBalance, double interestRate);
        void withdraw(double amount) override;
        void monthlyProc() override;

};

#endif // CHECKING_H

