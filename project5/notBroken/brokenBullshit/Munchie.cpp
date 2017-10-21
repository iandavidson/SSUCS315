
#include "Munchie.hpp"


Munchie *Munchie::MunchMake()
{
  srand(time(NULL)); //initalize random seed
  int x = rand() % 9 + 1;
  char number = valueHelper(x);
  Munchie *munch = new Munchie(number);
  munch->setMunchieValue(x);
  return munch;
}
