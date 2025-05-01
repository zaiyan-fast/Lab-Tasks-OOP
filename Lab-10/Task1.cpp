#include <iostream>
#include <fstream>
using namespace std;

int main() {
	ofstream of("task1.txt");
    string str;
    getline(cin, str);
    cout << "Original Text: " << str << endl;
    for(int i=0;i<str.length(); i++){
        str[i]+=i+1;
    }
    of << str;
	of.close();
	
	ifstream file("task1.txt");
	char buffer;
	int j=1;
	cout << "Reading from File: ";
	while(file.get(buffer)){
		buffer -= j++;
		cout << buffer;
	}
    return 0;
}