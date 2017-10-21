//Ian Davidson
//Cs315
//Project 5
//Spring 2017
//WormQueue.hpp 

#ifndef WORMQUEUE_HPP
#define WORMQUEUE_HPP


#include "Coord.hpp"


using namespace std;


class WormQueue
{
public:
  WormQueue(int max);
  Coord **  getWQ() { return wQueue; }
  //  void insert(Coord * item); 
  void Move(bool fullTummy, int Direction); // call with (munchLax > 0); then do: munchLax--;
  void Move(bool fullTummy, Coord *munchie); //overloaded move call where we are running into a munchie
  Coord * getFront() { return wQueue[front-1]; }
  Coord * getRear() { return wQueue[rear]; }


  //  WormQueue *get
  
  void makeInitial(Coord * item);
  int getSize() { return MaxSize;}
  int getWormLength() { return front - rear; } //called by worm in BoardClass to get/update score
  
private:

  void deleteRear();
  void addFront(Coord * item);
  Coord ** wQueue;
  int front, rear;
  int MaxSize;


};


#endif
