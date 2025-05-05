#include <iostream>
using namespace std;

template <typename T>
class Base {
protected:
    T value1;
    T value2;

public:
    Base(T v1, T v2) : value1(v1), value2(v2) {}

    T getProduct() const {
        return value1 * value2;
    }

    void printProduct() const {
        cout << "Base class product (value1 * value2): " << getProduct() << endl;
    }
};

template <typename T>
class Derived : public Base<T> {
private:
    T value3;
    T value4;

public:
    Derived(T v1, T v2, T v3, T v4) : Base<T>(v1, v2), value3(v3), value4(v4) {}

    T getDerivedProduct() const {
        return value3 * value4;
    }

    void printDerivedProduct() const {
        cout << "Derived class product (value3 * value4): " << getDerivedProduct() << endl;
    }

    // Override base class method to include both products
    void printProduct() const {
        Base<T>::printProduct();
        cout << "Derived class product (value3 * value4): " << getDerivedProduct() << endl;
    }
};

int main() {
    // Test with integers
    cout << "Testing with integers:" << endl;
    Derived<int> intDerived(2, 3, 4, 5);
    intDerived.printProduct();
    cout << endl;

    // Test with doubles
    cout << "Testing with doubles:" << endl;
    Derived<double> doubleDerived(2.5, 3.5, 4.5, 5.5);
    doubleDerived.printProduct();

    return 0;
}