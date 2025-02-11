#include <iostream>
using namespace std;

class Employee{
    private:
    	string first_name;
    	string last_name;
    	double monthly_sal;
    public:
    	Employee(string f_name, string l_name, double sal){
    	    this->first_name = f_name;
    	    this->last_name = l_name;
    	    if(sal > 0) this->monthly_sal = sal;
    	    else this->monthly_sal = 0.0;
    	}
    	
    	void giveraise(float percent){
    	    cout << "Gave " << first_name << " a raise of " << percent << "%" << endl;
    	    percent /= 100;
    	    this->monthly_sal = monthly_sal + monthly_sal * percent;
    	}
    	
    	void display_yearly_sal(){
    	    cout << "Yearly Salary of " << first_name << " " << last_name << " is " << monthly_sal * 12 << endl;
    	}
};
int main(int argc, char* argv[]) {
	Employee emp1(argv[1], argv[2], stoi(argv[3]));
	Employee emp2(argv[4], argv[5], stoi(argv[6]));
	emp1.display_yearly_sal();
	emp2.display_yearly_sal();
	emp1.giveraise(stoi(argv[7]));
	emp2.giveraise(stoi(argv[8]));
	emp1.display_yearly_sal();
	emp2.display_yearly_sal();

    return 0;
}
