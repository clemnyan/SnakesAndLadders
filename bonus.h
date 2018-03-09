//=================================================
// Name        : bonus.h
// Author      : Anaqhelly Cisneros
// Institution : Dartmouth College
// School	   : Thayer School of Engineering
// Description : Term Project in C++
// Date		   : February 17, 2018
//=================================================

#include <iostream>
#include <conio.h>

using namespace std;

class bonus{
private:
	int bonus_location;

public:
	//constructor
	bonus();

	//parameterized constructor
	bonus(int bl);

	void set_bonus_loc(int bl);
	int get_bonus_loc();
	void display_bonus_location();


};



