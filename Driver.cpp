#include "TTT.h"
#include <fstream>
#include <string>
/*
Name: 			Antonio Salgado
Description:    This program will allow the two users 
				play tic-tac-toe and allow them to pick 
				rounds.
				
Course: 		CS255-Computer Science II
Date: 			November 01, 2018
*/
void names(int gen[2],string& first,string& second);
bool choice(int number,int player);
void showOptions();
void showTable();
void results(short result, int& x,int& o, int& cat,string first,string second);
int main(){
	TTT table;
	ofstream Outfile;
	Outfile.open("results.txt");
	int gen[2],number,num,player=gen[1],cat=0,count=0,x=0,o=0,games=0,totalGames=0,choice=0;
	string first, second;	
	bool decision;
	short result;
	names(gen,first,second);
	showOptions();
	cin>>choice;
	switch(choice){//checks for rounds of tic-tac-toe
		
		case 1: 
				games=1;
		break;
		
		case 2: 
				games=3;
		break;
		
		case 3: 
				cout<<"How many rounds would you like?";
				cin>>games;
		break;
		
	}
	showTable();

	do{// stops until rounds has been reach
		do{// checks for winners
			do{ // checks for error in spots already taken
			
		
				cin>>number;
				if(count%2==0)//switches player each turn
					player=gen[1];
				else
					player=gen[2];
	
				switch(number){	//assigns spots
					case 1: 
						decision=table.MakeMove(player,0,0);
						break;	
					case 2: 
						decision=table.MakeMove(player,0,1);
						break;
					case 3: 
						decision=table.MakeMove(player,0,2);
						break;
					case 4: 
						decision=table.MakeMove(player,1,0);
						break;
					case 5: 
						decision=table.MakeMove(player,1,1);
						break;
					case 6: 
						decision=table.MakeMove(player,1,2);
						break;
					case 7: 
						decision=table.MakeMove(player,2,0);
						break;
					case 8: 
						decision=table.MakeMove(player,2,1);
						break;
					case 9: 
						decision=table.MakeMove(player,2,2);
						break;
							
						
					}
					
					if(decision==false)
						cout<<"Error! Spot has been already taken!"<<endl;
						
					
					}while(decision==false);
				count++;
				result = table.CheckBoard();
				cout<<string(5,'*')<<endl;
				table.PrintBoard();
				if(count==9)
					break;
		}while(result == 0);
	
		results(result,x,o,cat,first,second);
		totalGames++;
		table.ClearBoard();
		if(!(games==totalGames))
			showTable();
		count=0;
	}while(games <= 0 || games > totalGames);
	Outfile.close();
	
	return 0;
	
}
void results(short result, int& x,int& o, int& cat,string first,string second){
	ofstream Outfile;
	Outfile.open("results.txt");
	if(result == 1){ // checks if X won
		cout << first<<" won!" << endl;
		x++;
	}
			
	else if (result == -1){// checks if O won
		cout <<second<<" won!" << endl;
		o++;
	}
			
	else {//checks if cat or not win
		cout << "Cat won!" << endl;
		cat++;
	}
		
	cout<<"X O Cat"<<endl;
	cout<<x<<" "<<o<<" "<<cat<<endl;
	Outfile<<"X O Cat"<<endl;
	Outfile<<x<<" "<<o<<" "<<cat<<endl;	
	Outfile.close();
}
void names(int gen[2],string& first,string& second){
	cout<<"Enter 1st players name: ";
	cin>>first;
	cout<<"Enter 2nd players name: ";
	cin>>second;
	gen[1]=20;
	gen[2]=21;
}

void showTable(){
	cout<<"Pick a number from the table below."<<endl<<endl;
	cout<<"1|2|3"<<endl;
	cout<<"-----"<<endl;
	cout<<"4|5|6"<<endl;
	cout<<"-----"<<endl;
	cout<<"7|8|9"<<endl;

	
}
void showOptions(){
	cout << "1 - 1 Round" << endl;
	cout << "2 - Best of 3" << endl;
	cout << "3 - Certain Round" << endl;
	cout << "Enter choice (1 thru 3): ";
	
}
