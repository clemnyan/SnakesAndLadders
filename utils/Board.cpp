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
Board :: Board(int len, int wid, Snake *snks [], Ladder *ldrs [],
     int snksSize, int ldrsSize)
{
  this -> length = len;
  this -> width = wid;
  this -> snakes = (Snake **) calloc(1, sizeof(Snake **));
  this -> ladders = (Ladder **)calloc(1, sizeof(Ladder **));
  for (int i=0; i< snksSize; i++) {  //insert snakes into the board
    this -> snakes[i] = new Snake(*snks[i]);  //using copy constructor
  }
  for (int i=0; i< ldrsSize; i++) {  //insert ladders into the board
    this -> ladders[i] = new Ladder(*ldrs[i]);  //using copy constructor
  }
  this -> numberofSnakes = snksSize;
  this -> numberofLadders = ldrsSize;
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

/* Helper function to print board with varios objects such as snakes, players */
void Board :: printHelper (int i, int j, int wid, int count, int len) {
  int val =(count*wid) + j+1;  //box number on board
  if (i % 5 == 1) {  //first line of each box on grid
    int num = this -> NumDigits(val);
    //For detecting snake locations
    int smark = 0;  //to mark if snake is present in box
    int indexs = 0; //to track index of the snake
    for (int k=0; k<this -> numberofSnakes; k++) {
      if (this -> snakes[k] -> get_start() == val ||
        this -> snakes[k] -> get_end() == val) {
          smark =1;
          indexs = k;
        }
    }

    if (num == -1){ // Error case
      cout << "Error: Out of limits for board size"<<endl;
      smark = 0;
      exit(1);
    }
    if (num==1){  // box number only 1 digit
      if (smark == 1) {  //if snake exists in this location
         int numdig = this -> NumDigits(indexs);  //number of digits of snake index
         if (numdig == 1){
           cout <<"#"<<val<<"     S"<<indexs<<" ";
         } else {   //Total number of snakes < 100 (constraint)
           cout <<"#"<<val<<"    S"<<indexs<<" ";
         }
         smark = 0;  //reset marker
      }
      else {
        cout <<"#"<<val<<"        ";
      }
    }
    else if (num==2){
      if (smark == 1) {  //if snake exists in this location
         int numdig = this -> NumDigits(indexs);  //number of digits of snake index
         if (numdig == 1){
           cout <<"#"<<val<<"    S"<<indexs<<" ";
         } else {   //Total number of snakes < 100 (constraint)
           cout <<"#"<<val<<"   S"<<indexs<<" ";
         }
         smark = 0;  //reset marker
      }
      else {
        cout <<"#"<<val<<"       ";
      }
    }
    else {
      if (smark == 1) {  //if snake exists in this location
         int numdig = this -> NumDigits(indexs);  //number of digits of snake index
         if (numdig == 1){
           cout <<"#"<<val<<"   S"<<indexs<<" ";
         } else {   //Total number of snakes < 100 (constraint)
           cout <<"#"<<val<<"  S"<<indexs<<" ";
         }
         smark = 0;  //reset marker
      }
      else {
        cout <<"#"<<val<<"      ";
      }
    }
 }
 else if (i % 5 == 2) {  //second line of box on grid
     //For detecting ladder locations
     int smarl = 0;  //to mark if a ladder is present in box
     int indexl = 0; //to track index of the ladder
     for (int k=0; k<this -> numberofLadders; k++) {
       if (this -> ladders[k] -> get_start() == val ||
         this -> ladders[k] -> get_end() == val) {
           smarl =1;
           indexl = k;
         }
     }
     if (smarl == 1) {  //if ladder exists in this location
        int numdig = this -> NumDigits(indexl);  //digits in ladder index
        if (numdig == 1){
          cout <<"#      L"<<indexl<<" ";
        } else {   //Total number of ladders < 100 (constraint)
          cout <<"#     L"<<indexl<<" ";
        }
        smarl = 0;  //reset marker
       }
     else {
         cout <<"#         ";
       }
 }
 else if (j==0 && (i == 3)){
    //To denote start
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
  //delete all the snakes
  for (int i=0; i<this -> numberofSnakes; i++) {
    delete(this -> snakes[i]);
  }
  delete(this -> snakes);
}

