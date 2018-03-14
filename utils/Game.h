/* Main_Game.h

 * Clement Nyanhongo

 * Module with the control logic of the game. It
 * uses the modelled classes to ensure that the
 * flow of the game is consistent and well abstracted.
 */

#include <iostream>
#include <string.h>
#include "Player.h"
#include "Board.h"
#include "Snake.h"
#include "Ladder.h"
#include "Points.h"

using namespace std;

class Main_Game {
	private:
		Player ** players;   //Players in the game
		Snake ** snakes;    // array of snakes in the game
		Ladder ** ladders;  //array of ladders in the game
	  int numOfPlayers;
	  int difficulty;
	  int numOfSnakes;
	  int numOfLadders;
		Board *board;       //The board to show game state
	public:
    Main_Game();          //default constructor for the game
		void Play_Game();     // play game
		void printScores ();  // to print the current scores of the players
		int isComplete ();   // to check if the state of the game is complete
		void printBoard();   // print the game board
		int intro();         //game intro
		void game_Init();    // initialize and fill variables
	  int gameInstructions();   //instructions for the game
	  void fillSnakesLadders(int difficulty); 	// Populate the snakes and ladders for varying difficulty
		void getPlayers (); 	// Method to get the Players and populate them
	  ~Main_Game ();        // destructor for the game
};

