#define WORMHEAD_HPP
#ifndef WORMHEAD_HPP


#include "Worm.hpp"
#include "Cell.hpp"

class WormHead : public Worm
{
public:
  WormHead() : Worm('@') {}
  virtual bool isWormHead() { return true;}
};




#endif
