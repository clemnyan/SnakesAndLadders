//=================================================
// Name        : Source.cpp
// Author      : Anaqhelly Cisneros
// Institution : Dartmouth College
// School	   : Thayer School of Engineering
// Description : Project 5 in C++
// Date		   : February 17, 2018
//=================================================
#include <iostream>
#include <conio.h>
#include "game.h"

using namespace std;

void main(){

	main_game game;
	game.intro();
	game.info_player();
	game.level_play(1);

	getch();
}

