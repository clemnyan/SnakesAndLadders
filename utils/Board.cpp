//=================================================
// Clement      : Clement Nyanhongo
// Institution : Dartmouth College
// School          : Thayer School of Engineering
// Description : Term Project in C++
// Date            : February 20, 2018
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
  int count = -1;  //prints column-walls for each i, j coordinates
  int len = 5* this -> length;
  int wid = this -> width;

  for (int i=0; i<=len ; i++) {
    for (int j=0; j<wid; j++) {
      int m = j+1;
      if ((m % wid == 0) && ((i % 5) == 0)) {
        count ++;
      }

      if (i % 5 == 0) {
          cout << "#---------";   //print top row
      }
      else {
        if (i % 5 == 1) {
          int val = (count*wid) + j+1;
          int num = this -> NumDigits(val);
          if (num == -1){ // Error case
            cout << "Error: Out of limits for board size"<<endl;
            exit(1);
          }
          if (num==1){
            cout <<"#"<<val<<"        ";
          }
          else if (num==2){
            cout <<"#"<<val<<"       ";
          }
          else {
            cout <<"#"<<val<<"      ";
          }
       }
       else if (i<5 && j==0 && (i == 3)){
          cout <<"#  START  ";  //To denote start
       }
       else if (i>len -5  && j==wid -1 && (i ==(len-5+3))) {
          cout <<"#   END   ";   //To denote the end
       }
       else {
          cout << "#         ";   //print inner row
       }
      }
    }
  cout <<"#\n";
  }
}

/*Determine number of digits to help display integers in correct
  format on the board. The limit is up to 1000 */
int Board :: NumDigits(int x)
{
    x = abs(x);
    return (x < 10 ? 1 :
        (x < 100 ? 2 :
        (x < 1000 ? 3 :
        -1)));
}


Board :: ~Board() {
  // Nothing to destroy
}

