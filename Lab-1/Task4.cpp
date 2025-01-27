#include <iostream>
using namespace std;

int main() {
    float weight_kg, weight_lb;
    cout << "Enter the weight in kg: ";
    cin >> weight_kg;
    
    weight_lb = weight_kg * 2.2;
    
    printf("Weight in kg: %.2f \nWeight in lb: %.2f", weight_kg, weight_lb);
    
    return 0;
}