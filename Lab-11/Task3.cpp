#include <stdexcept>
#include <cstddef>
#include <iostream>

using namespace std;

// Custom exception for out-of-bounds access
class ArrayIndexOutOfBounds : public std::out_of_range {
public:
    ArrayIndexOutOfBounds(const std::string& message) : std::out_of_range(message) {}
};

template <typename T>
class SafeArray {
private:
    T* data;
    size_t size;

public:
    // Constructor
    SafeArray(size_t size) : size(size) {
        data = new T[size];
    }

    // Destructor
    ~SafeArray() {
        delete[] data;
    }

    // Copy constructor
    SafeArray(const SafeArray& other) : size(other.size) {
        data = new T[size];
        for (size_t i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
    }

    // Copy assignment operator
    SafeArray& operator=(const SafeArray& other) {
        if (this != &other) {
            delete[] data;
            size = other.size;
            data = new T[size];
            for (size_t i = 0; i < size; ++i) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }

    // Move constructor
    SafeArray(SafeArray&& other) noexcept : data(other.data), size(other.size) {
        other.data = nullptr;
        other.size = 0;
    }

    // Move assignment operator
    SafeArray& operator=(SafeArray&& other) noexcept {
        if (this != &other) {
            delete[] data;
            data = other.data;
            size = other.size;
            other.data = nullptr;
            other.size = 0;
        }
        return *this;
    }

    // Element access with bounds checking
    T& operator[](ptrdiff_t index) {
        if (index < 0 || static_cast<size_t>(index) >= size) {
            throw ArrayIndexOutOfBounds("Array index out of bounds");
        }
        return data[index];
    }

    const T& operator[](ptrdiff_t index) const {
        if (index < 0 || static_cast<size_t>(index) >= size) {
            throw ArrayIndexOutOfBounds("Array index out of bounds");
        }
        return data[index];
    }

    // Get size
    size_t getSize() const {
        return size;
    }
};

int main() {
    try {
        // Create a SafeArray of integers with size 5
        SafeArray<int> arr(5);

        // Initialize some values
        for (size_t i = 0; i < arr.getSize(); ++i) {
            arr[i] = static_cast<int>(i * 10);
        }

        // Test valid access
        cout << "Valid access tests:" << endl;
        for (size_t i = 0; i < arr.getSize(); ++i) {
            cout << "arr[" << i << "] = " << arr[i] << endl;
        }

        // Test invalid access (negative index)
        cout << "\nTesting negative index access:" << endl;
        cout << arr[-1] << endl; // Should throw exception
    }
    catch (const ArrayIndexOutOfBounds& e) {
        cout << "Caught expected exception: " << e.what() << endl;
    }

    try {
        // Create another SafeArray
        SafeArray<double> arr2(3);

        // Test invalid access (index >= size)
        cout << "\nTesting out-of-bounds index access:" << endl;
        cout << arr2[3] << endl; // Should throw exception
    }
    catch (const ArrayIndexOutOfBounds& e) {
        cout << "Caught expected exception: " << e.what() << endl;
    }

    return 0;
}