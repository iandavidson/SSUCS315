// Assignment : Lab04b
// File : linearlyNestedParentheses_rec.cpp
// Author : Ian Davidson
// Date  : Spring 2017     

#include <iostream>

#include "Token.hpp"
#include "Lex.hpp"

std::string readAnInputLine()
{
    std::string input;
    std::cout << "Enter a recursive list.\n";
    getline(std::cin, input);
    if( ! std::cin.good() ) {
        std::cout << "Input stream seems to be corrupt. Terminating...\n";
        exit(1);
    }
    return input;
}

bool isList(Lex *lex) 
{

  // trace this function using ( ( () () ) ( () () ) )
  Token token = lex->getToken();  // read the first left paren
  if( token.isEndOfText() )
    return true;

  if( ! token.isLeftParen() )  // a linearly nested list starts with an open parenthesis.
    return false;

  token = lex->getToken();       // reads the second open parent

  // Are we at the base case? That is, did we just get a right parenthesis
  // that matches the left parenthesis that we saw above?

  if( token.isRightParen() )   // If so, return
    return true;

  lex->ungetToken();
  while( isList(lex)){
    token = lex->getToken();
    if (token.isRightParen() )
      return true;

    
    lex->ungetToken();
  }


  
  return false;


}

int main() 
{
  //    std::string input = readAnInputLine();
    std::string input = "(a b (c d ((e) f ) ((a b (c d ((e) f )) a b (c d ((e) f ) ))) (c d ((e) f ) )) )";

    Lex *lex = new Lex(input);

    Token token = lex->getToken();  // get a token to determine if the input is empty or not.
    if( token.isEndOfText() ) {
        std::cout << "No input to parse!\n";
        delete lex;
        return 0;
    }
    
    // The input was not empty. So, put the token back and have isList to parse the input list.
    lex->ungetToken();  
    bool wasList = isList(lex);

    // Get another token to determine if we have exhausted the input or not.
    token = lex->getToken();

    if( ! wasList || ! token.isEndOfText() )
        std::cout << "The input string is not a well-formed nested parenthetical.\n";
    else
        std::cout << "Input is a well-formed nested parenthetical.\n";

    delete lex;
    return 0;
}
