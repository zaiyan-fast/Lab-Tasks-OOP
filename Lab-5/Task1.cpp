#include <iostream>
using namespace std;

class Engine{
    private:
        bool isRunning;
    public:
        void start(){
            isRunning = true;
            cout << "Engine started" << endl;
        }
        void stop(){
            isRunning = false;
            cout << "Engine stopped" << endl;
        }
        Engine(){
        	cout << "Engine Created" << endl;
        	isRunning = false;
		}
		~Engine(){
			cout << "Engine Destroyed" << endl;
		}
};

class Car{
    private: 
        Engine engine;
    public:
        void carStart(){
            engine.start();
        }
        void carStop(){
            engine.stop();
        }
        Car(){
        	cout << "Car Created" << endl;
		}
		~Car(){
			cout << "Car Destroyed" << endl;
		}
};

int main() {
    Car car1;
    car1.carStart();
    car1.carStop();

    return 0;
}
