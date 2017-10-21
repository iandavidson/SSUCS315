//Ian Davidson
//Cs315
//Project 5
//Spring 2017
//Game.cpp
#include "Game.hpp"

Game::Game(int row, int col)
{
  this->rows = row;
  this->cols = col;
  this->GameBoard = new Board(row, col);
  this->_GameOver = false;
  this->CurrentDirection = -1;
  startCurses();
}

void Game::updateScore()
{
  this->score = GameBoard->getWormSize() - 8;//game initially starts with 8 segments
  string s = to_string(score);

  //do cases for size of number
  if(score < 10){
    mvaddch(0, cols, s[0]);

  }
  else if(score < 100){
    mvaddch(0, cols, s[0]);
    mvaddch(0, cols+1, s[1]);
    
  } else if(score < 1000){
    mvaddch(0, cols, s[0]);
    mvaddch(0, cols+1, s[1]);
    mvaddch(0, cols+2, s[2]);
  } else {

    mvaddch(0, cols, s[0]);
    mvaddch(0, cols+1, s[1]);
    mvaddch(0, cols+2, s[2]);
    mvaddch(0, cols+3, s[3]);
  }

  refresh();
}

void Game::startCurses()
{
  initscr();     /* activate the curses */
  curs_set(0);/* do not display the cursor */
  clear();       /* clear the screen that curses provides */
  noecho();      /* prevent the input chars to be echoed to the screen */
  cbreak();      /* change the stty so that characters are delivered to the 
                    program as they are typed--no need to hit the return key!*/
}



void Game::startGame()
{
  startCurses();
  //display Board->vector in curses
  initialSetUp(GameBoard->getRows(), GameBoard->getCols());
  
}

void Game::initialSetUp(int rows, int cols)
{
  //curses works y,x
  move(0,0);
  addstr("Worm");
  move(0,cols - 8);
  addstr("score: ");// 7 chars so put score at
  move(0, cols);
  addstr("0");

  //setup boarder
  for(int j = 0; j < rows; j++)
    mvaddch(j+1, 0,'*');
  for(int k = 0; k < rows; k++)
    mvaddch(k+1, cols-1, '*');
  for(int l = 0; l < cols; l++)
    mvaddch(1, l, '*');
  for(int o = 0; o < cols; o++)
    mvaddch(rows, o, '*');

  //setup WormQueue on board
  mvaddch(1+ GameBoard->getWormHeadY() , GameBoard->getWormHeadX() ,'@');

  for(int q = 0; q < 7; q++ ){ 
    mvaddch(1+ GameBoard->getWormHeadY(), GameBoard->getWormHeadX() -1 - q, '0');
  }
  //place munchie with Correct Value
  mvaddch(1+ GameBoard->getMunchieY(), GameBoard->getMunchieX(), 48+ GameBoard->getMunchieValue());
  
  refresh();
}


void Game::convertInput(char c)
{
  if(c == 'h'){
    CurrentDirection = 2; //left direction
  }else if(c == 'j'){
    CurrentDirection = 1;//down direction
  }else if(c == 'k'){
    CurrentDirection = 0;//up direction
  }else if(c == 'l'){
    CurrentDirection = 3;//right direction
  }
  
}


void Game::giveInput(char input)
{//input can only be h,j,k,l

  int oldHX = GameBoard->getWormHeadX();
  int oldHY = GameBoard->getWormHeadY();
  int oldTX = GameBoard->getWormTailX();
  int oldTY = GameBoard->getWormTailY();

  
  convertInput(input);
  //pass a param & munchie hit
  bool hitMunchie = false;

  //  cout << "input: " << input << endl;
  //cout << "CurrentDirection " << this->CurrentDirection << endl;
  
  if(this->CurrentDirection != -1){
    //cout << "made it to movement call" << endl;
    if(!GameBoard->movement(CurrentDirection, hitMunchie)){//maybe pass an object w/ reference so we can see where munchie was placed. to update field
      _GameOver = true;
      return;
    }
  //change what needs to change in Curses window, depending on movement
  adjustMovement(oldHX, oldHY, oldTX, oldTY, hitMunchie);
  }
}

void Game::adjustMovement(int oldHeadX, int oldHeadY, int oldTailX, int oldTailY, bool placeMunch)
{
  //cout << "made it to adjustMovement() " << endl;
  //place new head '@'
  callMVChar( GameBoard->getWormHeadY(),GameBoard->getWormHeadX(),'@');
  //make old head location a '0'
  callMVChar( oldHeadY, oldHeadX, '0');
  if(placeMunch)
    callMVChar(GameBoard->getMunchieY(), GameBoard->getMunchieX(), 48 + GameBoard->getMunchieValue());

  if(!GameBoard->shouldWeGrow())
    callMVChar(oldTailY, oldTailX, ' ');
  
  updateScore();
  
  refresh();
}

void Game::callMVChar(int yVal, int xVal, char value)
{
  mvaddch(yVal +1, xVal, value);
}

void Game::terminateCurses()
{
  mvcur( 0, COLS - 1, LINES - 1, 0 );
  clear();
  refresh();
  endwin();
}
