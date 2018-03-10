//=================================================
// Name        : Source.cpp
// Author      : Anaqhelly Cisneros
// Institution : Dartmouth College
// School	   : Thayer School of Engineering
// Description : Project 5 in C++
// Date		   : February 17, 2018
//=================================================
#include <iostream>
#include "Board.h"

using namespace std;

int main(){

	Board *board = new Board(5,5);

	board -> printBoard();

  /*
	main_game game;
	game.intro();
	game.info_player();
	game.level_play(1);

	getch();
	*/
	return 0;
}

