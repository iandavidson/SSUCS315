//Ian Davidson
//Cs315
//Project 5
//Spring 2017
//screen.cpp


//#include<curses.h>
#include "getChar.hpp"
#include "Game.hpp"

#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>

//void startup( void );
//void terminateCurses( void );

using namespace std;

//call with a ./screen.x <rows> <columns>
int main(int argc, char * argv[])
{
  if(argc > 3 || argc < 3)
    {
      std::cerr << "./screen.x <rows> <cols>" << std::endl;
      exit(1);
    }

  int  row, column;
  
  row = atoi(argv[1]);

  if(row > 25 || row < 10)
    {
      std::cerr << "bad input, exiting, row's value is: " << row << std::endl;
      exit(1);
    }
    
  column = atoi(argv[2]);

  if(column > 80 || column < 10)
    {
      std::cerr << "bad input, exiting, column's value is: " << column << std::endl;
      exit(1);
    }
      


  std::string s = "";
  cout << "Controls: " << endl << "Left: h" << endl;
  cout << "Right: l" << endl << "Down: j " << endl;
  cout << "Up: k" << endl;
  cout << " Try not to eat yourself or the walls" << endl;
  
  //  Board *board = new Board(row, column);
  // Make instance of Game here
  Game *game = new Game(row, column);

  std::cout << "enter an \'s\' then press return to start game" << std::endl;
  while(s != "s"){
    std::cin >> s;
  }


  game->startGame();
  //Game now is handling curses

  char c;
  
  //we want a while loop right here getting input from user through getChar();
  while(!game->isGameOver()){
    //    game->giveInput(get_char());
    c = get_char();
    game->giveInput(c);

  }

 
  game->terminateCurses();
  int score = game->getScore();
  cout << "GameOver, dont eat a wall or yourself in real life" << endl;
  cout << "Your score was: " << score << endl;
  cout << "Ian's high score was: " << score + 1 << endl;
  return 0;
}  

