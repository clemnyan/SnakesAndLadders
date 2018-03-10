//=================================================
// Clement      : Clement Nyanhongo
// Institution : Dartmouth College
// School	   : Thayer School of Engineering
// Description : Term Project in C++
// Date		   : February 20, 2018
//=================================================

#include <iostream>
#include "Board.h"

using namespace std;

// constructs the board for the game
Board :: Board(int len, int wid)
{
  this -> length = len;
  this -> width = wid;
}

// get the length of the board
int Board:: getLength()
{
  return this -> length;
}

// get the width of the board
int Board :: getWidth()
{
  return this -> width;
}

// print the current state/view of the board
void Board :: printBoard()
{
  for (int i=0; i< this -> length; i++) {
    for (int j=0; j< this -> width ; j++) {
      cout << "#";
    }
    cout <<endl;
  }
}

Board :: ~Board() {
  // Nothing to destroy
}

