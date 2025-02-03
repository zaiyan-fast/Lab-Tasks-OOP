#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main(int argc, char* argv[]){
    int capacity = 5;
    int size = 0;
    int* arr = new int[capacity];
    
    for(int i = 0; i < argc - 1; i++){
        if(capacity == size){
            capacity *= 2;
            int* newArr = new int[capacity];
            memcpy(newArr, arr, size * sizeof(int));
            delete[] arr;
            arr = newArr;
        }
        arr[size] = stoi(*(argv + i + 1));
        size++;
    }
    
    int* newArr = new int[size];
    memcpy(newArr, arr, size * sizeof(int));
    delete[] arr;
    arr = newArr;
    
    for(int i = 0; i < size; i++)   
		cout << arr[i] << " ";
	    
    return 0;
}


