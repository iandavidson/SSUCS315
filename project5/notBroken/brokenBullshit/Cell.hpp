//Ian Davidson
//CS315 Project5
//
#ifndef CELL_HPP
#define CELL_HPP


//doesnt need a cpp impl. file

//note this class is an abstract class, meaning: only call this constructor through
//subclass's constructor.

//using namespace std;

class Cell{
public:
  
  Cell(char v): valueToDisplay(v){}
  void setIndex(int i) {this->index = i;}
  int getIndex() {return index;}
  //void setYX(int y, int x) { xFieldValue = x; yFieldValue = y;} //give me fucking r ,c
  //void setX(int x) { xFieldValue = x; }
  //int getX() { return xFieldValue; }
  //void setY(int y) { yFieldValue = y; }
  //  int getY() { return yFieldValue; }
  
  virtual bool objectWillBreakGame() = 0; //pure af

  virtual bool isWall() { return false; }
  virtual bool isEmpty() { return false; }
  virtual bool isMunchie() { return false;}
  virtual bool isWormType() { return false; }
  virtual bool isWormBody() { return false; }
  virtual bool isWormHead() { return false; }
  
private:


  
  char valueToDisplay;
  int index;
  //  int xFieldValue;//refer to index
  //int yFieldValue;// "        "
  
};


    
#endif
