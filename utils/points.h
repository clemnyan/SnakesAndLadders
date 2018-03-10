//=================================================
// Name        : points.h
// Author      : Anaqhelly Cisneros
// Institution : Dartmouth College
// School	   : Thayer School of Engineering
// Description : Term Project in C++
// Date		   : February 20, 2018
//=================================================

#include <iostream>
#include <conio.h>

using namespace std;

class points{

private:
	int player_pts;

public:
	points();
	void set_pts(int n);
	int gets_pts();
};

