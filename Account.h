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

    double getBalance() const;
    int getNumDeposits() const;
    int getNumWithdrawals() const;
    double getAnnualInterestRate() const;
    double getMonthlyServiceCharges() const;
};
