// Assignment : Project 1
// File : PostEvaluator.cpp
// Author : Ian Davidson
// Date  : Spring 2017


#include "PostEvaluator.hpp"


string PostEvaluator::evaluate(vector<Token*> postfix)
{
  
  //iterate through using checks from token class.

    //find operator leftmost, then check 2 behind to confirm theyre both RN s
  //infix   (X + X) * V
  //postfix  X X + V * -> XX V * -> C
  uint index = 0;
  Token *leftToken =new Token(postfix[index]->getDigitNumber());
  index++;

  postfix[index]->print();

  cout << endl;
  
  Number leftNum = leftToken->getDigitNumber();
  int leftValue = leftNum.intValue(); 
  
  while (index < postfix.size()-1){

       cout << "leftvalue: " << leftValue << endl;
    //get right value
       cout << "rightvalue: ";
       postfix[index]->print();
       cout << endl;
    //get operator
       cout << "operator: " ;
       postfix[index+1]->print();
       cout << endl;
    //apply operator
    leftValue = applyOperator(leftValue, postfix[index], postfix[index+1]);//add params
      
    index += 2;

    if ( index < postfix.size()-1)
      break;//if last iteration of while loop doesnt break here, segfault occurs
    
    leftToken->setDigitNumber(postfix[index]->getDigitNumber());
    leftNum = leftToken->getDigitNumber();
    leftValue = leftNum.intValue();
    
      //increment index by 2
    
    //find instance of (RNum, RNum, Oper), call apply operator
       //pushback return from apply operator

    //reassignment of variables


  }

  //leftValue -> romanValue->return
  Number sum = leftValue;

  delete leftToken;
  
  return sum.romanValue();
  
  
}




int PostEvaluator::applyOperator(int leftVal, Token* num2, Token* operate)
//num1 and num2 are RomanNumbers, operate is an operator char
{
  //create instances of Number, convert to int value
  Number rightNum = num2->getDigitNumber();
  int rightVal = rightNum.intValue();

  if (operate->isMultiplicationOperator()){
    return leftVal * rightVal;

  }else if (operate->isAdditionOperator()){
    return leftVal + rightVal;

  }else if (operate->isSubtractionOperator()){
    return leftVal - rightVal;

  }else if (operate->isModuloOperator()){
    return leftVal % rightVal;

  }else if (operate->isDivisionOperator())
      return leftVal / rightVal;

  return 0;
}

PostEvaluator::~PostEvaluator()
{
  //stub
  //int end = stack.size();
  //for (int i = 0; i < end; i++)
  //delete stack[i];

}
