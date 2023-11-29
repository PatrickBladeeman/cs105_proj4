#include "Account.h"

class Checking : public Account {
public:
    Checking(double initialBalance, double interestRate);

    void withdraw(double amount) override;
    void monthlyProc() override;
};

