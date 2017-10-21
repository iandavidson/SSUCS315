// Assignment : Project 1
// File : Tokenizer.cpp
// Author : Ian Davidson
// Date  : Spring 2017 


#include "Tokenizer.hpp"

vector<Token*> &Tokenizer::Tokenize()
{
  string expCopy = expression;

  // cout << "expCopy: " << expCopy << endl;
  expCopy.erase (remove (expCopy.begin(), expCopy.end(), ' '), expCopy.end());
  //  cout << "expCopy: " << expCopy << endl;
  
  
  //  vector<Token*> tokens;

  string equSign = "=";

  //save identifier as first token, and = as second token


  //if firstChunk isnt size 2 then we have a problem
  
  string firstChunk = expCopy.substr(0, expCopy.find(equSign)+1);
  //take first lowercase letter and save to tokens->insert(token(i))
  //do same with = sign as ^

  Token* identToken = new Token(firstChunk[0]);
  

  expCopy = expCopy.substr(firstChunk.length(), expCopy.length()-1);
  //expCopy

  
  //get past lowercase letter and =  in expression"i ="
  
  //get rid of all spaces to make things easier
  // expCopy.erase (remove (expCopy.begin(), expCopy.end(), ' '), expCopy.end());

  //  cout << expCopy << endl;
  int minExpression = expCopy.length();
  //iterate through rest of string
  int i = 0;
  // while (expCopy[i] != '\0'){


  while (i < minExpression){  
    // cout << "i  " << i << endl;
    //    cout << isSymbol(expCopy[i]) << endl;
    if (isSymbol(expCopy[i])){
      //create instance of token a expCopy[i]
	// Token tok2(expCopy[i]);
	// tokens.push_back(tok2);
      //      cout << "new token pushed in" << endl;
      tokens.push_back(new Token(expCopy[i]));
      i++;	
    }
      
    if (isRoman(expCopy, i) != 0)   {
      int k = isRoman(expCopy, i);
      //      Token tok3(expCopy.substr(i, k));
      // tokens.push_back(tok3);
      tokens.push_back(new Token(expCopy.substr(i, k)));
      i = i +k;
    }  
  }

  tokens.push_back(new Token('\0'));
  
  return tokens;
  
}

bool Tokenizer::isSymbol(char c)//used for operators
{
  //  cout << "made it to isSymbol, Symbol: " << c << endl;
  if (c == '(')
    return true;
  else if (c == ')')
    return true;
  else if (c == '+')
    return true;
  else if (c == '-')
    return true;
  else if (c == '*')
    return true;
  else if (c == '/')
    return true;
  else if (c == '%')
    return true;
  
  return false;

}



int Tokenizer::isRoman(string expCopy, int i)
{
  int rVal = 0;
  
  /* for (int k = i; isupper(expCopy[i]); k++)
    rVal = rVal + 1;
  */
  while (isupper(expCopy[i])){
    rVal = rVal + 1;
    i++;
  }
  return rVal;



}

Token Tokenizer::getIdentifier()
{
  return *identToken;
  
}


Tokenizer::~Tokenizer()
{
  int end = tokens.size();
  for (int i = 0; i < end; i++)
    delete tokens[i];

  delete identToken;
}
