 /*  Points.cpp

 * Clement Nyanhongo

 * Module with the Points which will be used in the maze for
 * The snakes and the ladders
 */

#include <iostream>
#include "Points.h"
using namespace std;

Points :: Points(){
   S1 = NULL;
   S2 = NULL;
   L1 = NULL;
   L2 = NULL;
}

//constructor for board coordinates based on the difficulty level
Points :: Points(int x) {
  if (x == 0) {    // lowest level
    S1 = new int [6];
    S2 = new int [6];
    L1 = new int [8];
    L2 = new int [8];
    // populate coordinates for ladders
    int x[8] = {3, 23, 35, 45, 9, 17, 8, 26};
    int y[8] = {7, 27, 38, 48, 29, 39,31, 42};
    for (int i=0; i<8; i++) {
      L1[i]=x[i];
      L2[i]=y[i];
    }
    // populate coordinates for snakes
    int x2[6] = {6, 16, 43, 46, 41, 10};
    int y2[6] = {2, 11, 37, 28, 33, 15};
    for (int i=0; i<6; i++) {
      S1[i]=x2[i];
      S2[i]=y2[i];
    }
  }
  else if (x == 1) {  // intermediate level maze
    S1 = new int [8];
    S2 = new int [8];
    L1 = new int [6];
    L2 = new int [6];
    // populate coordinates for ladders
    int x [6] = {83, 55, 75, 9, 17, 26};
    int y [6] = {87, 58, 78, 29, 59, 70};
    for (int i= 0; i< 6; i++) {
      L1[i]= x[i];
      L2[i]= y[i];
    }
    // populate coordinates for snakes
    int x2 [8] = {66, 16, 73, 98, 99, 90, 80, 23};
    int y2 [8] = {62, 11, 68, 95, 57, 61, 43, 5};
    for (int i= 0; i< 8; i++) {
      S1[i]= x2[i];
      S2[i]= y2[i];
    }
  }
  else {    // highest level
    S1 = new int [15];
    S2 = new int [15];
    L1 = new int [9];
    L2 = new int [9];
    // populate coordinates for small snakes
    int x [15] = {87, 58, 78, 93, 10, 129, 59, 100, 132, 67, 148, 91, 120, 143,95};
    int y [15] = {83, 55, 75, 88, 5, 109, 17, 36, 69, 47, 63, 72, 61, 4, 19};
    for (int i= 0; i< 15; i++) {
      S1[i]= x[i];
      S2[i]= y[i];
    }
    // populate coordinates for small ladders
    int x2 [9] = {62, 11, 68, 135, 115, 57, 66, 43, 5};
    int y2 [9] = {66, 16, 73, 139, 121, 119, 90, 103, 95};
    for (int i= 0; i< 9; i++) {
      L1[i]= x2[i];
      L2[i]= y2[i];
    }
    }
  }

  Points :: ~Points(){
    delete(S1);
    delete(S2);
    delete(L1);
    delete(L2);
  }

