#include<iostream>
using namespace std;

int main(){
	string str[] = {
	"Movie Name: ",
	"Number of Tickets Sold: ",
	"Gross Amount: ",
	"Percentage of Gross Amount Donated: ",
	"Amount Donated: ",
	"Net Sale: "
	};
	
	string movie_name;
	int adult_tick, child_tick, tot_tick;
	float child_price, adult_price, donation_percent, donation, gross, net;
	
	cout << "Enter movie name: ";
	cin >> movie_name;
	cout << "Enter the price of adult ticket: ";
	cin >> adult_price;
	cout << "Enter the price of child ticket: ";
	cin >> child_price;
	cout << "Enter the number of adult tickets sold: ";
	cin >> adult_tick;
	cout << "Enter the number of child tickets sold: ";
	cin >> child_tick;
	cout << "Enter the percentage of total amount to be donated: ";
	cin >> donation_percent;
	
	tot_tick = adult_tick + child_tick;
	gross = (adult_tick * adult_price) + (child_tick * child_price);
	donation = gross * (donation_percent / 100);
	net = gross - donation;
	
	float arr[] = {0, (float) tot_tick, gross, donation_percent, donation, net};
	
	int max = 0;
	for(int i = 0; i < 6; i++){
	    if(str[i].length() > max)    max = str[i].length();
	}
	
	for(int i = 0; i < 6; i++){
	    cout << str[i];
	    if(str[i].length() < max){
	        for(int j = str[i].length(); j < max; j++){
	            cout << ".";
	        }
	    }
	    if(i == 0)  cout << movie_name;
	    else    cout << arr[i];
	    cout << endl;
	}
	
	return 0;
}