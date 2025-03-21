#include <bits/stdc++.h>
using namespace std;

class Person {
protected:
    int empID;

public:
    virtual void getData() {
        cout << "Enter Employee ID: ";
        cin >> empID;
    }

    virtual void displayData() const {
        cout << "Employee ID: " << empID << endl;
    }

    virtual double calcBonus() const = 0;
};

class Admin : public Person {
protected:
    string name;
    double income;

public:
    void getData() override {
        Person::getData();
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Monthly Income: ";
        cin >> income;
    }

    void displayData() const override {
        Person::displayData();
        cout << "Name: " << name << endl;
        cout << "Monthly Income: " << income << endl;
        cout << "Annual Bonus: " << calcBonus() << endl;
    }

    double calcBonus() const override {
        return (income * 12) * (5.0/100);
    }
};

class Accounts : public Person {
protected:
    string name;
    double income;

public:
    void getData() override {
        Person::getData();
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Monthly Income: ";
        cin >> income;
    }

    void displayData() const override {
        Person::displayData();
        cout << "Name: " << name << endl;
        cout << "Monthly Income: " << income << endl;
        cout << "Annual Bonus: " << calcBonus() << endl;
    }

    double calcBonus() const override {
        return (income * 12) * (5.0/100);
    }
};

int main() {
    // Test by GPT
    Admin adminEmployee;
    Accounts accountsEmployee;

    cout << "Enter details for Admin Employee:" << endl;
    adminEmployee.getData();
    
    cout << "\nEnter details for Accounts Employee:" << endl;
    accountsEmployee.getData();

    cout << "\n---- Employee Details ----" << endl;
    adminEmployee.displayData();
    cout << endl;
    accountsEmployee.displayData();

    return 0;
}
