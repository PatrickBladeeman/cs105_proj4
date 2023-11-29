#include "Account.h"

class Saving : public Account {
private:
    bool status; // active or inactive

public:
    Saving(double initialBalance, double interestRate);

    void withdraw(double amount) override;
    void deposit(double amount) override;
    void monthlyProc() override;
};


