#include <bits/stdc++.h>
using namespace std;

class Person {
public:
    virtual void getdata()=0;
    virtual void display()=0;
    virtual void bonus()=0;
};

class Admin : virtual public Person {
protected:
    float salary;
public:
    void getdata() override {
        cout << "Enter admin salary: ";
        cin >> salary;
    }
    void display() override {
        cout << "Admin Salary: " << salary << endl;
    }
    void bonus() override {
        cout << "Admin Bonus: " << 0.1 * salary << endl;
    }
};

class Account : virtual public Person {
protected:
    float balance;
public:
    void getdata() override {
        cout << "Enter account balance: ";
        cin >> balance;
    }
    void display() override {
        cout << "Account Balance: " << balance << endl;
    }
    void bonus() override {
        cout << "Account Bonus: " << 0.05 * balance << endl;
    }
};

class Master : public Admin, public Account {
public:
    void getdata() override {
        Admin::getdata();
        Account::getdata();
    }
    void display() override {
        Admin::display();
        Account::display();
    }
    void bonus() override {
        Admin::bonus();
        Account::bonus();
        cout << "Master Total Bonus: " << (0.1 * salary + 0.05 * balance) << endl;
    }
};

int main() {
    Person* p;
    Master m;
    p = &m;
    p->getdata();
    p->display();
    p->bonus();
    return 0;
}
