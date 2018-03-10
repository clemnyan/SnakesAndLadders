//=================================================
// Name        : time.h
// Author      : Anaqhelly Cisneros
// Institution : Dartmouth College
// School	   : Thayer School of Engineering
// Description : Term Project in C++
// Date		   : February 17, 2018
//=================================================

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>

using namespace std;

class time_game {

private:
	double begins; //the time begins
	double ends;  //the time ends
	double ellapse; //the ellapsed time

public:
	//constructor
	time_game();

	//setters and getters
	void set_begin_time();
	void set_end_time();
	double get_ellapse_time();

};

