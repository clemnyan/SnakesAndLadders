/* Clement Nyanhongo
 *
 * Module with the driver Program
 */
#include <iostream>
#include "utils/Game.h"

using namespace std;

int main(){

  //Create new game instance
	Main_Game *g1 = new Main_Game();

  int start = 0;
	while (start ==0) {
		start = g1 -> intro();    //intro populates game properties
	}

	//Print the game board
	g1 -> printBoard();

  cout << g1->isComplete()<<endl;
	while (g1 -> isComplete() == 0) {
    g1 ->Play_Game();
	}

	g1 -> Play_Game();  //to print winners
	delete(g1); //destructor

	return 0;
}

