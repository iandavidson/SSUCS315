
#ifndef WORMBODY_HPP
#define WORMBODY_HPP

//#include "Worm.hpp"
#include "Cell.hpp"


class WormBody : public Worm
{
public:
  WormBody() : Worm('0') {}
  virtual bool isWormBody() { return true; }
};




#endif
