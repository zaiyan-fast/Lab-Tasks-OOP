#include <iostream>
using namespace std;

class Shape {
private:
    double length, width;

public:
    Shape(double l, double w) : length(l), width(w) {}

    double getArea() const{
        return length * width;
    }

    double operator+(const Shape& s) const{
        return this->getArea() + s.getArea();
    }

    void display() const {
        cout << "Shape with Length: " << length << " and Width: " << width << " has Area: " << getArea() << endl;
    }
};

int main() {
    Shape shape1(4, 5);
    Shape shape2(3, 6);

    shape1.display();
    shape2.display();

    double totalArea = shape1 + shape2;
    cout << "Total Area: " << totalArea << endl;

    return 0;
}
