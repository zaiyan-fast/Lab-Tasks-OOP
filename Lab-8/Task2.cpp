#include <iostream>
using namespace std;
#define PI 3.142

class Shape {
protected:
    string position;
    string color;
public:
    Shape(string pos, string col)
        : position(pos), color(col){}

    virtual void draw() const = 0;
    virtual double calculateArea() const = 0;
    virtual double calculatePerimeter() const = 0;
    virtual void print() const {
        cout << "Position: " << position << endl;
        cout << "Color: " << color << endl;
    }
    virtual ~Shape() {}
};

class Circle : public Shape {
    double radius;
    string center;
public:
    Circle(string p, string col, double r, string c)
        : Shape(p, col), radius(r), center(c) {}

    void draw() const override {
        cout << "Drawing a Circle at " << center << " with radius " << radius << endl;
    }

    double calculateArea() const override {
        return PI * radius * radius;
    }

    double calculatePerimeter() const override {
        return 2 * PI * radius;
    }

    void print() const override {
        Shape::print();
        cout << "Center Position: " << center << endl;
        cout << "Radius: " << radius << endl;
    }
};

class Rectangle : public Shape {
    double width, height;
    string topLeftCorner;

public:
    Rectangle(string p, string c, double w, double h, string l)
        : Shape(p, c), width(w), height(h), topLeftCorner(l) {}

    void draw() const override {
        cout << "Drawing a Rectangle at " << topLeftCorner << " with width " << width << " and height " << height << endl;
    }

    double calculateArea() const override {
        return width * height;
    }

    double calculatePerimeter() const override {
        return 2 * (width + height);
    }

    void print() const override {
        Shape::print();
        cout << "Top Left Corner: " << topLeftCorner << endl;
        cout << "Width: " << width << ", Height: " << height << endl;
    }
};

class Triangle : public Shape {
    double base, height, sideA, sideB, sideC;

public:
    Triangle(string p, string col, double base, double h, double a, double b, double c)
        : Shape(p, col), base(base), height(h), sideA(a), sideB(b), sideC(c) {}

    void draw() const override {
        cout << "Drawing a Triangle with base " << base << " and height " << height << endl;
    }

    double calculateArea() const override {
        return 0.5 * base * height;
    }

    double calculatePerimeter() const override {
        return sideA + sideB + sideC;
    }

    void print() const override {
        Shape::print();
        cout << "Base: " << base << ", Height: " << height << endl;
        cout << "Sides: " << sideA << ", " << sideB << ", " << sideC << endl;
    }
};

class Polygon : public Shape {
    int numSides;
    double *sideLengths;

public:
    Polygon(string pos, string col, int sides, double lengths[])
        : Shape(pos, col), numSides(sides) {
        sideLengths = new double[numSides];
        for (int i = 0; i < numSides; i++)
            sideLengths[i] = lengths[i];
    }

    void draw() const override {
        cout << "Drawing a Polygon with " << numSides << " sides" << endl;
    }

    double calculateArea() const override {
        cout << "Area depends on the specific shape" << endl;
        return 0.0; 
    }

    double calculatePerimeter() const override {
        double perimeter = 0;
        for (int i = 0; i < numSides; i++)
            perimeter += sideLengths[i];
        return perimeter;
    }

    void print() const override {
        Shape::print();
        cout << "Number of Sides: " << numSides << endl;
        cout << "Side Lengths: ";
        for (int i = 0; i < numSides; i++)
            cout << sideLengths[i] << " ";
        cout << endl;
    }

    ~Polygon() {
        delete[] sideLengths;
    }
};

// Main by GPT
int main() {
    Circle c("Center", "Red", 5.0, "(0,0)");
    Rectangle r("Top-Left", "Blue", 10.0, 5.0, "(0,0)");
    Triangle t("Bottom-Left", "Green", 6.0, 4.0, 5.0, 6.0, 7.0);
    
    double polySides[] = {5.0, 7.0, 8.0, 6.0};
    Polygon p("Random", "Yellow", 4, polySides);

    cout << endl << "--- Circle Details ---" << endl;
    c.draw();
    c.print();
    cout << "Area: " << c.calculateArea() << endl;
    cout << "Perimeter: " << c.calculatePerimeter() << endl;

    cout << endl << "--- Rectangle Details ---" << endl;
    r.draw();
    r.print();
    cout << "Area: " << r.calculateArea() << endl;
    cout << "Perimeter: " << r.calculatePerimeter() << endl;

    cout << endl << "--- Triangle Details ---" << endl;
    t.draw();
    t.print();
    cout << "Area: " << t.calculateArea() << endl;
    cout << "Perimeter: " << t.calculatePerimeter() << endl;

    cout << endl << "--- Polygon Details ---" << endl;
    p.draw();
    p.print();
    cout << "Perimeter: " << p.calculatePerimeter() << endl;

    return 0;
}
