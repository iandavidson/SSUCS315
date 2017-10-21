#ifndef WORM_HPP
#define WORM_HPP

#include "Cell.hpp"

class Worm : public Cell
{
public:
  //dont make instances of this
  Worm(char c) : Cell(c){}
  virtual bool objectWillBreakGame() {return true;}
  virtual bool isWormType() { return true; }
};



#endif
