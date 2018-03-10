//=================================================
// Name        : Board.h
// Author      : Clement Nyanhongo
// Institution : Dartmouth College
// School	   : Thayer School of Engineering
// Description : Term Project in C++
// Date		   : February 17, 2018
//=================================================

#include <iostream>
using namespace std;

#ifndef BOARD_H
#define BOARD_H

class Board {

private:
  //The length of the board
  int length;
  //The width of the board
  int width;
  /*
  Will  add these later
  Snakes snakes []
  Ladders ladders []
  Players players []
  */
public:
	//constructor to make the board, will add snakes and players later
	Board(int len, int wid);

	//setters and getters
	int getLength();
	int getWidth();
        void printBoard();
	~Board();

};

#endif

