#include "TTT.h"


short TTT::CheckBoard()const{

	int sum=0,count=0;
	
	for (int r = 0; r<3; r++) {	//win in column
		for (int c = 0; c<3; c++){
			sum+=board[r][c];
		}
		if(sum==3)
			return X;
		else if(sum==-3)
			return O;
			
		
	}
	sum=0;
	for (int c = 0; c<3; c++) { //win in row
		for (int r = 0; r<3; r++) {
			sum += board[r][c];
		}
		if(sum==3)
			return X;
		else if(sum==-3)
			return O;
	}
	sum=0;
	for(int i=0;i<3;i++){//win diagonal (\)
		
		sum+=board[i][i];
		if(sum==3)
			return X;
		else if(sum==-3)
			return O;
		
	}
	sum=0;
	sum=board[0][2]+board[1][1]+board[2][0];//win diagonal (/)
	if(sum==3)
		return X;
	else if(sum==-3)
		return O;

	return E;//none
	
}

TTT::TTT(){
	turn=E;
for (int r = 0; r<3; r++) {
	for (int c = 0; c<3; c++)
		board[r][c]=turn;
	}		
}

void TTT::ClearBoard(){
	turn=E;
	for (int r = 0; r<3; r++) {
		for (int c = 0; c<3; c++)
			board[r][c]=turn;
	}
	
}

bool TTT::MakeMove(short player, int r, int c){
	bool move=false;
	if(player==20){
		turn=X;
		if(board[r][c]==0){
			board[r][c]=X;
			move=true;
			return move;
		}
		else{
			return move;
		}
	}
	else if(player==21){
		if(board[r][c]==0){
			turn=O;
			board[r][c]=O;
			move=true;
			return move;
		}
		else{
			return move;
		}	
	}	
}

void TTT::PrintBoard()const{
	for (int r = 0; r<3; r++) {
		if(r==2||r==1)
			cout<<string(5,'-')<<endl;
		for (int c = 0; c<3; c++){
			if(c==2||c==1)
				cout<<"|";
		
			if(board[r][c]==0)
				cout<<" ";
			else if (board[r][c]==X)
				cout<<"X";
					
			else if(board[r][c]==O)
				cout<<"O";
				
		}
		cout<<endl;		
	}
}
