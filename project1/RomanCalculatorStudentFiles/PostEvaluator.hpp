// Assignment : Project 1
// File : PostEvaluator.cpp
// Author : Ian Davidson
// Date  : Spring 2017

#ifndef _POSTEVALUATOR_HPP
#define _POSTEVALUATOR_HPP

#include <vector>
#include "Token.hpp"
#include "Number.hpp"
#include <cctype>
#include <iostream>

using namespace std;


class PostEvaluator
{
public:

  //constructor
  PostEvaluator() {/*stub nub tryna watch flub-ber*/}
  
  //destructor
  ~PostEvaluator();//stub b/c nothing defined in heap

  string evaluate(vector<Token*> postfix);

  //  int applyOperator(Token num1, Token num2, Token operate);
  int applyOperator(int leftValue, Token* num2, Token* operate);//num1 should be int from leftValue
  
  
private:

  // not really any privates



};


#endif
