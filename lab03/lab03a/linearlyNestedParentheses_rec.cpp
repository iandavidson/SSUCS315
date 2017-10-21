// Assignment : lab03
// File : linearlyNestedParentheses_rec.cpp
// Author : Ian Davidson
// Date  : Spring 2017


#include <iostream>

#include "Token.hpp"
#include "Lex.hpp"


bool isList(Lex *lex)
{

  //attack plan: when isLeftparen() or right(). see what cases brackets/curlies would fall under. 
  // middle of list could be replaced with mirror->yeilding no changes to functions. how to keep ths and keep recursion.

  
  Token token = lex->getToken();
  if( token.isEndOfText() )
    return true;

  if( ! token.isLeftParen() )  // a linearly nested list starts with an open parenthesis.
    return false;

  token = lex->getToken();

  // Are we at the base case? That is, did we just get a right parenthesis
  // that matches the left parenthesis that we saw above?

  if( token.isRightParen() )   // If so, return
    return true;

  // No, we didn't see a right parenthesis. We either have a bad token or we have
  // a linearly nested list to parse. Put the token back and parse such list by
  // calling this function recursively.

  lex->ungetToken();
  if( isList(lex) ) {
    // So, at the top of this function, we saw a left parenthesis.
    // In between, we parsed a linearly nested list. Now, we should
    // see the right parenthesis that matches the left one.

    token = lex->getToken();
    return token.isRightParen();
  }

  return false;  

  
  /* below is original impl of is list,


  Token token = lex->getToken();
  if( token.isEndOfText() )
    return true;

  if( ! token.isLeftParen() )  // a linearly nested list starts with an open parenthesis.
    return false;

  token = lex->getToken();

  // Are we at the base case? That is, did we just get a right parenthesis
  // that matches the left parenthesis that we saw above?

  if( token.isRightParen() )   // If so, return
    return true;

  // No, we didn't see a right parenthesis. We either have a bad token or we have
  // a linearly nested list to parse. Put the token back and parse such list by
  // calling this function recursively.

  lex->ungetToken();
  if( isList(lex) ) {
    // So, at the top of this function, we saw a left parenthesis.
    // In between, we parsed a linearly nested list. Now, we should
    // see the right parenthesis that matches the left one.

    token = lex->getToken();
    return token.isRightParen();
  }

  return false;
  */
  
}

int main()
{
  //  std::string input = "( ( ( ((  ())  )) ))";
  std::string input = "(  (()  ())  )))";

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
