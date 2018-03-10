//=================================================
// Name        : turn.h
// Author      : Anaqhelly Cisneros
// Institution : Dartmouth College
// School	   : Thayer School of Engineering
// Description : Term Project in C++
// Date		   : February 20, 2018
//=================================================

#include <iostream>
#include <conio.h>

using namespace std;

class turn{

private:
	int total_turns;
	int left_turn;
	void set_left_turn();

public:
	turn();
	void set_total_turns(int n);
	int gets_total_turns();
	int gets_left_turns();
	void displays_left_turns();

};

