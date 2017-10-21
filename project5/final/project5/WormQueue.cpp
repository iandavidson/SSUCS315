//Ian Davidson
//Cs315
//Project 5
//Spring 2017
//WormQueue.cpp 


#include "WormQueue.hpp"



WormQueue::WormQueue(int max)
{//value passed to this shit should be the Size of the R*C from board.hpp
  this->MaxSize = max;
  wQueue = new Coord * [MaxSize];
  rear = front = 0;
}


void WormQueue::makeInitial(Coord * head)
{//gets called when default board is being made.
  //we would like the param to be at the last occupied space in the WQ, so getFront() returns "head", etc. 
  int nextY = head->y;
  int nextX = head->x -7;  

  Coord *point = new Coord(nextY, nextX);
  addFront(point);

  for(int i = 1; i < 7; i++){
    point = new Coord(nextY, nextX + i);
    addFront(point);
  }

  addFront(head);

}

void WormQueue::deleteRear()
{
  if(rear == MaxSize)
    rear = 0;
  
  delete wQueue[rear];
  rear++;
}

void WormQueue::addFront(Coord *item)
{
  if(front == MaxSize)
    front = 0;
  wQueue[front] = item;
  front++;
}


void WormQueue::Move(bool grow, int Direction)
{ //Direction : UP=0, DOWN=1, LEFT=2, Right=3
  //  cout << "value of front: rear: " << this->front << "   " << this->rear << endl;
  if(!grow){
    this->deleteRear();
    //if the worm needs to grow we dont delete rear so # of segments increase
  }
  this->addFront(getFront()->CopyCoord(Direction));
  //cout << "value of front: rear: " << this->front << "   " << this->rear << endl;


}

void WormQueue::Move(bool grow, Coord * munchie)
{
  if(!grow){
    this->deleteRear();
  }
  this->addFront(munchie);
  
}
