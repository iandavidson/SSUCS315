

#include "WormQueue.hpp"



WormQueue::WormQueue(int max)
{//value passed to this shit should be the Size of the R*C from board.hpp
  this->MaxSize = max;
  wQueue = new int [MaxSize];
  rear = front = -1;
}





void WormQueue::insert(Worm* item)
  {
    if ((front == 0 && rear == this->MaxSize -1) || (front == rear+1))
      {
	cout<<"Queue Overflow \n";
	return;
      }
    if (front == -1)
      {
	front = 0;
	rear = 0;
      }
    else
      {
	if (rear == MaxSize - 1)
	  rear = 0;
	else
	  rear = rear + 1;
      }
    wQueue[rear] = item ;
  }


void WormQueue::del()
{
  if (front == -1)
    {
      cout<<"Trying to delete with nothing here";
      return ;
    }
  cout<<"Element deleted from queue is : " << wQueue[front]<<endl;
  if (front == rear)
    {
      front = -1;
      rear = -1;
    }
  else
    {
      if (front == MAX - 1)
	front = 0;
      else
	front = front + 1;
    }
}
