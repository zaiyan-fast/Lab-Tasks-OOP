#include <bits/stdc++.h>
using namespace std;

class Wallet {
private:
    double balance;
    double dailyDepositUsed;
    double dailyWithdrawUsed;
    double depositLimit;
    double withdrawLimit;

public:
    Wallet(){}
    Wallet(double depositLimit, double withdrawLimit)
        : balance(0), dailyDepositUsed(0), dailyWithdrawUsed(0),
          depositLimit(depositLimit), withdrawLimit(withdrawLimit) {}

    bool deposit(double amount) {
        if (amount <= 0) {
            cout << "Deposit amount must be positive" << endl;
            return false;
        }
        if (dailyDepositUsed + amount > depositLimit) {
            cout << "Daily deposit limit exceeded" << endl;
            return false;
        }
        balance += amount;
        dailyDepositUsed += amount;
        cout << "Deposited: " << amount << ". New Balance: " << balance << endl;
        return true;
    }

    bool withdraw(double amount) {
        if (amount <= 0) {
            cout << "Withdrawal amount must be positive" << endl;
            return false;
        }
        if (amount > balance) {
            cout << "Insufficient balance" << endl;
            return false;
        }
        if (dailyWithdrawUsed + amount > withdrawLimit) {
            cout << "Daily withdrawal limit exceeded" << endl;
            return false;
        }
        balance -= amount;
        dailyWithdrawUsed += amount;
        cout << "Withdrew: " << amount << ". New Balance: " << balance << endl;
        return true;
    }

    double getBalance() const {
        return balance;
    }

    void resetLimits() {
        dailyDepositUsed = 0;
        dailyWithdrawUsed = 0;
    }
};

class User {
private:
    string id;
    string name;
    Wallet wallet;

public:
    User(string id, string name) : id(id), name(name) {}

    bool deposit(double amount) {
        cout << name << ": ";
        return wallet.deposit(amount);
    }

    bool withdraw(double amount) {
        cout << name << ": ";
        return wallet.withdraw(amount);
    }

    void checkBalance() const {
        cout << name << ": Current Balance: " << wallet.getBalance() << endl;
    }

    void resetLimits() {
        wallet.resetLimits();
    }
};

// Test Func by GPT
int main() {
    User alice("U001", "Alice");
    User bob("U002", "Bob");

    // Alice uses wallet
    alice.deposit(1000);
    alice.withdraw(300);
    alice.checkBalance();

    cout << "\n";

    // Bob tests limits
    bob.deposit(6000); // Exceeds deposit limit
    bob.deposit(4000); // Still too much
    bob.deposit(2000); // Should work
    bob.withdraw(5000); // Too much
    bob.withdraw(1000); // OK
    bob.checkBalance();

    cout << "\nResetting limits for next day...\n\n";
   
    // Simulate next day
    alice.resetLimits();
    bob.resetLimits();

    bob.deposit(3000);
    bob.checkBalance();

    return 0;
}
