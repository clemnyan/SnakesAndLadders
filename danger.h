//=================================================
// Name        : danger.h
// Author      : Anaqhelly Cisneros
// Institution : Dartmouth College
// School	   : Thayer School of Engineering
// Description : Term Project in C++
// Date		   : February 17, 2018
//=================================================
#include <iostream>
#include <conio.h>

using namespace std;

class danger{

private:
	int danger_spot;

public:
	danger();
	danger(int ds);
	void sets_danger_loc(int ds);
	int gets_danger_loc();
	void display_Danger();

};

