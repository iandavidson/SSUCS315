//Ian Davidson
//Cs315
//Project 5
//Spring 2017
//Board.hpp 


#ifndef BOARD_HPP
#define BOARD_HPP

#include "WormQueue.hpp"
#include "Coord.hpp"
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

 class Board{
public:

  enum dirType{ UP, DOWN, LEFT, RIGHT };

  
  Board(int row, int column); 
  void destroy();

  int getRows() { return this->rows;}
  int getCols() { return this->cols;}

  bool movement(int dirType, bool &hitMunchie);
   
  void printVector();
  
  WormQueue *getWorm() { return worm; }
  vector <int>getCB() { return CellBuffer; }
  Coord **getFP() {return FP;}
  int getWormSize() { return worm->getWormLength(); }// call to update score

  //we need destructors for GB, WormQueue, FreeQueue

   //accessors needed for the calling class to spit out game information
   int getMunchieX() { return munchieCoord->x; }
   int getMunchieY() { return munchieCoord->y; }
   int getMunchieValue() { return currentMunchieValue; }
   int getWormHeadX() { return worm->getFront()->x; }
   int getWormHeadY() { return worm->getFront()->y; }
   int getWormTailX() { return worm->getRear()->x; }
   int getWormTailY() { return worm->getRear()->y; }
   bool shouldWeGrow() { return munchLax > 0; }

  WormQueue *worm;

   
private:

  vector <int> CellBuffer; //acts as the 2D ARRAY, access one below by [i] + cols


  
  void initDataStructs();
  void assignVectorFree(int r, int c);
  void reassignCoordinateHead(int indexOfToBeReplaced);//refers to the CellBuffer
  
  void setNewMunchieIndex();
  
  //function will manipulate FP[] pull int index out and repalce it w/ a munchie in "grid"
  void freePoolMunchieSwapper(int UnswappedFreeIndex, int munchieValue);

  int munchLax;//how many net segments we still needa grow
  Coord * munchieCoord;
  int currentMunchieValue; 
  
  int rows;
  int cols;
  
  
  
  int lastFreeIndex; //refers to FP  
  Coord ** FP;

};


#endif
