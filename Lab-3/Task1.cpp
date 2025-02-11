#include <iostream>
using namespace std;

class User{
    public:
        int age;
        string name;
        
    User(int age, string name){
        this->age = age;
        this->name = name;
    }
    void display(){
        cout << "My name is " << name << " and I'm " << age << " years old" << endl;
    }
};


int main(int argc, char* argv[]) {
    User user1(stoi(argv[1]), argv[2]);
    user1.display();
    return 0;
}
