/*                                                                                  
Assignment : project4                                                                
Author: Ian Davidson                                                                     
File: Lex.cpp                                                                            
Date : Spring 2017                                                                       
*/



#include "Token.hpp"

//print is the only value function of Token which requires more than one line of implementation
void Token::print()
{
  //dont do shit if its the end of text bc theres no reason
  if (this->isEndOfText())
    return;
  
  if (elemTokenValue == '\0'){ //string case (quoted and unquoted)
    cout << valueTokenValue << endl;
    return;
  }
  
  cout << elemTokenValue << endl; //single character case

}

bool Token::isExpectedString()
{
  if (this->isType() || this->isParent() || this->isName() || this->isPath())
    return true;
  return false;

}

char Token::getElemValue()
{
  if (this->isEndOfText())
    {
    cerr << "end of text Token" << endl;
    exit(1);
    }
  return elemTokenValue;
  
}

string Token::getStringValue()
{
  if (this->isEndOfText())
    {
      cerr << "end of text Token"<< endl;
      exit(1);      
    }
  return valueTokenValue;
}
