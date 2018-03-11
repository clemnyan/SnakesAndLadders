/* Clement Nyanhongo
 * Ladder.cpp
 *
 *
 * This module defines operations for the ladder
 * in SnakesAndladders
 */


#include <iostream>
#include "Ladder.h"

using namespace std;

/* default constructor, the Ladder doesnt exist since it does not have a
 *defined length
 */
Ladder :: Ladder() {
  this -> start = -1;
  this -> end = -1;
}

Ladder :: Ladder (int s, int e) {   // Parametrized Constructor
  this -> start = s;
  this -> end = e;
}

Ladder :: Ladder (Ladder & l) {   //copy constructor for the Ladder
  this -> start = l.start;
  this -> end = l.end;
}

void Ladder :: set_start(int x) {  //set starting point
  this -> start = x;
}

void Ladder :: set_end(int x) { //set end coordinate
  this -> end = x;
}

int Ladder :: get_start() {   //get start location
  return this -> start;
}

int Ladder :: get_end() {
  return this -> end;    //get end location
}

Ladder :: ~Ladder(){
  //Nothing to destroy
}

