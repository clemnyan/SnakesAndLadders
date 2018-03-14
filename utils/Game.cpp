/* Main_Game.cpp

 * Clement Nyanhongo

 * Module with the control logic of the game. It
 * uses the modelled classes to ensure that the
 * flow of the game is consistent and well abstracted.
 */

#include <iostream>
#include <string.h>
#include <unistd.h>
#include "Game.h"
#include "Board.h"

using namespace std;

// Constructor for  the main game controller
Main_Game :: Main_Game() {
	players = NULL;
	snakes = NULL;    // array of snakes in the game
	ladders = NULL;  //array of ladders in the game
	board = NULL;
}

//Method to play the game
void Main_Game :: Play_Game (){

   if (isComplete() == 1) {
		 cout << "\nGame over!" <<endl;
     //display the player who just won the game
		 int target = this->board -> getLength() * this -> board -> getWidth();
		 for (int i=0; i<numOfPlayers; i++) {
			 if (this -> players[i] ->get_score() >= target) {
				 cout << "Player "<<this -> players[i]-> get_name()<<" wins the game" <<endl;
			 }
		 }
     // Print the scores of the other players
     printScores();
		 exit(0);
	 }
	 else {
		 //print the current scores
		 cout << "\nCurrent scores now:"<<endl;
		 printScores();
     // Roll the die for each player and increment the scores accordingly
		 for (int i=0; i<numOfPlayers ; i++) {
			 int choice;
			 int s1, s2, s3;   //scores from rolling the die
			 //A player rolls the dice three times and chooses best score
			 s1 = this -> players[i] -> roll();
			 s2 = this ->players[i] ->  roll();
			 s3 = this -> players[i] -> roll();
			 cout << "Die outcomes: ("<<s1<<","<<s2<<","<<s3<<")"<<endl;
			 cout << "\nChoose dice to use (1,2,3): " <<endl;
			 cin >> choice;
			 if (choice == 1) {
				 this -> players[i] -> set_score (this -> players[i] -> get_score() + s1);
			 }
			 else if (choice == 2) {
				 this -> players[i] -> set_score (this -> players[i] -> get_score() + s2);
			 }
			 else {
				 this -> players[i] -> set_score (this -> players[i] -> get_score() + s3);
			 }
       //check to see if the score is accociated a the snake location
			 for (int j=0; j<numOfSnakes; j++) {
				 if (this -> snakes[j]-> get_start() == this -> players[i] -> get_score()){
					 // Move the user score(location) to the tail of the snake
					 cout << "Ooops, swallowed by snake!" <<endl;
					 this -> players[i] -> set_score(this -> snakes[j] -> get_end());
					 break;
				 }
			 }
			 //check to see if the score is associated with a ladder location
			 for (int j=0; j<numOfLadders; j++) {
				 if (this -> ladders[j]-> get_start() == this -> players[i] -> get_score()){
					 // Move the user score(location) to the top of the ladder
					 cout << "Bingo, climbed the ladder!" <<endl;
					 this -> players[i] -> set_score(this -> ladders[j] -> get_end());
					 break;
				 }
			 }
		 }
	 }
}

//print the scores of the Players
void Main_Game :: printScores (){
	cout<<"SCORES: "<<endl;
	for (int i=0; i<this-> numOfPlayers; i++) {
		cout << "Player " << this -> players[i] -> get_name() << " :Score ";
		cout << this -> players[i] -> get_score() << endl;
  }
	cout <<endl;
}

//Check state of the game to see if the game is complete
int Main_Game :: isComplete () {
	// Target score based on board dimensions
	int target = this->board -> getLength() * this -> board -> getWidth();
	//check to see any of the Players reached the target score
  for (int i=0; i<this-> numOfPlayers; i++) {
		if (this -> players[i] -> get_score() >= target) {
			return 1;
		}
	}
	//game not complete
	return 0;
}

// Method to print ASCI board configuration of the game
void Main_Game :: printBoard() {
	this -> board -> printBoard();
}

// Game introduction
int Main_Game ::  intro() {
	cout << "Welcome to your favourite Game: Snakes and Ladders" <<endl;
	cout << "SELECT ONE OF THE OPTIONS BELOW TO CONTINUE (enter number)"<<endl;
	cout << "1. START GAME    2. GAME INSTRUCTIONS  .3 EXIT"<<endl;
	int ans;
	cin >> ans;
	if (ans == 1){
		cout << "GAME INIT SUCCESSFUL ...."<<endl;
		sleep(1); // delay a bit
		cout <<"\nChoose the game level (1 - Easy, 2-Medium, 3- Hard): "<< endl;
		cin >> this -> difficulty;
		if (this -> difficulty < 1) {  //set to base level if out of bounds
			this -> difficulty = 1;
		}
		if (this -> difficulty > 3) {   // set to the highest level
			this -> difficulty = 3;
		}
		// Create players
		getPlayers();
		// constructs new game and with valid properties
		game_Init();
		return 1;  //successful return
	}
	else if (ans == 2) {
		return gameInstructions();
	}
	else if (ans == 3){
		cout << "EXITING ...";
		exit(1);
	}
	else {
		cout << "Choose the correct option (1, 2 or 3)"<<endl;
		return 0;
	}
}

