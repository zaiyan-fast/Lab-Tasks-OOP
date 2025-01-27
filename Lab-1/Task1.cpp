#include <iostream>
#include <climits>
#define N 20
using namespace std;

int main(int argc, char* argv[]) {
    float arr[N];
    for(int i = 0; i < N; i++){
        *(arr + i) = atof(*(argv + i + 1));
    }
    
    float highest = INT_MIN;
    float s_highest = INT_MIN;
    
    for(int i = 0; i < N; i++){
        if(highest < *(arr + i))    
            highest = *(arr + i);
    }
    
    for(int i = 0; i < N; i++){
        if(s_highest < *(arr + i) && *(arr + i) != highest) 
            s_highest = *(arr + i);
    }
    
    if(s_highest == INT_MIN) 
        cout << "Second Highest Not Found" << endl;
    else
        cout << "Sec Highest: " << s_highest << endl;
    
    return 0;
}