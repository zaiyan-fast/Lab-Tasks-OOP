#include <iostream>
#include <any>
#include <exception>
using namespace std;

// Custom Exception for Type Mismatch
class BadTypeException : public exception {
public:
    const char* what() const noexcept override {
        return "Type Mismatch Error!";
    }
};

// Type-Safe Container class using std::any
template <typename T>
class TypeSafeContainer {
private:
    std::any value;
public:
    // Store a value of type T
    template <typename U>
    void store(const U& input) {
        value = input;
    }
    
    // Retrieve a value of type T
    template <typename U>
    U get() const {
        try {
            return std::any_cast<U>(value);
        } catch (const std::bad_any_cast&) {
            cerr << "Attempted to retrieve incorrect type!" << endl;
            throw BadTypeException();
        }
    }
};

int main() {
    try {
        TypeSafeContainer<int> container;
        
        // Store an integer
        container.store(42);
        int number = container.get<int>();
        cout << "Stored integer: " << number << endl;

        // Store a string
        container.store(string("Test String"));
        string text = container.get<string>();
        cout << "Stored string: " << text << endl;

        // Attempt to retrieve wrong type (should throw)
        double wrong = container.get<double>();
        cout << "Stored double: " << wrong << endl;
    }
    catch (const exception& e) {
        cout << "Exception: " << e.what() << endl;
    }
    return 0;
}