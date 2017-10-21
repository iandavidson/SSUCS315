// Assignment : Project 1
// File : Post_main.cpp
// Author : Ian Davidson
// Date  : Spring 2017  

#include "PostEvaluator.hpp"
#include "Token.hpp"
#include "Tokenizer.hpp"
#include "InfixToPostfix.hpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {

  //  Tokenizer *tok = new Tokenizer( "i = (M + X * II + IV) * II" );
  // std::vector<Token*> tokens = tok->Tokenize();
  /*
  for( auto token : tokens )
    token->print();
  std::cout << std::endl;
  
  Token *token = new Token();
  token->eol(true);
  tokens.push_back(token);
  
  int tokensSize = tokens.size();
  
  //holds the variable passed in token, in this case its i.
  Token* identifier = tok->getIdentifier();

  
  InfixToPostfix *itop = new InfixToPostfix();
  std::vector<Token *> postfixTokens;
  itop->convert( tokens, tokensSize, postfixTokens );
  std::cout << "\nThe postfix expression has " << postfixTokens.size() << " tokens.\n";
  for( auto postfixToken : postfixTokens)
    postfixToken->print();
  std::cout << std::endl;
  */

  vector<Token*> tokens = vector<Token *>();
  // vector after should have XXX XX +
  tokens.push_back(new Token("XXX"));     // 30
  tokens.push_back(new Token("XX"));     // 20
  tokens.push_back(new Token('+'));     // +

  PostEvaluator* post = new PostEvaluator();

  string output = post->evaluate(tokens);

  cout << output << endl;
  
  
  return 0;
}

