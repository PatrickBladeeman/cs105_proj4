
#ifndef ACCOUNT_H
#define ACCOUNT_H
class Account {
private:
    double balance;
    int numDeposits;
    int numWithdrawals;
    double annualInterestRate;
    double monthlyServiceCharges;

public:
    Account(double initialBalance, double interestRate);

    virtual void deposit(double amount);
    virtual void withdraw(double amount);
    virtual void calcInt();
    virtual void monthlyProc();

    double getBalance() const {return balance;};
    void setBalance(double amount) {balance = amount;};
    int getNumDeposits() const {return numDeposits;};
    int getNumWithdrawals() const {return numWithdrawals;};
    double getAnnualInterestRate() const {return annualInterestRate;};
    double getMonthlyServiceCharges() const {return monthlyServiceCharges;};
    void setMonthlyServiceCharges(double amount) {monthlyServiceCharges = amount;};
};

#endif // ACCOUNT_H
