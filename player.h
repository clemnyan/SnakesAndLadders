//=================================================
// Name        : player.h
// Author      : Anaqhelly Cisneros
// Institution : Dartmouth College
// School	   : Thayer School of Engineering
// Description : Term Project in C++
// Date		   : February 20, 2018
//=================================================

#include <iostream>
#include <conio.h>
#include <string>
#include "moves.h"
#include "points.h"
#include "position.h"

using namespace std;

class player{
private:

	string player_name;
	int player_number;

	position *p= new position;
	moves *m= new moves;
	points *pt= new points;

public:
	player();
	player(string name, int num);

	void sets_location_player(int n);
	void changes_location_player(int n);

	void sets_player_name(string name_2);
	void sets_player_number(int n);

	string gets_player_name();
	int gets_player_number();
	int gets_location_player();
	void displays_player_location();

	//uses moves.h
	void set_moves_player(int n);
	void increase_player_moves();
	int gets_moves_player();
	void display_moves_player();

	//uses points.h
	void sets_player_points(int n);
	int gets_player_points();
	int gets_points();


};

