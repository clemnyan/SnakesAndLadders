//=================================================
// Name        : Player.cpp
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
#include "Player.h"
#include "Dice.h"

using namespace std;

Player:: Player() {   //default constructor for a player
	this -> player_name= "";
	this -> player_number=0;
	this -> score = 0;
	this -> location = 0;
	this -> die = new Dice();
}

Player :: Player(string name , int num){
  this -> player_name = name;
	this -> player_number = num;
	this -> score = 0;
	this -> location = 0;
	this -> die = new Dice();
}

void Player :: modify_location(int k) {
	if (this -> location +k < 0) {  //you can not move to a value less than 0
		this -> location = 0;
	}
	else {
		this -> location = this -> location + k;
	}
}

void Player :: set_location (int k) {  //set the location for a player
	this -> location = k;
}

void Player :: set_name(string name) {  //set player name
	this -> player_name=name;
}

void Player :: set_player_number(int n) {  //set player number
	this -> player_number=n;
}

void Player :: set_score (int m) {  //set the score for the player
	this -> score = m;
}

string Player :: get_name(){   //get the player name
	return player_name;
}

int Player :: get_player_number(){   //get the player number
	return player_number;
}

int Player :: get_location (){   // get the location of the player
	return this -> location;
}

int Player :: get_score (){
	return this -> score;
}

int Player :: roll () {  // Method for the player to roll the die
  cout << "Player: "<<this -> player_name<<" 's turn to roll die"<<endl;
	if (this -> die == NULL) {
		this -> die = new Dice();
	}
	this -> die -> roll_dice(); //roll the Dice
	int val = this -> die -> gets_value();  // get the value
  this -> die -> resetDice(); //reset die for future use
	return val;    // return the score
}

Player :: ~Player() {  // destructor for the player
	delete(die);
}

