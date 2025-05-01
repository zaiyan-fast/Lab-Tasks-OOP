#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

void addTask() {
    string task;
    cout << "Enter task: ";
    getline(cin >> ws, task);
    ofstream out("todo.txt", ios::app);
    out << task << endl;
    cout << "Task added.\n";
}

void viewTasks(vector<string>& tasks) {
    ifstream in("todo.txt");
    string line;
    tasks.clear();
    int i = 1;
    while (getline(in, line)) {
        tasks.push_back(line);
        cout << i++ << ". " << line << endl;
    }
}

void markDone() {
    vector<string> tasks;
    viewTasks(tasks);
    if (tasks.empty()) return;

    int n;
    cout << "Enter task number to mark as done: ";
    cin >> n;
    if (n < 1 || n > tasks.size()) return;

    ofstream out("todo.txt");
    for (int i = 0; i < tasks.size(); i++) {
        if (i != n - 1) out << tasks[i] << endl;
    }
    cout << "Task removed.\n";
}

int main() {
    while (true) {
        cout << "\n1. Add Task\n2. View Tasks\n3. Mark Done\n4. Exit\nChoose: ";
        int c;
        cin >> c;
        if (c == 1) addTask();
        else if (c == 2) {
            vector<string> t;
            viewTasks(t);
        }
        else if (c == 3) markDone();
        else break;
    }
    return 0;
}
