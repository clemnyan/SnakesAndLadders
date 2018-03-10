//=================================================
// Name        : game.h
// Author      : Anaqhelly Cisneros
// Institution : Dartmouth College
// School	   : Thayer School of Engineering
// Description : Project 5 in C++
// Date		   : February 17, 2018
//=================================================
#include <iostream>
#include <conio.h>
#include "dice.h"
#include "player.h"
#include "levels.h"
#include "score.h"
#include "time.h"

using namespace std;

class main_game{
private:

	dice Dicegame;
	player player1, player2;
	levels level1, level2;
	score scores;
	time t;
	void setLevel();

public:
	//functions
	void intro();
	void info_player();
	void status_of_game();
	void set_player1_score(int p_one);
	void set_player2_score(int p_two);
	void level_play(int number);
	void level1_complete();
	void level2_complete();
	void display_gameboard(int level);

	int checking_for_snakes(int m, int level);
	int checking_for_ladders(int m, int level);

	bool checking_dangers(int m, int n, int level);
	bool checking_bonus(int m, int level);

};

