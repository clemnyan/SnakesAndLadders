/* Points.cpp

 * Clement Nyanhongo

 * Module with the Points which will be used in the maze for
 * The snakes and the ladders
 */

#include <iostream>
using namespace std;

//constructor for board coordinates based on the difficulty level
Points :: Points(int x) {
  if (x == 0) {    // small level
    S1 = new int [2];
    S2 = new int [2];
    sS1 = new int [3];
    sS2 = new int [3];
    L1 = new int [4];
    L2 = new int [4];
    sL1 = new int [4];
    sL2 = new int [4];
    // populate coordinates for small ladders
    sL1 = {3, 23, 35, 45};
    sL2 = {7, 27, 38, 48};
    // populate coordinates for large Ladders
    L1 = {9, 17, 8, 26};
    L2 = {29, 39,31, 42};
    // populate coordinates for small snakes
    sS1 = {6, 16, 43};
    sS2 = {2, 11, 37};
    // populate coordinates for large snakes
    S1 = {49, 41};
    S2 = {29, 31};
  }
  else if (x == 1) {  // intermediate level maze
    S1 = new int [4];
    S2 = new int [4];
    sS1 = new int [4];
    sS2 = new int [4];
    L1 = new int [3];
    L2 = new int [3];
    sL1 = new int [3];
    sL2 = new int [3];
    // populate coordinates for small ladders
    sL1 = {83, 55, 75};
    sL2 = {87, 58, 78};
    // populate coordinates for large Ladders
    L1 = {9, 17, 26};
    L2 = {29, 59, 70 };
    // populate coordinates for small snakes
    sS1 = {66, 16, 73, 98};
    sS2 = {62, 11, 68, 95};
    // populate coordinates for large snakes
    S1 = {99, 90, 80, 23 };
    S2 = {57, 61, 43, 5};
  }
  else {    // highest level
    S1 = new int [5];
    S2 = new int [5];
    sS1 = new int [10];
    sS2 = new int [10];
    sL1 = new int [5];
    sL2 = new int [5];
    L1 = new int [4];
    L2 = new int [4];
    // populate coordinates for small snakes
    sS1 = {87, 58, 78, 93, 10};
    sS2 = {83, 55, 75, 88, 5};
    // populate coordinates for large snakes
    S1 = {129, 59, 100, 132, 67, 148, 91, 120, 143,95};
    S2 = {109, 17, 36, 69, 47, 63, 72, 61, 4, 19};
    // populate coordinates for small ladders
    sL1 = {62, 11, 68, 135, 115};
    sL2 = {66, 16, 73, 139, 121};
    // populate coordinates for large ladders
    L1 = {57, 66, 43, 5};
    L2 = {119, 90, 103, 95};
    }
  }

  Points :: ~Points(){
    delete(S1);
    delete(S2);
    delete(sS1);
    delete(sS2);
    delete(L1);
    delete(L2);
    delete(sL1);
    delete(sL2);
  }

