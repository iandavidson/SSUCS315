// Assignment : project3
// File : Lex.cpp
// Author : Ian Davidson
// Date  : Spring 2017      
#ifndef __LEX_HPP
#define __LEX_HPP

#include "Token.hpp"

#include<iostream>
#include<cstring>


class Lex 
{
public:
  Lex(std::string);
  Token getToken();
  void ungetToken();
  
private:
  std::string inputToTokenize;
  unsigned int whereToStart;
  bool haveAnUngottenToken;
  Token lastToken;
  std::string lastNameToken;
  
  int skipWhiteSpaces();
  Token parseElement();//non quoted string
  Token parseValue();//quoted string
  bool isValue( char value );
};

#endif
