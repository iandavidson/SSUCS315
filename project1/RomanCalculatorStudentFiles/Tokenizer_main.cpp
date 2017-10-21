// Assignment : Project 1
// File : Tokenizer_main.cpp
// Author : Ian Davidson
// Date  : Spring 2017    

#include <iostream>
#include "Tokenizer.hpp"
#include "Token.hpp"



int main() {
  Tokenizer *tok = new Tokenizer( "i = (M + X * II + IV) * II" );
  std::vector<Token*> tokens = tok->Tokenize();
  for( auto token : tokens )
    token->print();
  cout << endl;
  
  tok = new Tokenizer( "i=((M+X)*(II+IV))*II" );
  tokens = tok->Tokenize();
  for( auto token : tokens )
    token->print();
  cout << endl;
  
  tok = new Tokenizer( "i=(    M     +    X    *II+IV     )   *II" );
  tokens = tok->Tokenize();
  for( auto token : tokens )
    token->print();
  cout << endl;
  
  return 0;
}
