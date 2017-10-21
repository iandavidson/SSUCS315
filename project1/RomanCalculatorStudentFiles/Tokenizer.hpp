// Assignment : Project 1
// File : Tokenizer.cpp
// Author : Ian Davidson
// Date  : Spring 2017
#ifndef _TOKENIZER_CPP
#define _TOKENIZER_CPP



#include <string>
#include <vector>
#include <algorithm>
#include "Token.hpp"
#include <cctype>

using namespace std;

class Tokenizer {

public:
  Tokenizer ( string expr) {expression = expr;}

  ~Tokenizer();
  //destructor
  
  
  vector<Token*>   &Tokenize();
  Token getIdentifier();

  
private:

  bool isSymbol(char c);//char is turned into an instance of Token, Token then added to vector "tokens"
  int isRoman(string expCopy,int i); // same as above but is passed a roman numeral
  
  string expression;
  vector<Token*> tokens;
  Token*  identToken;//holds 
};

#endif
