//=================================================
// Name        : Snake.h
// Author      : Anaqhelly Cisneros
// Institution : Dartmouth College
// School	   : Thayer School of Engineering
// Description : Term Project in C++
// Date		   : February 17, 2018
//=================================================
#include <iostream>
#include <conio.h>

using namespace std;

class snake{

private:
	int start, end; //beginning position and ending pos.

public:
	//constructor
	snake();

	//parameterized constructor
	snake(int s, int e);


	void set_startS(int);
	void set_endS(int);

	int get_startS();
	int get_endS();

	voind diplay_snake();


};


