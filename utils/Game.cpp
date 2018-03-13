/* Main_Game.c

 * Clement Nyanhongo

 * Module with the control logic of the game. It
 * uses the modelled classes to ensure that the
 * flow of the game is consistent and well abstracted.
 */

#include <iostream>
#include <unistd.h>
#include "Dice.h"
#include "Player.h"
#include "Board.h"
#include "Snake.h"
#include "Ladder.h"
#include "Points.h"

using namespace std;

class Main_Game{
private:
	Player ** players;   //Players in the game
	Snakes ** snakes;    // array of snakes in the game
	Ladders ** ladders;  //array of ladders in the game
  int numOfPlayers;
  int difficulty;
  int numOfSnakes;
  int numOfLadders;
	int * scores;       //array of game scores
	Board *board;       //The board to show game state
public:

  Main_Game :: Main_Game(Players *p[], int numOfPlayers, int difficulty){

     /* Initialize game based on the difficulty defined. As the difficulty
      * increases, the ratio of snakes to ladders decreases making it
      * less easier for the player to win.
      */
     if (difficulty == 1) {  //minimum difficulty
       numOfSnakes = 5;
       numOfLadders = 8;
       this ->board = new Board(5,10);
     }
     else if (difficulty == 2) {  // intermediate difficulty
       numOfSnakes = 8;
       numOfLadders = 6;
       this -> board = new Board(10,10);
     }
     else {
       numOfSnakes = 15;
       numOfLadders = 9;
       this -> board = new Board(10, 15);
     }

     //initialize variables
     this -> snakes = calloc(1, sizeof(Snake **));
     this -> ladders = calloc(1, sizeof(Ladder **));
     this -> Players = calloc (1, sizeof (Player **));
		 this -> scores = new int [numrOfPlayers];

     // Populate players into the game
		 for (int i=0 ; i<numOfPlayers; i++) {
			 this -> players[i] = p[i];
		 }

		 // Populate the snakes and ladders for varying difficulty
     if (difficulty == 1) {   // populate snakes and ladders props for level 1
			 Points *pt = new Points(0)
			 for (int i = 0; i<3  ; i++) {  //populate large
	      this -> snakes [i] = new Snake (pt -> sS1[i], pt -> sS2[i]);
	     }
			 for (int i = 3: i< 5 ; i++ ) {
				 this -> snakes [i] = new Snake (pt -> S1[i], pt -> S2[i]);
			 }
			 for (int i=0; i<4 ; i++) {
				 this -> ladders[i] = new Ladder (pt -> L1[i], pt -> L2[i]);
			 }
			 for (int i=0; i<4 ; i++) {
				 this -> ladders[i+4] = new Ladder (pt -> sL1[i+4], pt -> sL2[i+4]);
			 }
		 }

		 else if (difficulty == 2) {   // populate snakes and ladders props for level 2
			Points *pt = new Points(1)
			for (int i = 0; i<4  ; i++) {  //populate large
			 this -> snakes [i] = new Snake (pt -> sS1[i], pt -> sS2[i]);
			}
			for (int i = 4: i< 8 ; i++ ) {
				this -> snakes [i] = new Snake (pt -> S1[i], pt -> S2[i]);
			}
			for (int i=0; i<3 ; i++) {
				this -> ladders[i] = new Ladder (pt -> L1[i], pt -> L2[i]);
			}
			for (int i=3; i<6 ; i++) {
				this -> ladders[i] = new Ladder (pt -> sL1[i], pt -> sL2[i]);
			}
		}

		if (difficulty == 3) {   // populate snakes and ladders props for level 3
		 Points *pt = new Points(2)
		 for (int i = 0; i<10  ; i++) {  //populate large
			this -> snakes [i] = new Snake (pt -> sS1[i], pt -> sS2[i]);
		 }
		 for (int i = 10: i< 15; i++ ) {
			 this -> snakes [i] = new Snake (pt -> S1[i], pt -> S2[i]);
		 }
		 for (int i=0; i<4 ; i++) {
			 this -> ladders[i] = new Ladder (pt -> L1[i], pt -> L2[i]);
		 }
		 for (int i=4; i<9 ; i++) {
			 this -> ladders[i] = new Ladder (pt -> sL1[i], pt -> sL2[i]);
		 }
	 }
  }

	int Main_Game ::  intro(){
    cout << "Welcome to your favourite Game: Snakes and Ladders" <<endl;
    cout << "SELECT ONE OF THE OPTIONS BELOW TO CONTINUE (enter number)"<<endl;
    cout << "1. START GAME    2. GAME INSTRUCTIONS  .3 EXIT"<<endl;
    int ans;
    cin >> ans;
    if (ans == 1){
      cout << "GAME INIT SUCCESSFUL ...."<<endl;
      sleep(2); // delay a bit
      cout <<"\nChoose the game level (1 - Easy, 2-Medium, 3- Hard): "<< endl;
      cin >> this -> difficulty;
      if (this -> difficulty < 1) {  //set to base level if out of bounds
        this -> difficulty = 1;
      }
      if (this -> difficulty > 3) {   // set to the highest level
        this -> difficulty = 3;
      }
      sleep(2); // delay a bit
      return 1;
    }
    else if (ans == 2) {
      return gameInstructions();
    }
    else if (ans == 3){
      cout << "EXITING ...";
      sleep(1);
      EXIT(1);
    }
    else {
      cout << "Choose the correct option (1, 2 or 3)"<<endl;
      return 0;
    }
  }

	void info_player();
	void show_state();
	void game_state();
	void getScores();
	void showBoard();

  //instructions for the game
  int Main_Game :: gameInstructions(){
    cout << " \nThe goal of this game is to strategically roll the dice"<<endl;
    cout << " and make logical decisions to ensure that as a player you" <<endl;
    cout << " reach the finsh point first before other players" <<endl;
    cout << " in the game. Basically the decisions will "<<endl;
    cout << " involve attacking players, overcoming snake obstacles," <<endl;
    cout << " and utilizing opportunies to get bonuses and ladders." <<endl;
    cout << " The game is also probablistic since its based on the dice"<<endl;
    cout << " but good decisions will give you an added advantage\n" <<endl;
    return intro();
  }

  //destructor for the whole game
  Main_Game :: ~Main_Game () {
    for (int i =0; i< numOfSnakes; i++){
       delete(snakes[i]);
     }
    for (int i=0; i< numOfLadders; i++) {
      delete(ladders[i]);
    }
    for (int i=0; i<numOfPlayers; i++) {
      delete(players[i]);
    }
    delete(scores);
    delete(board);
  }

};

