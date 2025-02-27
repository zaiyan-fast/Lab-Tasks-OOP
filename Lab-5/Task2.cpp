#include <iostream>
#include <vector>
using namespace std;

class Car{
    private:
        string name;
        int id;
    public:
    Car(string name, int id) : name(name), id(id){}
    ~Car(){
        cout << name << " Destroyed" << endl;
    }
    
    string getName(){
        return name;
    }
    int getId(){
        return id;
    }
};

class Garage{
private:
    vector <Car*> cars;
public:
    void parkCar(Car* car){
        cars.push_back(car);
    }
    
    void listCars(){
        cout << "--- Cars Parked ---" << endl;
        for(auto &car : cars){
            cout << "Name: " << car->getName() << endl;
            cout << "Id: " << car->getId() << endl;
        }
    }
    
    ~Garage(){
        cout << "Garage Destroyed" << endl;
    }
};

int main() {
    Car car1("Corolla", 12);
    Car car2("Civic", 15);
    Garage g;
    g.parkCar(&car1);
    g.parkCar(&car2);
    g.listCars();
    return 0;
}
