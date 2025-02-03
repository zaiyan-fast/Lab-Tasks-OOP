#include <iostream>
#include <string>
using namespace std;

void* add_op(void* arr, int x, int n){
    int* arr2 = (int*) arr;
    for(int i = 0; i < n; i++){
        arr2[i] += x;
    }
    return arr;
}
int main(int argc, char* argv[]){
    int arr[argc - 2];
    
    for(int i = 0; i < argc - 2; i++){
        *(arr + i) = stoi(*(argv + i + 2));
    }
    
    int x = stoi(argv[1]);
    
    int* arr2 = (int*) add_op(arr, x, argc - 2);
    
    for(int i = 0; i < argc - 2; i++){
        cout << arr2[i] << " ";
    }
    return 0;
}


