//=================================================
// Name        : score.h
// Author      : Anaqhelly Cisneros
// Institution : Dartmouth College
// School	   : Thayer School of Engineering
// Description : Term Project in C++
// Date		   : February 17, 2018
//=================================================
#include <iostream>
#include <conio.h>

using namespace std;

class score{

private:
	int player1_score;
	int player2_score;

public:
	//constructor
	score();

	//functions
	void set_player1_score(int n);
	void set_player2_score(int n);
	int get_player1_score();
	int get_player2_score();
	void Display_score();
	int Display_winner();

};




