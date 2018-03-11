//=================================================
// Name        : Snake.h
// Author      : Anaqhelly Cisneros
// Institution : Dartmouth College
// School	   : Thayer School of Engineering
// Description : Term Project in C++
// Date		   : February 17, 2018
//=================================================

/* Module for the snake in Snakes in Snakes and ladders
 */
#include <iostream>
using namespace std;

#ifndef SNAKE_H
#define SNAKE_H

class Snake {

private:
	int start, end; //beginning position and ending pos.

public:

  Snake();  //default constructor for a snake
	// Constructor for snake, takes 2 inputs the start num and end num
	Snake(int s, int e);
	Snake (Snake & s);   //copy constructor for a snake
  //setters
	void set_start(int);  //set start location
	void set_end(int);  //set end location
  //getters
	int get_start();  //get start location
	int get_end();  //get end location
	~Snake();  //destructor

};

#endif

