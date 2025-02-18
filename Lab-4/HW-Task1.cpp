#include <iostream>
using namespace std;
#define PI 3.142

class Circle {
private:
    double radius;

public:
    Circle(double r){
        if (r < 0) {
            cout << "Radius cannot be negative" << endl;
        }
        else
            radius = r;
    }

    double getArea() {
        return PI * radius * radius;
    }

    double getPerimeter() const {
        return 2 * PI * radius;
    }
};

int main(int argc, char* argv[]) {
    Circle circle(stof(argv[1]));

    cout << "Area: " << circle.getArea() << endl;
    cout << "Perimeter: " << circle.getPerimeter() << endl;

    return 0;
}