#include <bits/stdc++.h>
using namespace std;

class BankAccount
{
private:
    long accNum;
    double balance;
    bool isFrozen;

public:
    BankAccount(long num, double bal) : accNum(num), balance(bal), isFrozen(false) {}
    double getBalance()
    {
        return balance;
    }
    void setBalance(double b)
    {
        balance = b;
    }
    void freeze()
    {
        isFrozen = true;
    }
    void unfreeze()
    {
        isFrozen = false;
    }
    virtual void deposit(double amount)
    {
        if (!isFrozen)
        {
            if (amount > 0)
            {
                balance += amount;
                cout << amount << " deposited. New balance: " << balance << endl;
            }
            else
            {
                cout << "Invalid deposit amount." << endl;
            }
        }
        else
        {
            cout << "Account is frozen. Cannot deposit." << endl;
        }
    }
    virtual void withdraw(double amount)
    {
        if (!isFrozen)
        {
            if (amount > 0 && amount <= balance)
            {
                balance -= amount;
                cout << amount << " withdrawn. New balance: " << balance << endl;
            }
            else
            {
                cout << "Invalid withdrawal amount or insufficient funds." << endl;
            }
        }
        else
        {
            cout << "Account is frozen. Cannot withdraw." << endl;
        }
    }
};

class SavingsAccount : public BankAccount
{
private:
    double int_rate;

public:
    SavingsAccount(long num, double bal, double rate) : int_rate(rate), BankAccount(num, bal) {}
    double getIntRate()
    {
        return int_rate;
    }
    double getAmountAfterInt()
    {
        return getBalance() * int_rate;
    }
};

class CheckingAccount : public BankAccount
{
private:
    double draft_limit;

public:
    CheckingAccount(long num, double bal, double lim) : draft_limit(lim), BankAccount(num, bal) {}
    double getDraftLimit()
    {
        return draft_limit;
    }
    void withdraw(double amount) override
    {
        if (getBalance() - amount < -draft_limit)
        {
            cout << "Overdraft limit exceeded" << endl;
            return;
        }
        setBalance(getBalance() - amount);
        cout << amount << " withdrawn. New balance: " << getBalance() << endl;
    }
};

class BusinessAccount : public BankAccount
{
private:
    double tax;

public:
    BusinessAccount(long num, double bal, double tax) : tax(tax), BankAccount(num, bal) {}
    double getTax()
    {
        return tax;
    }
    void deposit(double amount) override
    {
        if (amount > 0)
        {
            double tax_amount = tax * amount;
            setBalance(getBalance() + amount - tax_amount);
            cout << amount << " deposited with " << tax_amount << " tax. New balance: " << getBalance() << endl;
        }
        else
        {
            cout << "Error" << endl;
        }
    }
};

class Human
{
private:
    string name;

public:
    Human(string n) : name(n) {}
    string getName()
    {
        return name;
    }
};

class Customer : public Human
{
private:
    int id;

public:
    Customer(string n, int id) : Human(n), id(id) {}
    void ability(BankAccount *acc)
    {
        int choice;
        cout << "Enter 1 to deposit, 2 to withdraw: ";
        cin >> choice;
        double amount;
        switch (choice)
        {
        case 1:
            cout << "Enter deposit amount: ";
            cin >> amount;
            acc->deposit(amount);
            break;
        case 2:
            cout << "Enter withdrawal amount: ";
            cin >> amount;
            acc->withdraw(amount);
            break;
        default:
            cout << "Invalid choice." << endl;
        }
    }
};

class Employee : public Human
{
private:
    int emp_id;
    double salary;

public:
    Employee(string n, int id, double sal) : emp_id(id), salary(sal), Human(n) {}
    int getId()
    {
        return emp_id;
    }
};

class Teller : public Employee
{
public:
    Teller(string n, int id, double sal) : Employee(n, id, sal) {}
    virtual void ability(BankAccount *acc)
    {
        int choice;
        cout << "Enter 1 to deposit, 2 to withdraw, 3 to freeze acc: ";
        cin >> choice;
        double amount;
        switch (choice)
        {
        case 1:
            cout << "Enter deposit amount: ";
            cin >> amount;
            acc->deposit(amount);
            break;
        case 2:
            cout << "Enter withdrawal amount: ";
            cin >> amount;
            acc->withdraw(amount);
            break;
        case 3:
            acc->freeze();
            break;
        default:
            cout << "Invalid choice." << endl;
        }
    }
};

class Manager : public Teller
{
public:
    Manager(string n, int id, double sal) : Teller(n, id, sal) {}
    void ability(BankAccount *acc) override
    {
        int choice;
        cout << "Enter 1 to deposit, 2 to withdraw, 3 to freeze acc, 4 to unfreeze acc: ";
        cin >> choice;
        double amount;
        switch (choice)
        {
        case 1:
            cout << "Enter deposit amount: ";
            cin >> amount;
            acc->deposit(amount);
            break;
        case 2:
            cout << "Enter withdrawal amount: ";
            cin >> amount;
            acc->withdraw(amount);
            break;
        case 3:
            acc->freeze();
            break;
        case 4:
            acc->unfreeze();
            break;
        default:
            cout << "Invalid choice." << endl;
        }
    }
};
// Test Function by GPT
void testFunction(){
	SavingsAccount savings(12345, 1000, 0.01);
    CheckingAccount checking(67890, 500, 200);
    BusinessAccount business(54321, 2000, 0.1);

    Customer customer("John Doe", 1);
    Teller teller("Jane Smith", 2, 30000);
    Manager manager("Alice Johnson", 3, 50000);

    vector<BankAccount *> accounts = {&savings, &checking, &business};

    for (auto acc : accounts)
    {
        cout << "\nOperating on account with balance: " << acc->getBalance() << endl;

        cout << "\nCustomer operations:" << endl;
        customer.ability(acc);

        cout << "\nTeller operations:" << endl;
        teller.ability(acc);

        cout << "\nManager operations:" << endl;
        manager.ability(acc);
    }

}

int main()
{
	testFunction();
    return 0;
}