#include <bits/stdc++.h>
using namespace std;

class Student {
protected:
    string name;
    int roll;
public:
    Student(string n, int r) : name(n), roll(r){}

    void displayStudentDetails() const{
        cout << "Student Name: " << name << endl;
        cout << "Roll Number: " << roll << endl;
    }
};

class Marks : public Student {
protected:
    int marks1, marks2, marks3;
public:
    Marks(string n, int r, int m1, int m2, int m3) : Student(n, r), marks1(m1), marks2(m2), marks3(m3) {}

    void displayMarks() const{
        cout << "Marks in Course 1: " << marks1 << endl;
        cout << "Marks in Course 2: " << marks2 << endl;
        cout << "Marks in Course 3: " << marks3 << endl;
    }
};

class Result : public Marks {
public:
    Result(string n, int r, int m1, int m2, int m3) : Marks(n, r, m1, m2, m3) {}

    void displayResult() const{
        int total = marks1 + marks2 + marks3;
        float average = total / 3.0;
        cout << "Total Marks: " << total << endl;
        cout << "Average Marks: " << average << endl;
    }
};

int main() {
    string name;
    int rollNo, marks1, marks2, marks3;

    cout << "Enter Student Name: ";
    cin >> name;
    cout << "Enter Roll Number: ";
    cin >> rollNo;
    cout << "Enter Marks for Course 1: ";
    cin >> marks1;
    cout << "Enter Marks for Course 2: ";
    cin >> marks2;
    cout << "Enter Marks for Course 3: ";
    cin >> marks3;

    Result studentResult(name, rollNo, marks1, marks2, marks3);

    cout << "--- Student Details ---\n";
    studentResult.displayStudentDetails();

    cout << "--- Marks Obtained ---\n";
    studentResult.displayMarks();

    cout << "--- Total and Average Marks ---\n";
    studentResult.displayResult();

    return 0;
}

