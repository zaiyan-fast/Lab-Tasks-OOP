#include <iostream>
using namespace std;

int main(int argc, char* argv[]){
	cout << "Name: " << argv[1] << " " << argv[2] << endl;
	float scores[5] = {0};
	
	for(int i = 3; i < 8; i++)
		scores[i-3] = stof(argv[i]);
		
	float sum = 0;
	for(int i = 0; i < 5; i++)
		sum += scores[i];
	
	float avg = sum/5;
	
	cout << "Test Scores: ";
	for(int i = 0; i < 5; i++)	cout << scores[i] << " ";
	cout << endl;
	
	cout << "Avg Test Score: " << avg << endl;
	return 0;
}