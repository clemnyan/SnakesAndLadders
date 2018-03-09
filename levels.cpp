//=================================================
// Name        : levels.h
// Author      : Anaqhelly Cisneros
// Institution : Dartmouth College
// School	   : Thayer School of Engineering
// Description : Term Project in C++
// Date		   : February 17, 2018
//=================================================
#include <iostream>
#include <conio.h>
#include "levels.h"

using namespace std;

levels levels:: levels(){

	number=0;
}
levels levels:: levels(int n){
	number=n;
}
void levels::set_level_number(int n){
	number=n;
}
int levels:: get_level_number(){
	return number;
}
void levels::diplay_level_onBoard(){

	int holder;
	holder= this->get_level_number();
	board_1.display_board(holder);
}

void levels::set_level_turns(int n){

	turn[0]= set_total_turns(n);
}
void levels::get_remain_turns(){

	turn[0].displays_left_turns();
}
int levels:: get_Snake_start(int n){
	return board_1.get_startS(n);
}
int levels::get_Snake_end(int n){
	return board_1.get_endS(n);
}
int levels:: get_Ladder_start(int n){
	return board_1.get_startl(n);
}
int levels:: get_Ladder_end(int n){
	return board_1.get_endl(n);
}
int levels::get_bonus_pos(int n){
	return board_1.get_bonus_loc(n);
}
int levels::get_danger_pos(int n){
	return board_1.get_danger_loc(n);
}










