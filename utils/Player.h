//=================================================
// Name        : Player.h
// Author      : Anaqhelly Cisneros
// Institution : Dartmouth College
// School	   : Thayer School of Engineering
// Description : Term Project in C++
// Date		   : February 20, 2018
//=================================================


/* Module for an individual player in the game
 * The player has properties such as a score
 * and location within the Board
 * The player can also roll the dice to make sure
 * that he moves within the Board
 */

#include <iostream>
#include <string.h>
#include "Dice.h"

using namespace std;

class Player{
private:
	string player_name;
	int player_number;
	int score;
	int location;
	Dice *die;

public:
	Player();    //default constructor for a Player
	Player(string name, int num);  // constructor with Parameters
  void modify_location(int k);
	//getters
	void set_location(int k);   //location on board (grid) for the Player
	void set_name(string name);
	void set_player_number(int n);
	void set_score(int m);
	//setters
	string get_name();
	int get_player_number();
	int get_location();
	int get_score();
	//roll Dice
	int roll ();
	//destructor
	~Player();

};

