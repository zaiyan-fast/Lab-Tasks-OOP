#include <iostream>
#include <string>
using namespace std;
#define N 5

int sum_arr(int *arr, int n){
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += *(arr + i);
    }
    return sum;
}

int main(int argc, char* argv[]) {
    int arr[argc - 1];
    for(int i = 0; i < argc - 1; i++) 
        *(arr + i) = stoi(*(argv + i + 1));
    
    int sum = sum_arr(arr, argc - 1);
    cout << sum;
    
    return 0;
}


