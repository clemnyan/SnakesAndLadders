//=================================================
// Name        : Ladder.h
// Author      : Anaqhelly Cisneros
// Institution : Dartmouth College
// School	   : Thayer School of Engineering
// Description : Term Project in C++
// Date		   : February 17, 2018
//=================================================

/* Module for the ladders in SnakesAndLadders
 */
#include <iostream>
using namespace std;


#ifndef LADDER_H
#define LADDER_H

class Ladder {

private:
	int start, end; //beginning position and ending pos.

public:

  Ladder();  //default constructor for a snake
	// Constructor for snake, takes 2 inputs the start num and end num
	Ladder(int s, int e);
	Ladder(Ladder & l);   //copy constructor for the ladder
  //setters
	void set_start(int);  //set start location
	void set_end(int);  //set end location
  //getters
	int get_start();  //get start location
	int get_end();  //get end location
	~Ladder();  //destructor

};

#endif

