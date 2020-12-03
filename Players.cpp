/*
Programmed By: Antonio Salgado 
CS 255-01
Assignment #5
Due: Tuesday, 18th @ 12:30
Description: Creates a simple Players container that test all constructors.
		Also allows the user to manually input some data and returns 
		values based on the inputs calculation.
*/
#include <iostream>
#include <string>
using namespace std;

//class declaration 
class Players{
	
	//data members/objects:
	string first, last; 
	int age;
	double weight;
	string position;

	//operations upon the data:
	public:
		Players();
		Players(string f);
		Players(string f, string l);
		Players(string f, string l, int a);
		Players(string f, string l, int a, double w);
		Players(string f, string l, int a, double w, string p);
		void const Print();
		void Input();
		string const GetName();
		void AgeReq();
		double Fun(double weight);
};
//constructors/implementation/defintion:
Players::Players(){
	first= "Antonio";
	last = "Salgado";
	age= 20;
	weight = 190.8;
	position="Guard";
}
Players::Players(string f){
			
	first = f;
	last ="Cosby";
	age = 20;
	weight =190.8;
	position = "Guard";
}
Players::Players(string f, string l){
			
	first = f;
	last= l;
	age = 20;
	weight =190.8;
	position = "Guard";
}
Players::Players(string f, string l, int a){
	first=f;
	last=l;
	age=a;
	weight=190.8;
	position = "Guard";
}
Players::Players(string f, string l, int a, double w){
	
	first=f;
	last =l;
	age=a;
	weight = w;
	position = "Guard";
}
Players::Players(string f, string l, int a, double w, string p){
	
	first=f;
	last =l;
	age=a;
	weight = w;
	position=p;
}	
/*
Name:Print
Description: outputs the values of the class once hard coded or inputted
Incoming: class info
Returns: n/a
*/ 
void const Players::Print(){
	
     cout << first << " " << last << endl;
	 cout << age << endl;
	 cout << weight << endl;
	 cout << position << endl;
 }
 /*
 Name: Input();
 Descriptiion: takes in multiple inputs from the user.
 Incoming: class info
 Returns: n/a
 */
 void Players::Input(){

 	cout << "Enter Your Name(first last): ";
 	cin >> first  >> last;
	cout << "Enter Your Age: ";
 	cin >> age;
 	cout << "Enter Your Wieght: ";
 	cin >> weight;
 	cout << "Enter Position (guard, foward, center): ";
 	cin >> position;
 	
 }
  /*
 Name: GetName();
 Descriptiion: Accessor function that finds the full name 
 incoming: the class infp 
 Returns: first name and last name (and a char inbetween the both to sepaarate the 2 
 */
 string const Players::GetName(){
 	char space=' ';
 	return first+space+last;
 }
   /*
 Name: AgeReq();
 Descriptiion: mutator function that check if a person meets the age requirement for 
 the team.. If not it tells them how much younger or older the need to be. and sets
 your age to the max age that meets the requirements
 incoming: the class info
 Returns: n/a 
 */
 void Players::AgeReq(){
 	
 	if (age >=18 && age <= 35 )
 		cout << "You do meet requirement the age requirements for team." << endl;

 	if (age < 18 ){
 		cout << "Your age does not meet requirements for team." << endl;
 		cout << "You need to be " << 35 - age << " years older" << endl;
 			age = 35;
	 }
	 
 	if (age > 35){
 			cout << "Your age does not meet requirements for team." << endl;
 			cout << "You need to be " << (35 - age)*-1<< " years younger" << endl;		//multiplies the number by a (-) to get the number positive
 				age = 35;
	 }
	 

 }
   /*
 Name: Fun();
 Descriptiion: this functions reads in a value in the parameters and sets
 the fuctions parameters to that value and returns it 
 incoming: the class info
 Returns: a double of the valur of weight inputted into the parameters
 */
 double Players::Fun(double weight){
 	return weight;
 }
 //driver 
int main(){
	//below is a testers:
	cout << "TESTERS: " << endl;
	Players p;
	Players p1("Jane");
	Players p2("Jane", "Doe");
	Players p3("Jane", " Doe", 20);
	Players p4("jane", " Doe", 20, 209.10);
	Players p5("Jane", " Doe", 20, 209.10, "Foward");
	Players p7;
	
	p.Print(); cout << endl;
	cout << "________________________________" << endl;
	p1.Print(); cout << endl;
	cout << "________________________________" << endl;
	p2.Print(); cout << endl;
	cout << "________________________________" << endl;
	p3.Print(); cout << endl;
	cout << "________________________________" << endl;
	p4.Print(); cout << endl;
	cout << "________________________________" << endl;
	p5.Print(); cout << endl;	

	cout << "**************************************************" << endl;
	cout << "Input Info: " << endl;
	p7.Input(); 
	
	cout << "**************************************************" << endl;
	p7.Print(); cout << endl;
	cout << "The name of the inputted player is: " << endl;
	cout << p7.GetName() << endl;
	
	cout << "**************************************************" << endl;
	cout << "Checks if age of inputted player meets team age requirements: " << endl;
	p7.AgeReq(); cout << endl;	
	
	cout << "**************************************************" << endl;
	cout << "Function using an object as a parameter: " << endl;
	cout << p1.Fun(2000.2) << endl;
	
 	cout << "**************************************************" << endl;
	cout << "Checking Objects: " << endl;
	p1.Print(); cout << endl;	//used this to see if it would change the weight value for Players p1.
	return 0;
}
