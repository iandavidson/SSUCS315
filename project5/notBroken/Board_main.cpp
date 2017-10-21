
#include <string>
#include "Board.hpp"
#include <iostream>

using namespace std;

int main(){
  Board *board = new Board(15, 15);
  board->printVector();
  /*
  board->movement(0);

  cout << endl << endl << endl;
  cout << "move up" << endl;
  
  board->printVector();
  */

  
  char fishass = ' ';
  cin >> fishass;
  int fishguts = atoi(&fishass);
  

  bool fuckthisbullshit = false;
  while (true){

    //movement returns false if game should end
    fishguts = atoi(&fishass);
    if(!board->movement(fishguts, fuckthisbullshit))
      break;
    board->printVector();
    cin >> fishass;    
    
  }
  
  return 0;
}

