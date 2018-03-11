/* Clement Nyanhongo
 *
 * Module with the driver Program
 */
#include <iostream>
#include "utils/Board.h"
#include "utils/Snake.h"
#include "utils/Ladder.h"

using namespace std;

int main(){

  //Create snakes
	Snake *snakes [3];
	snakes[0] = new Snake(15,3);
	snakes[1] = new Snake(27, 9);
	snakes[2] = new Snake(95, 43);

	//Create Ladders
	Ladder *ladders [3];
	ladders[0] = new Ladder(5,10);
	ladders[1] = new Ladder(12,40);
	ladders[2] = new Ladder(3, 70);
	// Create the board
	Board *board = new Board(10,10, snakes, ladders,  3, 3);

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

