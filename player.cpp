//=================================================
// Name        : player.cpp
// Author      : Anaqhelly Cisneros
// Institution : Dartmouth College
// School	   : Thayer School of Engineering
// Description : Term Project in C++
// Date		   : February 20, 2018
//=================================================

#include <iostream>
#include <conio.h>
#include <string>
#include <player.h>

using namespace std;

player:: player(){

	player_name= " ";
	player_number=0;
}
player :: player(string name , int num){

	player_name=name;
	player_number=num;
}
void :: sets_player_name(string name_2){

	player_name=name_2;

}
void :: sets_player_number(int n){

	player_number=n;
}
string :: gets_player_name(){

	return player_name;
}
int :: gets_player_number(){

	return player_number;
}

void player ::sets_location_player(int n){
	p[0].set_pos(n);
}
void player ::changes_location_player(int n){
	p[0].change_pos(n);
}
int player ::gets_location_player(){
	return p[0].get_location();
}
void player:: displays_player_location(){

	cout<<"Player "<<player_number<<"it is currently located at "<<this->gets_location_player()<<endl;
}
void  player:: set_moves_player(int n){

	m[0].set_moves(n);

}
void player:: increase_player_moves(){
	m[0].addition_moves();

}
int player:: gets_moves_player(){
	return m[0].get_moves_made();

}
void player:: display_moves_player(){

	cout<<gets_moves_player();

}
void player:: sets_player_points(int n){
	pt[0].set_pts(n);

}
int player::gets_player_points(){

	return pt[0].gets_pts();

}

//not too sure about this one
//I wrote something down just to hold a place
int player::gets_points(){

	return pt[0].gets_pts();

}












