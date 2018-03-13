//=================================================
// Name        : Dice.h
// Author      : Anaqhelly Cisneros
// Institution : Dartmouth College
// School	   : Thayer School of Engineering
// Description : Term Project in C++
// Date		   : February 20, 2018
//=================================================

/* Module for rolling the dice */

#include <iostream>
using namespace std;

#ifndef DICE_H
#define DICE_H

class Dice{
	private:
		int value;
	public:
		Dice();
		void roll_dice();  //roll the dice
		int gets_value();   // get value after rolling
		void resetDice ();   // reset the dice
	  ~Dice();  //destructor
};

#endif

