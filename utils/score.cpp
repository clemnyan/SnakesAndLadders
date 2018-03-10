//=================================================
// Name        : score.cpp
// Author      : Anaqhelly Cisneros
// Institution : Dartmouth College
// School	   : Thayer School of Engineering
// Description : Term Project in C++
// Date		   : February 20, 2018
//=================================================

#include <iostream>
#include <conio.h>
#include "score.h"

using namespace std;

score :: score(){

	player1_score=0;
	player2_score=0;
}

void score :: set_player1_score(int n){

	player1_score=n;
}

void score :: set_player2_score(int n){

	player2_score=n;
}
int score :: get_player1_score(){
	return player1_score;
}
int score :: get_player2_score(){
	return player1_score;
}
void score :: Display_score(){

	cout << "Score for Player 1: " << player1_score<<endl;
	cout << "Score for Player 2: " << player2_score << endl;
}

int score :: Display_winner(){

	if(player1_score > player2_score){
		cout << "************************"<<endl;
		cout << "***  PLAYER 1 WINS! ***"<<endl;
		cout << "************************"<<endl;

		return 1;

	}
	else {
		cout << "************************"<<endl;
		cout << "***  PLAYER 2 WINS! ***"<<endl;
		cout << "************************"<<endl;

		return 2;

	}
}


