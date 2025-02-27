#include <iostream>
#include <string>
using namespace std;

class Car {
public:
    int hp;
    int seatCap;
    int speakers;

    Car(int h, int seating, int sp)
        : hp(h), seatCap(seating), speakers(sp) {}
        
    // I used GPT on this one as I had no idea about typecasting a const this pointer to a non-const pointer
    void setEngineHorsepower(int horsepower) const {
        const_cast<Car*>(this)->hp = horsepower;
    }

    void setSeatingCapacity(int seating) const {
        const_cast<Car*>(this)->seatCap = seating;
    }

    void setNoOfSpeakers(int speakers) const {
        const_cast<Car*>(this)->speakers = speakers;
    }

    void displayAttributes() const {
        cout << "Engine Horsepower: " << hp << endl;
        cout << "Seating Capacity: " << seatCap << endl;
        cout << "Number of Speakers: " << speakers << endl;
    }
};

int main(int argc, char* argv[]) {
    Car myCar(stoi(argv[1]), stoi(argv[2]), stoi(argv[3]));

    cout << "Initial car attributes:" << endl;
    myCar.displayAttributes();

    myCar.setEngineHorsepower(stoi(argv[4]));
    myCar.setSeatingCapacity(stoi(argv[5]));
    myCar.setNoOfSpeakers(stoi(argv[6]));

    cout << "\nUpdated car attributes:" << endl;
    myCar.displayAttributes();

    return 0;
}

