// Assignment : Project4
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
  Token(): elemTokenValue('\0'), valueTokenValue(""), endOfText(false) {}
  Token(char c): elemTokenValue(c), valueTokenValue(""), endOfText(false) {}
  Token(std::string st): elemTokenValue('\0'), valueTokenValue(st), endOfText(false) {}

  void print();
  
  void makeEndOfText()  { endOfText = true; }


  char getElemValue();
  string getStringValue();
  
  bool isOpenCurly() { return elemTokenValue == element::OPENCURLY; }
  bool isCloseCurly() { return elemTokenValue == element::CLOSECURLY; }
  bool isOpenBracket() { return elemTokenValue == element::OPENBRACKET; }
  bool isCloseBracket() { return elemTokenValue == element::CLOSEBRACKET; }
  bool isComma() { return elemTokenValue == element::COMMA; }
  bool isColon() { return elemTokenValue == element::COLON; }
  bool isQuote() { return elemTokenValue == element::QUOTE; }
  //comma
  //colon
  //quote






  //possible frequent unquoted strings
  bool isType()         { return valueTokenValue == "type"; }
  bool isParent()         { return valueTokenValue == "parent"; }
  bool isName()         { return valueTokenValue == "name"; }
  bool isPath()         { return valueTokenValue == "path"; }
  bool isChildren()     { return valueTokenValue == "children"; }
  
  bool isFile()         { return valueTokenValue == "\'file\'"; }
  bool isDirectory()    { return valueTokenValue == "\'directory\'"; }

  bool isExpectedString();
  bool isValue()        { return valueTokenValue != ""; }// for quoted strings
  std::string getValue() {return valueTokenValue; }
  
  bool isEndOfText()    { return endOfText; }
  
private:
  char elemTokenValue;
  std::string valueTokenValue;
  bool endOfText;
};

#endif
