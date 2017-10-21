
#ifndef MUNCHIE_HPP
#define MUNCHIE_HPP

#include "Cell.hpp"
#include <stdlib.h>
#include <time.h>


class Munchie : public Cell
{
public:

  Munchie(char c): Cell(c) {}
  virtual bool objectWillBreakGame() {return false;}
  virtual bool isMunchie() {return true; }
  void setMunchieValue(int v) { value = v;}
  int getMunchieValue() { return value; }
  Munchie * MunchMake();

private:

  char valueHelper(int x) {return '0' + x;}
  int value;

};

#endif
