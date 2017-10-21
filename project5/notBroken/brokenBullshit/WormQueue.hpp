



#include "Worm.hpp"


using namespace std;


class WormQueue
{
private:
  int *wQueue;
  int front, rear;
  int MaxSize;
public:
  WormQueue(int max);
 
  void insert(Worm *item);
 
  void del();
