
#ifndef WALL_HPP
#define WALL_HPP

#include "Cell.hpp"


class Wall : public Cell{
public:
  Wall(): Cell('X') {}
  virtual bool objectWillBreakGame() { return true;}
  virtual bool isWall() {return true;}
};


#endif
