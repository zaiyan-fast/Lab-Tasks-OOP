#include <iostream>
using namespace std;

class Account {
private:
    double balance;

public:
    Account(double initialBalance = 0) {
        this->balance = initialBalance;
    }

    void credit(double amount) {
        this->balance += amount;
    }

    void debit(double amount) {
        if (amount <= balance) 
            balance -= amount;
        else 
            cout << "Debit amount exceeded balance" << endl;
        
    }

    double getBalance() {
        return balance;
    }
};

int main() {
    Account account(1000);

    cout << "Initial balance: " << account.getBalance() << endl;

    account.credit(500);
    cout << "After crediting 500: " << account.getBalance() << endl;

    account.debit(200);
    cout << "After debiting 200: " << account.getBalance() << endl;

    account.debit(5000);
    return 0;
}