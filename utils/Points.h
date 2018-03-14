/* Points.h

 * Clement Nyanhongo

 * Module with the Points which will be used in the maze for
 * The snakes and the ladders
 */

#include <iostream>

using namespace std;

class Points{
 public:
  // Coordinates for the board (start, end points)
  int * S1;
  int * S2;
  int * L1;
  int * L2;
  //constructor for board coordinates based on the difficulty level
  Points();
  Points(int x);
  ~Points();
};

