#include <bits/stdc++.h>
using namespace std;

class Vehicles {
protected:
    double price;
public:
    Vehicles(double p) : price(p) {}

    virtual void displayDetails() const {
        cout << "Price: $" << price << "\n";
    }

    virtual ~Vehicles() {}
};

class Car : public Vehicles {
protected:
    int seating;
    int doors;
    string fuel;
public:
    Car(double p, int s, int d, string f) 
        : Vehicles(p), seating(s), doors(d), fuel(f) {}

    void displayDetails() const override {
        Vehicles::displayDetails();
        cout << "Seating Capacity: " << seating 
             << "\nNumber of Doors: " << doors
             << "\nFuel Type: " << fuel << "\n";
    }
};

class Motorcycle : public Vehicles {
protected:
    int cylinders;
    int gears;
    int wheels;
public:
    Motorcycle(double p, int c, int g, int w) 
        : Vehicles(p), cylinders(c), gears(g), wheels(w) {}

    void displayDetails() const override {
        Vehicles::displayDetails();
        cout << "Number of Cylinders: " << cylinders 
             << "\nNumber of Gears: " << gears 
             << "\nNumber of Wheels: " << wheels << "\n";
    }
};

class Audi : public Car {
private:
    string model;
public:
    Audi(double p, int s, int d, string f, string m) 
        : Car(p, s, d, f), model(m) {}

    void displayDetails() const override {
        Car::displayDetails();
        cout << "Model Type: " << model << "\n\n";
    }
};

class Yamaha : public Motorcycle {
private:
    string makeType;
public:
    Yamaha(double p, int c, int g, int w, string m) 
        : Motorcycle(p, c, g, w), makeType(m) {}

    void displayDetails() const override {
        Motorcycle::displayDetails();
        cout << "Make Type: " << makeType << "\n\n";
    }
};

int main() {
    Audi myAudi(50000, 5, 4, "Petrol", "A4");
    cout << "Audi Car Details:\n";
    myAudi.displayDetails();

    Yamaha myYamaha(12000, 2, 6, 2, "R1");
    cout << "Yamaha Motorcycle Details:\n";
    myYamaha.displayDetails();

    return 0;
}
