#include <bits/stdc++.h>
using namespace std;

class Shape {
public:
    virtual float getArea() = 0;
};

class Rectangle : public Shape {
    float w, h;
public:
    Rectangle(float w, float h) : w(w), h(h) {}
    float getArea() override {
        return w * h;
    }
};

class Triangle : public Shape {
    float b, h;
public:
    Triangle(float b, float h) : b(b), h(h) {}
    float getArea() override {
        return 0.5 * b * h;
    }
};

int main() {
    Shape* r = new Rectangle(4, 5);
    Shape* t = new Triangle(3, 6);

    cout << "Area of Rectangle: " << r->getArea() << endl;
    cout << "Area of Triangle: " << t->getArea() << endl;

    delete r;
    delete t;
    return 0;
}
