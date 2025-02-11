#include <iostream>
using namespace std;

class Date{
    private:
        int day;
        int month;
        int year;
    public:
        void setDate(int day, int month, int year){
            this->day = day;
            this->month = month;
            this->year = year;
        }
        void displayDate(){
            cout << day << "/" << month << "/" << year << endl;
        }
};

int main(int argc, char* argv[]) {
   Date date;
   date.setDate(stoi(argv[1]), stoi(argv[2]), stoi(argv[3]));
   date.displayDate();
    return 0;
}
