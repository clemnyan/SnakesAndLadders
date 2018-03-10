//=================================================
// Name        : Board.h
// Author      : Clement Nyanhongo
// Institution : Dartmouth College
// School	   : Thayer School of Engineering
// Description : Term Project in C++
// Date		   : February 17, 2018
//=================================================

/*Module to view the state of the game on an n*m
 * grid as the game progresses
 */
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

	//getters
	int getLength();
	int getWidth();
  //print the board
  void printBoard();
  // find number of digits in integer
  int NumDigits(int x);
  ~Board();

};

#endif

