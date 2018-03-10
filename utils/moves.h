//=================================================
// Name        : moves.h
// Author      : Anaqhelly Cisneros
// Institution : Dartmouth College
// School	   : Thayer School of Engineering
// Description : Term Project in C++
// Date		   : February 20, 2018
//=================================================

#include <iostream>
#include <conio.h>

using namespace std;

class moves{
private:
	int making_moves;

public:
	moves();

	void set_moves(int m);
	void addition_moves();
	int get_moves_made();

};

