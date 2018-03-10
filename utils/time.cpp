//=================================================
// Name        : time.cpp
// Author      : Anaqhelly Cisneros
// Institution : Dartmouth College
// School	   : Thayer School of Engineering
// Description : Term Project in C++
// Date		   : February 20, 2018
//=================================================

#include <iostream>
#include <conio.h>
#include "time.h"

using namespace std;

time_game :: time_game(){

	begins= 0;
	ends= 0;
	ellapse= 0;

}

void time_game :: set_begin_time(){

	clock_t begin;

	begin= clock();

	begins= begin;

}

void time_game :: set_end_time(){

		clock_t end;

		end= clock();

		ends= end;
}
void time_game :: get_ellapse_time(){

		ellapse= ends-begin;

		ellapse /=3600;

		return ellapse;
}

