//=================================================
// Name        : ladder.h
// Author      : Anaqhelly Cisneros
// Institution : Dartmouth College
// School	   : Thayer School of Engineering
// Description : Term Project in C++
// Date		   : February 17, 2018
//=================================================
#include <iostream>
#include <conio.h>

using namespace std;

class ladder{

private:
	int start, end; //beginning position and ending pos.

public:
	//constructor
	ladder();

	//parameterized constructor
	ladder(int s, int e);


	void set_startl(int);
	void set_end(int);

	int get_startl();
	int get_endl();

	voind diplay_ladder();


};

