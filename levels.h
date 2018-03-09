//=================================================
// Name        : levels.h
// Author      : Anaqhelly Cisneros
// Institution : Dartmouth College
// School	   : Thayer School of Engineering
// Description : Term Project in C++
// Date		   : February 17, 2018
//=================================================
#include <iostream>
#include <conio.h>
#include "board.h"
#include "turn.h"

using namespace std;

class levels{

private:
	int number;
	board board_1;
	turns *turn= new turns;

public:
	//constructor
	levels();
	levels(int n);

	void set_level_number(int n);
	int get_level_number();

	void set_level_turns(int n);
	void diplay_level_onBoard();
	void get_remain_turns();

	int get_Snake_start(int n);
	int get_Snake_end(int n);
	int get_Ladder_start(int n);
	int get_Ladder_end(int n);
	int get_bonus_pos(int n);
	int get_danger_pos(int n);


};

