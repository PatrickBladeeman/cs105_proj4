#include "Account.h"

class Checking : public Account {
    private:
        void serviceCharge(double amount);
    public:
        Checking(double initialBalance, double interestRate);
        void withdraw(double amount) override;
        void monthlyProc() override;

};

