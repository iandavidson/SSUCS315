//Ian Davidson
//Cs315
//Project 5
//Spring 2017
//Game.hpp 

#ifndef GAME_HPP
#define GAME_HPP

#include <curses.h>
#include "Board.hpp"
#include <iostream>
#include <string>

using namespace std;

class Game
{
public: 
  
  Game(int row, int col);
  void updateScore(); 
  void startGame();
  void startCurses();
  void terminateCurses();
  void giveInput(char c);//input from caller
  void  convertInput(char c);
  bool isGameOver() { return _GameOver;}
  void initialSetUp(int rows, int cols);
  int getScore() { return score; }
  void adjustMovement(int oldHeadx, int oldHeady, int oldTailx, int oldTaily, bool placeMunch);
  void callMVChar(int yVal, int xVal, char value);
    
private:
  int rows;
  int cols;
  int CurrentDirection; //use: up = 0, down = 1, left =  2, right = 3
  int score;
  Board *GameBoard;
  bool _GameOver;
};



#endif
