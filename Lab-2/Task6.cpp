#include <iostream>
#include <vector>
using namespace std;

struct Subject{
    string subject_name;
};
struct Student{
    int id;
    Subject subjects[3];
};

int main() {
    vector<Student> students;
    int count = 0;
    int flag = 1;
    while(flag){
        struct Student new_std;
        cout << "Enter student " << count + 1 << " id: ";
        cin >> new_std.id;
         for (int j = 0; j < 3; j++) {
            cout << "Enter subject " << j + 1 << ": ";
            cin >> new_std.subjects[j].subject_name;
        }
        
        students.push_back(new_std);
        count++;
        cout << "Press any num to continue and 0 to exit: ";
        cin >> flag;
    }

    return 0;
}