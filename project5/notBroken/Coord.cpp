
#include "Coord.hpp"

Coord::Coord(int y, int x)
{//called with (row, col) format
  this->x = x;
  this->y = y;
}


Coord * Coord::CopyCoord(int dir)
//this function will return a Coord * new obj with relative xy vals to this->instance based off param "dir"
{//must be called with 0-3 value in dir or else problems occur
  Coord *newPoint = new Coord(this->y, this->x);
  if(dir == DirType::UP){
    newPoint->setY(newPoint->y - 1);
  }else if(dir == DirType::DOWN){
    newPoint->setY(newPoint->y + 1);
  }else if(dir == DirType::LEFT){
    newPoint->setX(newPoint->x -1);
  }else if(dir == DirType::RIGHT){
    newPoint->setX(newPoint->x + 1);
  }
  //  cout << "new coordinate made" << endl;
  //cout << "X:  " << newPoint->x << endl;
  // cout << "Y:  " << newPoint->y << endl;
  
  return newPoint;
}


Coord Coord::operator = (const Coord & otherCoord)
{
  if (this == &otherCoord)
    return * this;

  x = otherCoord.x;
  y = otherCoord.y;
    
  return otherCoord;
}


bool Coord::operator == (const Coord & otherCoord)
{
  if(this->x == otherCoord.x && this->y == otherCoord.y)
    return true;
  return false;

}

int Coord::calcIndex(int numCols)
{
  //y * cols + x
  int index = y * numCols + x;
  //  cout << "cols " << numCols << endl;
  //cout << "X:  " << x << endl;
  //cout << "Y:  " << y << endl;
  //cout << "index: " << index << endl;

  return index;

}
