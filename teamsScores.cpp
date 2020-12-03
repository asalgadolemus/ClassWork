/*
Name: 			Antonio Salgado
Description:    This program will get the scores and names
				from a file and will add thme into arrays
				it will print them and show the names of the teams
				with their scores, total, and the team with the highest
				scoring team in the quarter the user picks.
Course: 		CS255-Computer Science II
Date: 			August 30, 2018
*/
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;
//Constants
const int MAX = 10;
//Function Declarations
void menu();
void FillArrays(string tm[], int& size, int Q1[], int Q2[], int Q3[], int Q4[]);
void PrintArrays(string tm[], int size, int Q1[], int Q2[], int Q3[], int Q4[]);
string GetMax(string tm[], int size, int Q1[], int Q2[], int Q3[], int Q4[], int choice);
//Driver
int main() {

	string tm[MAX],team;
	int Q1[MAX], Q2[MAX], Q3[MAX], Q4[MAX];
	int size=0,choice=0,teamChoice = 0;
	
		do {
			menu();
			cin >> choice;
			cout << string(35, '*') << endl;
			cout << endl;
			switch (choice) {
					case 0:
						cout << "Thank You!" << endl;
						break;
					case 1: 
						FillArrays(tm,size, Q1, Q2, Q3, Q4);
						break;
					case 2:
			
							cout << setw(13) << left << "Teams " << "1st " << "2nd " << "3rd " << "4th " << " Total" << endl;
							cout << string(35, '*') << endl;
							PrintArrays(tm,size, Q1, Q2, Q3, Q4);
			
						break;
					case 3:
			
						
						do {
							cout << "Enter quarter for highest scoring team: ";
							cin >> teamChoice;
						} while (teamChoice <= 0 || teamChoice >= 5);
						team=GetMax(tm,size, Q1, Q2, Q3, Q4, teamChoice);
						cout<<"Highest scoring team in quarter " <<teamChoice<<": "<<team<<endl<<endl;
						break;
					
					
					default:
						cout << "Invalid Choice!" << endl << endl;
			}
		} while (choice != 0);

	

	return 0;

}
//Function Definitions 

//***********************************************
// Name:		FillArrays
// Purpose:		Will fill the arrays from the file 
//				containing the teams and their scores.
// Incoming:	array of teams (string), size (int), Quarter_1,2,3,4 (int)
// Outgoing:	array of teams (string), size (int), Quarter_1,2,3,4 (int)
//Return:		None
//***********************************************
void FillArrays(string tm[],int& size, int Q1[], int Q2[], int Q3[], int Q4[]) {
	//Gets filename
	string filename;
	cout<<"Enter filename: ";
	cin>>filename;
	//opens file and checks for errors
	ifstream infile;
	infile.open(filename.c_str());
	if(infile.fail()){
		cout<<"Error: File not found!";
		exit(1);
	}
	//fills the array
	int i = 0;
	while(infile >> tm[i] >> Q1[i] >> Q2[i] >> Q3[i] >> Q4[i]){
		i++;
	}
	size=i;
	//closes file
	infile.close();
}
//***********************************************
// Name:		PrintArrays
// Purpose:		Will print each team, with their scores
//				from each quarter and a column that totals the score.
// Incoming:	array of teams (string), size (int), Quarter_1,2,3,4 (int)
// Outgoing:	None
//Return:		None
//***********************************************
void PrintArrays(string tm[],int size, int Q1[], int Q2[], int Q3[], int Q4[]) {
	int sum = 0;
	for (int i = 0; i<size; i++) {
		//sums up each teams total
		sum = Q1[i] + Q2[i] + Q3[i] + Q4[i];
		//prints teams scores and total
		cout << setw(12) << left << tm[i] << setw(4) << right << Q1[i] << setw(4) <<
			right << Q2[i] << setw(4) << right << Q3[i] << setw(4) << right <<
			Q4[i] << setw(6) << right << sum << endl;
	}
}
//***********************************************
// Name:		GetMax
// Purpose:		Will return the name of the team 
//				with the highest score from the quarter
//				pick by the user.
// Incoming:	array of tm (string),size (int), Q1,2,3,4 (int),choice (int)
// Outgoing:	tm (string)
//Return:		None
//***********************************************
string GetMax(string tm[],int size, int Q1[], int Q2[], int Q3[], int Q4[], int choice) {
	int max = 0, count = 0;
	//returns max scoring team
	switch (choice) {
		case 1:
			max = Q1[0];
			for (int i = 1; i<size; i++) {
	
				if (Q1[i]>max) {
					max = Q1[i];
					count = i;
				}
			}
			return tm[count];
			break;
		case 2:
			max = Q2[0];
			for (int i = 1; i<size; i++) {
	
				if (Q2[i]>max) {
					max = Q2[i];
					count = i;
				}
			}
			return tm[count];
			break;
		case 3:
			max = Q3[0];
			for (int i = 1; i<size; i++) {
	
				if (Q3[i]>max) {
					max = Q3[i];
					count = i;
				}
			}
			return tm[count];
			break;
		case 4:
			max = Q4[0];
			for (int i = 1; i<size; i++) {
	
				if (Q4[i]>max) {
					max = Q4[i];
					count = i;
				}
			}
			return tm[count];
			break;
	}
}
void menu(){
	cout << string(35, '*') << endl;
	cout << "0 - Quit" << endl;
	cout << "1 - Fill Array" << endl;
	cout << "2 - Print Array" << endl;
	cout << "3 - Get Max Team" << endl;
	cout << "Enter choice (0 thru 3): ";	
}


