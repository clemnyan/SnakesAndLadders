/* Clement Nyanhongo
 * Snake.cpp
 *
 *
 * This module defines operations for the snake
 * in Snakes  and ladders
 */


#include <iostream>
#include "Snake.h"

using namespace std;

/* default constructor, the snake doesnt exist since it does not have a
 *defined length
 */
Snake :: Snake() {
  this -> start = -1;
  this -> end = -1;
}

Snake :: Snake (int s, int e) {   // Parametrized Constructor
  this -> start = s;
  this -> end = e;
}

Snake :: Snake (Snake & s) {   //copy constructor for the snake
  this -> start = s.start;
  this -> end = s.end;
}

void Snake :: set_start(int x) {  //set starting point
  this -> start = x;
}

void Snake :: set_end(int x) { //set end coordinate
  this -> end = x;
}

int Snake :: get_start() {   //get start location
  return this -> start;
}

int Snake :: get_end() {
  return this -> end;    //get end location
}

Snake :: ~Snake(){
  //Nothing to destroy
}

