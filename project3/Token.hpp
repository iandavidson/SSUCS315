// Assignment : Project3
// File : Token.hpp
// Author : Ian Davidson
// Date  : Spring 2017

#ifndef __Token_hpp
#define __Token_hpp

#include <iostream>
#include <cstring>
#include <string>


using namespace std;

class Token
{
public:

  //enum is public because it can then be used freely in both classes, Token & Lex.
  enum element { OPENCURLY = '{', CLOSECURLY = '}', OPENBRACKET = '[', CLOSEBRACKET = ']', COMMA = ',' , COLON = ':', QUOTE =  '\'' };


    // variable elemToken represents a one-character token such as { and '.
    // To create such token, use the constructor that accepts a character.
  

    // variable valueTokenValue represents an atom -- a sequence of characters.
    // To create such a token, use the constructor that accepts a string.

    // To create an end-of-text token, create an instance of this
    // class using the contructor that doesn't take any arguments and
    // then, call function makeEndOfText() on that instance.  
  

  //constructors
  Token(): elemTokenValue('\0'), valueTokenValue(""), endOfText(false) {}
  Token(char c): elemTokenValue(c), valueTokenValue(""), endOfText(false) {}
  Token(std::string st): elemTokenValue('\0'), valueTokenValue(st), endOfText(false) {}

  void print();
  
  void makeEndOfText()  { endOfText = true; }

  //possible frequent unquoted strings
  bool isType()         { return valueTokenValue == "type"; }
  bool isParent()         { return valueTokenValue == "parent"; }
  bool isName()         { return valueTokenValue == "name"; }
  bool isPath()         { return valueTokenValue == "path"; }
  bool isChildren()     { return valueTokenValue == "children"; }
      
  bool isValue()        { return valueTokenValue != ""; }// for quoted strings
  std::string getValue() {return valueTokenValue; }
  
  bool isEndOfText()    { return endOfText; }
  
private:
  char elemTokenValue;
  std::string valueTokenValue;
  bool endOfText;
};

#endif
