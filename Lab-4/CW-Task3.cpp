#include <iostream>
#include <limits.h>
using namespace std;

class DynamicArray{
private:
    int* array;
    int count;
    
public:
    DynamicArray() : count(0){
        array = new int[count];
    }
    DynamicArray(int size) : count(size){
        array = new int[count];
        for(int i = 0; i < count; i++){
            array[i] = 0;
        }
    }
    
    DynamicArray(const DynamicArray &a) : count(a.count){
        array = new int[count];
        for(int i = 0; i < count; i++){
            array[i] = a.array[i];
        }
    }
    
    DynamicArray(DynamicArray &&a) : array(a.array), count(a.count){
        a.array = nullptr;
        a.count = 0;
    }
    
    // Assignment operator by GPT
    DynamicArray& operator=(const DynamicArray& other) {
        if (this == &other) {
            return *this;
        }
        delete[] array;
        count = other.count;
        array = new int[count];
        for (int i = 0; i < count; i++) {
            array[i] = other.array[i];
        }
        return *this;
    }

    DynamicArray& operator=(DynamicArray&& other) noexcept {
        if (this == &other) {
            return *this;
        }
        delete[] array;
        array = other.array;
        count = other.count;
        other.array = nullptr;
        other.count = 0;
        return *this;
    }
    
    ~DynamicArray(){
        delete[] array;
    }
    
    int size(){
        return this->count;
    }
    
    int& at(int index) const{
        if(index < 0 || index >= count){
            // I wrote this but apparently this doesnt work as I'm trying to return an int as opposed to a reference, so I used GPT on this one
            // cout << "Out of Bound" << endl;
            // return  INT_MIN;
            throw out_of_range("Index out of bounds");
        }
        return array[index];
    }
    
    void resize(int new_size){
        int* newArr = new int [new_size];
        for(int i = 0; i < new_size; i++){
            newArr[i] = 0;
        }
        
        int minSize = 0;
        if(count >= new_size)
            minSize = new_size;
        else
            minSize = count;
        for(int i = 0; i < minSize; i++){
            newArr[i] = array[i];
        }
        delete[] array;
        array = newArr;
        count = new_size;
    }
};

// Test Function by GPT
void testFunction(){
    DynamicArray arr(5);
    arr.at(2) = 10;
    cout << "Element at index 2: " << arr.at(2) << endl;

    DynamicArray arr2 = arr; // Copy constructor
    arr2.at(2) = 20;
    cout << "Copied array element at index 2: " << arr2.at(2) << endl;
    
    DynamicArray arr3 = std::move(arr); // Move constructor
    cout << "Moved array size: " << arr3.size() << endl;
}


int main() {
    testFunction();
    return 0;
}