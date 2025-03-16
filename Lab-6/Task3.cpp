#include <bits/stdc++.h>
using namespace std;

class Employee {
protected:
    int id;
    string name;
public:
    Employee(int id, string n) : id(id), name(n) {}
    virtual void showDetails() const {
        cout << "ID: " << id << ", Name: " << name << endl;
    }
    virtual ~Employee() {}
};

class IOrderTaker {
public:
    virtual void takeOrder() = 0;
    virtual ~IOrderTaker() {}
};

class IOrderPreparer {
public:
    virtual void prepareOrder() = 0;
    virtual ~IOrderPreparer() {}
};

class IBiller {
public:
    virtual void generateBill() = 0;
    virtual ~IBiller() {}
};

class Waiter : public Employee, public IOrderTaker {
public:
    Waiter(int id, string n) : Employee(id, n) {}
    void takeOrder() override {
        cout << name << " is taking order\n";
    }
};

class Chef : public Employee, public IOrderPreparer {
public:
    Chef(int id, string n) : Employee(id, n) {}
    void prepareOrder() override {
        cout << name << " is preparing the order\n";
    }
};

class Cashier : public Employee, public IBiller {
public:
    Cashier(int id, string n) : Employee(id, n) {}
    void generateBill() override {
        cout << name << " is generating the bill\n";
    }
};

class Manager : public Employee, public IOrderTaker, public IBiller {
public:
    Manager(int id, string n) : Employee(id, n) {}
    void takeOrder() override {
        cout << name << " (Manager) is taking order\n";
    }
    void generateBill() override {
        cout << name << " (Manager) is generating the bill\n";
    }
};

class Menu {
protected:
    vector<string> items;
    vector<double> prices;
public:
    void addItem(string item, double price) {
        items.push_back(item);
        prices.push_back(price);
    }
    virtual double calculateTotal() = 0;
    virtual ~Menu() {}
};

class FoodMenu : public Menu {
public:
    double calculateTotal() override {
        double total = 0;
        for (double price : prices) total += price;
        return total;
    }
};

class BeverageMenu : public Menu {
public:
    double calculateTotal() override {
        double total = 0;
        for (double price : prices) total += price * 1.1;
        return total;
    }
};

// TestFunction by GPT
void testFunction(){
    vector<Employee*> employees;
    vector<IOrderTaker*> orderTakers;
    vector<IBiller*> billers;

    // Creating employees
    Waiter* waiter = new Waiter(1, "Alice");
    Manager* manager = new Manager(4, "Dave");

    // Storing them in respective vectors
    employees.push_back(waiter);
    employees.push_back(manager);
    
    orderTakers.push_back(waiter);
    orderTakers.push_back(manager);
    
    billers.push_back(manager);

    cout << "Demonstrating Polymorphism:\n";
    for (auto taker : orderTakers) {
        taker->takeOrder();
    }
    
    FoodMenu foodMenu;
    foodMenu.addItem("Burger", 5.0);
    foodMenu.addItem("Pizza", 8.0);
    cout << "Total Food Cost: $" << foodMenu.calculateTotal() << "\n";
    
    BeverageMenu beverageMenu;
    beverageMenu.addItem("Coke", 2.0);
    beverageMenu.addItem("Juice", 3.0);
    cout << "Total Beverage Cost: $" << beverageMenu.calculateTotal() << "\n";
    
    // Cleaning up
    for (auto emp : employees) {
        delete emp;
    }
}

int main() {
    testFunction();
    return 0;
}
