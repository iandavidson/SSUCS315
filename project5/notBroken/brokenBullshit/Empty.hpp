
#ifndef EMPTY_HPP
#define EMPTY_HPP


#include "Cell.hpp"


class Empty : public Cell
{
public:
  Empty(): Cell(' ') {}
  virtual bool objectWillBreakGame() { return false;} //if a worm head ran into this sub-def of cell then
  //  it is okay
  void setFreePoolIdx(int idx) {FreePoolIdx = idx;}
  int getFreePoolIdx() {return FreePoolIdx;}

private:
  int FreePoolIdx;

};

#endif
