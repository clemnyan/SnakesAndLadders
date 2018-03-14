//=================================================
// Clement      : Clement Nyanhongo
// Institution : Dartmouth College
// School          : Thayer School of Engineering
// Description : Term Project in C++
// Date            : February 20, 2018
//=================================================

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "Board.h"
#include "Snake.h"
#include "Ladder.h"

using namespace std;

// constructs the board for the game
Board :: Board(int len, int wid)
{
  this -> length = len;
  this -> width = wid;
}

void Board :: setLength(int x) {  //set length of board
  this -> length = x;
}

void Board :: setWidth(int x) {   //set width of the board
  this -> width = x;
}

int Board:: getLength()   // get the length of the board
{
  return this -> length;
}

int Board :: getWidth()  // get the width of the board
{
  return this -> width;
}

void Board :: printBoard()  // print the current state/view of the board
{
  int count = -1;  //prints column-walls for each i, j coordinates
  int len = 5* this -> length;
  int wid = this -> width;

  for (int i=0; i<=len ; i++) {
    for (int j=0; j<wid; j++) {
      int m = j+1;
      if ((m % wid == 0) && ((i % 5) == 0)) {
        count ++;    //number of times i iterates 5 times (length)
      }
      if (i % 5 == 0) {
          cout << "#---------";   //print top row
      }
      else {   //print other parts of the board in formatted structure
        this -> printHelper (i, j, wid, count, len);
      }
    }
  cout <<"#\n";
  }
}

/*Determine number of digits to help display integers in correct
  format on the board. The limit is up to 1000 */
int Board :: NumDigits(int x) {
    x = abs(x);
    return (x < 10 ? 1 :
        (x < 100 ? 2 :
        (x < 1000 ? 3 :
        -1)));
}

/* Helper function to print board */
void Board :: printHelper (int i, int j, int wid, int count, int len) {
  int val = (width * length- j)-(count*wid); //box number on board
  if (i % 5 == 1) {  //first line of each box on grid
    int num = this -> NumDigits(val);
    if (num == -1){ // Error case
      cout << "Error: Out of limits for board size"<<endl;
      exit(1);
    }
    if (num==1){  // box number only 1 digit
        cout <<"#"<<val<<"        ";
    }
    else if (num==2){
        cout <<"#"<<val<<"       ";
    }
    else {
       cout <<"#"<<val<<"      ";
    }
 }
 else if (j==0 && (i == 3)){
   cout <<"#   END   ";   //To denote the end
 }
 else if (j==wid -1 && (i ==(len-5+3))) {
   cout <<"#  START  ";  //To denote start
 }
 else {
    cout << "#         ";   //print inner rows
 }
}

//destructor
Board :: ~Board() {
}

