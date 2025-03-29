#include <bits/stdc++.h>
using namespace std;

class Account {
protected:
    string accNumber;
    string holderName;
    double balance;

public:
    Account(string num, string name, double bal)
        : accNumber(num), holderName(name), balance(bal) {}

    virtual void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: " << amount << ". New Balance: " << balance << endl;
        } else
            cout << "Invalid amount" << endl;
    }

    virtual void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawn: " << amount << ". New Balance: " << balance << endl;
        } else
            cout << "Insufficient balance or invalid amount" << endl;
    }

    virtual double calculateInterest() = 0;

    virtual void print() {
        cout << "Account Statement:" << endl;
        cout << "Holder: " << holderName << endl;
        cout << "Number: " << accNumber << endl;
        cout << "Balance: " << balance << endl;
    }

    virtual ~Account() {}
};

class SavingsAccount : public Account {
    double intRate;
    double minBalance;

public:
    SavingsAccount(string accNum, string holder, double bal, double rate, double minBal)
        : Account(accNum, holder, bal), intRate(rate), minBalance(minBal) {}

    double calculateInterest() override {
        return balance * (intRate / 100);
    }

    void withdraw(double amount) override {
        if (balance - amount >= minBalance) {
            Account::withdraw(amount);
        } else {
            cout << "Withdrawal denied" << endl;
        }
    }

    void print() override {
        Account::print();
        cout << "Interest Rate: " << intRate << "%" << endl;
        cout << "Minimum Balance: " << minBalance << endl;
    }
};

class CheckingAccount : public Account {
public:
    CheckingAccount(string accNum, string holder, double bal)
        : Account(accNum, holder, bal) {}

    double calculateInterest() override {
        return 0.0;
    }
};

class FixedDepositAccount : public Account {
    double fixedIntRate;
    int maturityDate;

public:
    FixedDepositAccount(string num, string holder, double bal, double rate, int maturity)
        : Account(num, holder, bal), fixedIntRate(rate), maturityDate(maturity) {}

    double calculateInterest() override {
        return balance * (fixedIntRate / 100);
    }

    void withdraw(double amount) override {
        cout << "Withdrawal not allowed before it is matured" << endl;
    }

    void print() override {
        Account::print();
        cout << "Fixed Interest Rate: " << fixedIntRate << "%" << endl;
        cout << "Maturity Date: " << maturityDate << endl;
    }
};

// Main by GPT
int main() {
    SavingsAccount sa("12345", "Alice", 5000, 3.5, 1000);
    CheckingAccount ca("67890", "Bob", 2000);
    FixedDepositAccount fda("11223", "Charlie", 10000, 5.0, 2026);

    cout << endl << "--- Savings Account ---" << endl;
    sa.deposit(1000);
    sa.withdraw(4500);
    sa.print();

    cout << endl << "--- Checking Account ---" << endl;
    ca.deposit(500);
    ca.withdraw(2500);
    ca.print();

    cout << endl << "--- Fixed Deposit Account ---" << endl;
    fda.deposit(2000);
    fda.withdraw(500);
    fda.print();

    return 0;
}
