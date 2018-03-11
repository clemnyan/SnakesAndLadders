/* Clement Nyanhongo
 *
 * Module with the driver Program
 */
#include <iostream>
#include "utils/Board.h"
#include "utils/Snake.h"

using namespace std;

int main(){

  //Create snakes
	Snake *snakes [3];
	snakes[0] = new Snake(5,10);
	snakes[1] = new Snake(9,20);
	snakes[2] = new Snake(3, 70);
	// Create the board
	Board *board = new Board(10,10, snakes, 3);

	board -> printBoard();

  /*
	main_game game;
	game.intro();
	game.info_player();
	game.level_play(1);

	getch();
	*/
	return 0;
}

