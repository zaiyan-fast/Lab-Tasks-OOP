#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    const int roll_no;

public:
    Student(int roll) : roll_no(roll) {}

    void display() {
        cout << "Roll Number: " << roll_no << endl;
    }
};

int main(int argc, char* argv[]) {
    int roll = stoi(argv[1]);

    Student student(roll);

    student.display();

    return 0;
}

