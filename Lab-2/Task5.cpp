#include <iostream>
using namespace std;

struct Student{
    int id;
    string name;
};

void bubbleSortID(Student* students, int n){
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(students[j].id > students[j+1].id){
                Student temp = students[j];
                students[j] = students[j+1];
                students[j+1] = temp;
            }
        }
    }
}

void bubbleSortName(Student* students, int n){
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(students[j].name > students[j+1].name){
                Student temp = students[j];
                students[j] = students[j+1];
                students[j+1] = temp;
            }
        }
    }
}

void printarr(Student* students, int n){
    for (int i = 0; i < n; i++) {
        cout << "Student " << i + 1 << " ID: " << students[i].id << endl;
        cout << "Student " << i + 1 << " Name: " << students[i].name << endl;
    }
    cout << endl;
}


int main() {
    int n;
    cout << "Enter the number of structures: ";
    cin >> n;
    
    Student* students = new Student[n];
    
    for(int i = 0; i < n; i++){
        printf("Enter id of student %d: ", i + 1);
        cin >> students[i].id;
        printf("Enter name of student %d: ", i + 1);
        cin >> students[i].name;
    }
    
    cout << "Sorting by id: \n";
    bubbleSortID(students, n);
    printarr(students, n);
    
    cout << "Sorting by name: \n";
    bubbleSortName(students, n);
    printarr(students, n);
    
    delete[] students;
    return 0;
}