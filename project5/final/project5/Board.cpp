/*
Ian Davidson
CS315 Project5
Spring 2017 
Board.cpp
*/

#include "Board.hpp"


Board::Board(int row, int col)
{

  this->rows = row;
  this->cols = col;
  this->lastFreeIndex = 0;
  this->munchLax = 0;
  int FreeSize = (rows -1)*(col - 1);
  Coord ** fishStick = new Coord * [FreeSize];
  this->FP = fishStick;
  WormQueue * fishAss = new WormQueue(FreeSize);
  this->worm = fishAss;
  initDataStructs();
}

void Board::assignVectorFree(int row, int col)
{
  this->CellBuffer.push_back(this->lastFreeIndex);
  Coord *yxVal = new Coord(row, col);
  FP[lastFreeIndex] = yxVal;
  this->lastFreeIndex++;
  return;
}


void Board::initDataStructs()
{  
  bool wormPlaced = false;
  //place head & 7 body segments in exact middle of grid
  for(int i = 0; i < this->rows; i++)
    {
      if(i == 0 || i == rows-1)
	{
	  for(int j = 0; j < this->cols; j++)
	    {
	      CellBuffer.push_back(-1);
	    }
	}else if(i == this->rows/2 && ! wormPlaced)
	{
	  
	  int count = 7; //this case is only for the center row where worm is placed
	  for(int l = 0; l < this->cols; l++)
	    {

	      if(l == 0 || l == cols-1){//boardercase
		CellBuffer.push_back(-1);
	      }
	      
	      //we need the head on the right side
	      else if(l >= cols/2 - 5 && l <= cols/2 + 2)
		{
		  //make instance of worm, push in worm queue
		  if(count == 0){
		    
		    //wormhead
		    Coord *point = new Coord(i, l);
		    this->worm->makeInitial(point);
		    //we need to call WormQueue::makeInitial

		    CellBuffer.push_back(-1);
		  }else{
		    //wormBody		    

		    //cout << "X:  Y:  "<< l << "  " << i << endl;
		    //cout << "lastFreeINdex value rn: " <<  lastFreeIndex << endl;
		    CellBuffer.push_back(-1);
		    count--;
		    
		  }
		}
	      else
		assignVectorFree(i, l);
	      //insert empty here^
	    }
	  wormPlaced = true;
      }
      else{
	for(int k = 0; k < this->cols; k++)
	  {
	    if(k == 0 || k == cols-1)//boarder case
	      {
       		CellBuffer.push_back(-1);
		
	      }else
	      {//empty case
		
		assignVectorFree(i, k);
	      }
	  }
      }
    }
  
  
  //  cout << "lastFreeIndex: (rows-2) * (cols-2): " << lastFreeIndex << endl;
  //FP and CB are made we needa make that worm
  
  //call funct to get random number value to place initial munchie
  setNewMunchieIndex();
  
}

void Board::destroy()
{

}

void Board::printVector()
{
  int currentIndex = 0;
  for(int i = 0; i < rows; i++){
    for(int j = 0; j < cols; j++){
      if(CellBuffer[currentIndex] < 0){
	cout << CellBuffer[currentIndex] << "  ";
      }else if(CellBuffer[currentIndex] < 10){
	cout << CellBuffer[currentIndex] << "   ";
      }else if(CellBuffer[currentIndex] < 100){
	cout << CellBuffer[currentIndex] << "  ";
      }else
	cout << CellBuffer[currentIndex] << " ";
      currentIndex++;
    }
    cout << endl;
  }

}

