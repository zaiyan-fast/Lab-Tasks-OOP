#include <bits/stdc++.h>
using namespace std;

class Car {
protected:
    string model;
    float price;
public:
    virtual void setPrice(float p) = 0;
    string getModel() { 
        return model; 
    }
    float getPrice() {
        return price; 
    }
    void setModel(string m) { 
        model = m;
    }
};

class Color : public Car {
    string color;
public:
    void setColor(string c) {color = c; }
    string getColor() {return color;}
    void setPrice(float p) override {
        price = p + 1000;
        
    }
};

class Company : public Car {
    string company;
public:
    void setCompany(string c) {
        company = c;
    }
    string getCompany() {
        return company; 
    }
    void setPrice(float p) override {
        price = p + 2000; }
};

int main() {
    Color c;
    c.setModel("X");
    c.setColor("Red");
    c.setPrice(30000);

    Company co;
    co.setModel("Y");
    co.setCompany("Tesla");
    co.setPrice(35000);

    cout << "Color Car - Model: " << c.getModel() << ", Color: " << c.getColor() << ", Price: " << c.getPrice() << endl;
    cout << "Company Car - Model: " << co.getModel() << ", Company: " << co.getCompany() << ", Price: " << co.getPrice() << endl;

    return 0;
}
