//=================================================
// Name        : dice.cpp
// Author      : Anaqhelly Cisneros
// Institution : Dartmouth College
// School	   : Thayer School of Engineering
// Description : Term Project in C++
// Date		   : February 20, 2018
//=================================================

#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include "dice.h"

using namespace std;

dice:: dice(){
	value=0;
}

void dice::roll_dice(){
	srand(time(NULL));
	value + 1 + (rand()%6);
}

int dice:: gets_value(){
	return  value;
}