bool Board::movement(int dir, bool &hitMunchie) //returns false is direction will break game
{
  Coord *head = worm->getFront();
  //head's index in vector is [y *col + x]
  int headIdx = head->calcIndex(this->cols);
  int relativeIntValue;
  int relativeIndex;

  
  //  cout << "headIndex" << headIdx << endl;
  //  cout << "dir : " << dir << endl;

  if(dir == dirType::UP){
    relativeIndex = headIdx - cols;
    relativeIntValue = CellBuffer[relativeIndex];
  }else if(dir == dirType::DOWN){
    relativeIndex = headIdx + cols;
    relativeIntValue = CellBuffer[relativeIndex];
  }else if(dir == dirType::LEFT){
    relativeIndex = headIdx - 1;
    relativeIntValue = CellBuffer[relativeIndex];
  }else if(dir == dirType::RIGHT){
    relativeIndex = headIdx + 1;
    relativeIntValue = CellBuffer[relativeIndex];
  }

  bool needToSetMunchie = false;

  //  cout << "MunchLax val: " << munchLax << endl;
  //cout << "relativeIndex: " << relativeIndex << endl;
  //cout << "relativeINdexintValue : " << relativeIntValue << endl;

  
  if(relativeIntValue < 0){
    if(relativeIntValue == -1){ //thinking about dx between wall vs worm, worm -11
      //  cout << "the worm has eaten the wall or itself" << endl;
      return false;//means game should end
    }//otherwise we just ran into a munchie
    this->munchLax += (relativeIntValue * -1) -1;
    needToSetMunchie = true;
    hitMunchie = true;
    //    cout << "munchie has been munched upon" << endl;
  }

  //we have to get x and y of the worm rear before move, so we have the for later
  int ButtX = worm->getRear()->x;
  int ButtY = worm->getRear()->y;
  //cout << "wormButt to be pickedup: X: Y: " << ButtX << "  " << ButtY << endl;
     
  //fix data structs which changed bc of move
  //  worm->Move(munchLax > 0, dir);
  
  //this chunk adjusts the CB, FP, after a new worm peice successefully is placed
  if(!needToSetMunchie){//means we didnt just run into a munchie
    worm->Move(munchLax > 0, dir);
    reassignCoordinateHead(relativeIndex);
    //cout << "didnt hit munchie" << endl;
  }else{// case: if the relativeIndex refers to a munchie 
    worm->Move(munchLax > 0, munchieCoord);//Coord @ this->munchieCoord should be new head of worm
    CellBuffer[munchieCoord->calcIndex(cols)] = -1;// make the board realize the munch location is on the board.
    setNewMunchieIndex();
    //place/set new munchie on board.
  }

  //munchLax == 0 means the worm wont grow this time
  if (munchLax == 0){//refers to rear of worm     
    CellBuffer[ButtY *cols + ButtX] = lastFreeIndex;
    Coord *point = new Coord(ButtY, ButtX);
    FP[lastFreeIndex] = point; //coordinate, 
    lastFreeIndex++;
  }
  
  //set new munchie on field by calling setNewMunchieIndex()
  //  if(needToSetMunchie)
  //  setNewMunchieIndex();
	     
  if(munchLax > 0)
    munchLax--;
  return true;
}


void Board::setNewMunchieIndex()
//works for FP
{
  int Index;
  int munchieValue;
  srand(time(NULL));
  Index = rand() % this->lastFreeIndex;
  munchieValue = (rand() % 9) + 1;
  this->currentMunchieValue =  munchieValue;
  freePoolMunchieSwapper(Index, munchieValue);
  return;
}


void Board::freePoolMunchieSwapper(int Index, int munchieValue)
{//  
  munchieCoord  = FP[Index];
  int x = munchieCoord->x;
  int y = munchieCoord->y;
  
  munchieValue = (munchieValue * -1) -1;
  //cout << "munchie placed at FP index: " << Index << endl;
  CellBuffer[y*cols + x] = munchieValue;
  FP[Index] = FP[lastFreeIndex-1];
  int newX = FP[Index]->x;
  int newY = FP[Index]->y;
  CellBuffer[newY*cols + newX] = Index;
  
  lastFreeIndex--;

  //toBeMunchie = NULL;
  return;
}

void Board::reassignCoordinateHead(int relativeIndex)//index of CellBuffer
//we need to reassign the x and y of CB[relativeIndex] to sit at CB[lastFreeIndex-1]//where the last elem is
{
  //re assign this object FP[CellBuffer[relativeIndex]]'s x and y  =  FP[CellBuffer[lastFreeIndex-1]]'s location
  FP[CellBuffer[relativeIndex]]->setX(FP[lastFreeIndex-1]->x);
  FP[CellBuffer[relativeIndex]]->setY(FP[lastFreeIndex-1]->y);
  //set CB[FP[CB[relativeIndex]]]->x][FP[CB[relativeIndex]]->y] = lastFreeIndex-1
  int newIndex = FP[CellBuffer[relativeIndex]]->calcIndex( this->cols);

  CellBuffer[newIndex] = CellBuffer[relativeIndex];
  CellBuffer[relativeIndex] = -1;
  delete FP[lastFreeIndex-1];
  //FP[lastFreeIndex-1] = NULL;
  lastFreeIndex--;
  
}
