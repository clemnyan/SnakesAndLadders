//=================================================
// Name        : position.h
// Author      : Anaqhelly Cisneros
// Institution : Dartmouth College
// School	   : Thayer School of Engineering
// Description : Term Project in C++
// Date		   : February 20, 2018
//=================================================

#include <iostream>
#include <conio.h>

using namespace std;

class position{
private:
	int making_moves;

public:
	moves();

	void set_pos(int m);
	void change_pos();
	int get_location();

};

