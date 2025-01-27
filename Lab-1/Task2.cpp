#include <iostream>
#define N 20
using namespace std;

int main(int argc, char* argv[]) {
    float arr[N];
    
    for(int i = 0; i < N; i++){
        *(arr + i) = atof(*(argv + i + 1));
    }

    float sum = 0;
    
    for(int i = 0; i < N; i++)  
        sum += *(arr + i);
    
    cout << "Sum: " << sum << endl;;
    
    return 0;
}