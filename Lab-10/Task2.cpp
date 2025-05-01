#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

struct Employee {
    int id;
    string name;
    string designation;
    int years;

    string to_string() const {
        return std::to_string(id) + " " + name + " " + designation + " " + std::to_string(years);
    }
};

int main() {
    ofstream out("task2.txt");
    out << "1 John Developer 1\n";
    out << "2 Alice Manager 3\n";
    out << "3 Bob Manager 1\n";
    out << "4 Charlie Tester 4\n";
    out << "5 Dave Manager 2\n";
    out.close();

    ifstream in("task2.txt");
    vector<Employee> all;
    Employee emp;
    while (in >> emp.id >> emp.name >> emp.designation >> emp.years) {
        all.push_back(emp);
    }
    in.close();

    vector<Employee> filtered;
    for (auto emp : all) {
        if (emp.designation == "Manager" && emp.years >= 2) {
            filtered.push_back(emp);
        }
    }

    cout << "Query A - Managers with >=2 years:\n";
    for (auto emp : filtered) {
        cout << emp.to_string() << endl;
    }

    out.open("task2.txt");
    for (const auto& emp : filtered) {
        out << emp.to_string() << endl;
    }
    out.close();

    for (auto& emp : filtered) {
        emp.id += 10;
        emp.years += 1;
    }

    cout << "\nQuery C - Modified Data:\n";
    for (auto emp : filtered) {
        cout << emp.to_string() << endl;
    }

    out.open("task2.txt");
    for (const auto& emp : filtered) {
        out << emp.to_string() << endl;
    }
    out.close();

    return 0;
}
