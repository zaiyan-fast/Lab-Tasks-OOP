#include <bits/stdc++.h>
using namespace std;

class Person {
protected:
    int id;
    string name,address, number, email;
public:
    Person(string n, int id, string a, string num, string e)
        : name(n), id(id), address(a), number(num), email(e) {}
    virtual void displayInfo() const {
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Address: " << address << endl;
        cout << "Phone: " << number << endl;
        cout << "Email: " << email << endl;
    }
    virtual void updateInfo(string newAddr, string newPhone, string newEmail) {
        address = newAddr;
        number = newPhone;
        email = newEmail;
    }
    virtual ~Person() {}
};

class Student : public Person {
    vector<string> courses;
    double GPA;
    int enrollmentYear;

public:
    Student(string n, int id, string a, string num, string e, vector<string> c, double gpa, int y)
        : Person(n, id, a, num, e), courses(c), GPA(gpa), enrollmentYear(y) {}

    void displayInfo() const override {
        Person::displayInfo();
        cout << "Enrollment Year: " << enrollmentYear << endl;
        cout << "GPA: " << GPA << endl;
        cout << "Courses Enrolled: ";
        for (const auto& course : courses)
            cout << course << " ";
        cout << endl;
    }
};

class Professor : public Person {
    string department;
    vector<string> coursesTaught;
    double salary;

public:
    Professor(string n, int id, string a, string num, string e, string dept, vector<string> courses, double sal)
        : Person(n, id, a, num, e), department(dept), coursesTaught(courses), salary(sal) {}

    void displayInfo() const override {
        Person::displayInfo();
        cout << "Department: " << department << endl;
        cout << "Courses Taught: ";
        for (auto& course : coursesTaught)
            cout << course << " ";
        cout << endl;
        cout << "Salary: " << salary << endl;
    }
};

class Staff : public Person {
    string department, position;
    double salary;

public:
    Staff(string n, int id, string a, string num, string e, string dept, string pos, double sal)
        : Person(n, id, a, num, e), department(dept), position(pos), salary(sal) {}

    void displayInfo() const override {
        Person::displayInfo();
        cout << "Department: " << department << endl;
        cout << "Position: " << position << endl;
        cout << "Salary: $" << salary << endl;
    }
};

class Course {
    string courseId, courseName, instructor;
    int credits;
    string schedule;
    vector<Student*> enrolledStudents;

public:
    Course(string id, string name, string inst, int cr, string sch)
        : courseId(id), courseName(name), instructor(inst), credits(cr), schedule(sch) {}

    void registerStudent(Student* student) {
        enrolledStudents.push_back(student);
    }

    void displayCourseInfo() const {
        cout << "Course ID: " << courseId << endl;
        cout << "Course Name: " << courseName << endl;
        cout << "Instructor: " << instructor << endl;
        cout << "Credits: " << credits << endl;
        cout << "Schedule: " << schedule << endl;
        cout << "Enrolled Students: ";
        for (auto& student : enrolledStudents)
            student->displayInfo();
    }
};

// Main by GPT
int main() {
    Student s1("Ali", 123 , "123 Street", "1234567890", "ali@email.com", {"CS101", "CS102"}, 3.8, 2023);
    Professor p1("Dr. Khan", 456, "456 Avenue", "0987654321", "khan@email.com", "Computer Science", {"CS101", "CS202"}, 75000);
    Staff st1("Mr. Ahmed", 789, "789 Road", "1122334455", "ahmed@email.com", "Admin", "Manager", 50000);

    Course cs1("CS101", "Intro to Programming", "Dr. Khan", 3, "Mon-Wed 10AM");

    cs1.registerStudent(&s1);

    cout << "--- Student Info ---" << endl;
    s1.displayInfo();

    cout << "--- Professor Info ---" << endl;
    p1.displayInfo();

    cout << "--- Staff Info ---" << endl;
    st1.displayInfo();

    cout << "--- Course Info ---" << endl;
    cs1.displayCourseInfo();

    return 0;
}
