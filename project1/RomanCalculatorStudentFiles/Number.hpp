// Assignment : Project 1
// File : Number.hpp
// Author : Ian Davidson
// Date  : Spring 2017
#ifndef NUMBER_HPP
#define NUMBER_HPP

#include <string>

using namespace std;

class Number {
public:
  Number( int n )         { intNumber = n; }//strNumber == NULL, if only this called
  Number( string s ) { strNumber = s; intNumber = -1;}

  // is the Roman number that is stored in "strNumber" a legal Roman number?
  bool isALegalRomanNumber();

  // Return the int value of this Roman number.  If the instance was
  // created by having used a decimal number, just return it.
  // Otherwise, convert "strNumber" to its decimal counterpart and
  // return it.  Note that you may already have converted it when the
  // user called "isALegalRomanNumber".
  int intValue();

  // convert "intNumber" to its Roman counterpart and return it as a string.
  string romanValue();

private:
  
  string strNumber;
  int intNumber;

  
  //enum Numeral{I = 1, V = 5, X = 10, L = 50, C = 100, D = 500, M = 1000};

  //can evaluate a single tokenized roman chunk
  int evaluateRomanNumber( string chunk);

  //turn a #0-10, with 3 roman chars to represent, return string of the 
  string assignRomanPart( int n, string one, string five, string ten); 
			  
  
};


#endif