// Initialize and fill the game variables (snakes, ladders, boards)
void Main_Game :: game_Init() {
	//initialize variables
	this -> snakes = (Snake **) calloc(1, sizeof(Snake **));
	this -> ladders = (Ladder **) calloc(1, sizeof(Ladder **));
  /* Initialize game based on the difficulty defined. As the difficulty
   * increases, the ratio of snakes to ladders decreases making it
   * less easier for the player to win.
   */
  if (this -> difficulty == 1) {  //minimum difficulty
    numOfSnakes = 5;
    numOfLadders = 8;
	  fillSnakesLadders(this -> difficulty);
    this ->board = new Board(5, 10, this -> snakes, this -> ladders,5,8);
   }
   else if (this -> difficulty == 2) {  // intermediate difficulty
     numOfSnakes = 8;
     numOfLadders = 6;
		 fillSnakesLadders(this -> difficulty);
		 this ->board = new Board(10, 10, this -> snakes, this -> ladders,8,6);

   }
   else { //highest difficulty
     numOfSnakes = 15;
     numOfLadders = 9;
		 fillSnakesLadders(this -> difficulty);
		 this ->board = new Board(10, 15, this -> snakes, this -> ladders,15,9);
   }

}

  //instructions for the game
int Main_Game :: gameInstructions(){
  cout << "\nThe goal of this game is to roll the dice"<<endl;
  cout << "and make logical decisions to ensure that as a player you" <<endl;
  cout << "reach the finsh point first before other players" <<endl;
  cout << "in the game. Basically the decisions will involve" <<endl;
	cout << "overcoming snake obstacles, and utilizing opportunies" <<endl;
	cout << "to get ladders.The game is also probablistic since its" <<endl;
	cout << "based on the dice but good decisions will give you an" <<endl;
	cout << "added advantage\n" <<endl;
  return intro();
}

// Populate the snakes and ladders for varying difficulty
void Main_Game :: fillSnakesLadders(int difficulty) {
	// populate snakes and ladders props for level 1
  if (difficulty == 1) {
		Points *pt = new Points(0);
		for (int i = 0 ; i<this -> numOfSnakes; i++ ) {
				this -> snakes [i] = new Snake (pt -> S1[i], pt -> S2[i]);
		}
		for (int j=0; j<this -> numOfLadders ; j++) {
			this -> ladders[j] = new Ladder (pt -> L1[j], pt -> L2[j]);
		}
	}
	// populate snakes and ladders props for level 2
	if (difficulty == 2) {
		Points *pt = new Points(1);
		for (int i = 0 ; i<this -> numOfSnakes; i++ ) {
				this -> snakes [i] = new Snake (pt -> S1[i], pt -> S2[i]);
		}
		for (int j=0; j<this -> numOfLadders ; j++) {
			this -> ladders[j] = new Ladder (pt -> L1[j], pt -> L2[j]);
		}
	}
	 // populate snakes and ladders props for level 3
	if (difficulty == 3) {
		 Points *pt = new Points(2);
		 for (int i = 0 ; i<this -> numOfSnakes; i++ ) {
 				this -> snakes [i] = new Snake (pt -> S1[i], pt -> S2[i]);
 		}
 		for (int j=0; j<this -> numOfLadders ; j++) {
 			this -> ladders[j] = new Ladder (pt -> L1[j], pt -> L2[j]);
 		}
	 }
 }

	// Method to get the Players and populate them
	void Main_Game :: getPlayers () {
		int num;  // number  of Players
	  cout << "How many players will players (2 up to 5?)"<<endl;
	  cin >> num;
	  if (num > 1 && num <=5) {
		   this -> numOfPlayers = num;
			 this -> players = (Player **) calloc (1, sizeof (Player **));
			 for (int i=0; i<num ; i++) {
				  string name;  //variable to hold player name
					cout << "Enter Player "<<i+1<<" 's name"<<endl;
					cin >> name;
					this -> players[i] = new Player(name, i+1);
			 }
			 return;
		}
		else {
			cout << "Number of players should be from 0 to 5"<<endl;
			getPlayers();
	 }
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
	 delete(board);
}

