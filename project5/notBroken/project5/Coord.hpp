
#ifndef COORD_HPP
#define COORD_HPP


#include <iostream>

using namespace std;


class Coord
{
public:
  enum DirType { UP = 0, DOWN = 1, LEFT = 2, RIGHT = 3}; 
  //con
  Coord(int yVal, int xVal);
  //destruct

  Coord *CopyCoord(int dir);
  
  void setX(int val) { x = val;}
  void setY(int val) { y = val;}
  int x;
  int y;
  
  Coord operator = (const Coord & otherCoord);
  bool operator == (const Coord &otherCoord);

  int calcIndex(int numCols) ;
};


#endif
