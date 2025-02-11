#include <iostream>
using namespace std;

class Glass{
    public:
        int LiquidLevel;
        
        Glass(){
            this->LiquidLevel = 200;
        }
        
        void Drink(int milliliters){
            this->LiquidLevel -= milliliters;
            if(LiquidLevel < 100){
                Refill();
            }
            cout << "Drink Level: " << LiquidLevel << endl;
        }
        
        void Refill(){
            this->LiquidLevel = 200;
        }
};

int main(int argc, char* argv[]) {
   Glass juice;
   for(int i = 1; i < argc; i++){
       if(stoi(argv[i]) == 0) return 0;
       else{
           juice.Drink(stoi(argv[i]));
       }
   }
   
   int ml;
   do{
   		cout << "Enter liquid level you want to drink (0 to terminate): ";
   		cin >> ml;
   		juice.Drink(ml);
   }while(ml != 0);
   cout << "Program Terminated!" << endl;
    return 0;
}
