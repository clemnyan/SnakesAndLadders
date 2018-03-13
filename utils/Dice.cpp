//=================================================
// Name        : dice.cpp
// Author      : Anaqhelly Cisneros
// Institution : Dartmouth College
// School	   : Thayer School of Engineering
// Description : Term Project in C++
// Date		   : February 20, 2018
//=================================================

/* Module for rolling the die during the game */

#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include "Dice.h"

using namespace std;

Dice:: Dice(){
	value=0;
}

void Dice :: roll_dice(){   // roll the dice during the game
	cout << "rolling dice ....\n";
	sleep(2);     //delay a bit while rolling the die
	value = value + 1 + (rand()%6);
}

int Dice :: gets_value(){   //get the value from the dice
	return  value;
}

void Dice :: resetDice (){   //reste the dice
	value = 0;
}

Dice :: ~Dice(){
	//Nothing to destroy
}

