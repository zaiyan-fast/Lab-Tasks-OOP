#include <iostream>
using namespace std;

struct Employee{
    int emp_id;
    string emp_name;
    int salary;
};
struct Organization{
    string org_name;
    string org_num;
    struct Employee emp;
};


int main() {
    Organization org;
    
    org.org_name = "NU-Fast";
    org.org_num = "NUFAST123ABC";
    org.emp.emp_id = 127;
    org.emp.emp_name = "Linus Sebastian";
    org.emp.salary = 400000;
    
    cout << "The size of structure org: " << sizeof(org) << endl;
    cout << "Organization Name: " << org.org_name << endl;
    cout << "Organization Number: " << org.org_num << endl;
    cout << "Employee ID: " << org.emp.emp_id << endl;
    cout << "Employee Name: " << org.emp.emp_name << endl;
    cout << "Employee Salary: " << org.emp.salary << endl;

    return 0;
}