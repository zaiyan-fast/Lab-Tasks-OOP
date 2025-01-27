#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
    int id = atoi(argv[1]);
    string name = argv[2];
    float units = atof(argv[3]);
    float charge = 0, amount = 0, surcharge = 0;
    
    if(units < 0){
        cout << "Invalid number of units" << endl;
        return 0;
    }
    if(units < 200){
        charge = 16.20;
    }else if(units >= 200 && units < 300){
        charge = 20.10;
    }else if(units >= 300 && units < 500){
        charge = 27.10;
    }else{
        charge = 35.90;
    }
    
    amount = units * charge;
    
    cout << "Customer ID: " << id << endl;
    cout << "Customer Name: " << name << endl;
    cout << "Units Consumed: " << units << endl;
    cout << "Amount Charges @Rs." << charge << " per unit: " << amount << endl;
    if(amount > 18000){
        surcharge = amount * 0.15;
    }
    amount += surcharge;
    cout << "Surcharge Amount: " << surcharge << endl;
    cout << "Net Amount paid by the customer: " << amount << endl;
    
    return 0;
}