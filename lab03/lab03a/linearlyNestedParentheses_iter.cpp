// Assignment : lab03
// File : linearlyNestedParentheses_iter.cpp
// Author : Ian Davidson
// Date  : Spring 2017      

#include <iostream>

#include "Lex.hpp"

using namespace std;

int main() 
{
    std::string input = "( [ { } ] )";

    int numOpenParens = 0;
    int numOpenBracket = 0;
    int numOpenCurly = 0;
    Token firstHalf[input.length()];
    Lex *lex = new Lex(input);

    Token token = lex->getToken();

    int counter = 0;
    while( token.isLeftParen() || token.isLeftBracket() || token.isLeftCurly() ) {  // count the number of open parentheses.
   
    // for(Token token = lex->getToken(); token.isLeftParen() || token.isLeftBracket() || token.isLeftCurly(); lex->getToken() ){
      firstHalf[counter] = token;
      if (token.isLeftParen())
	numOpenParens++;
      else if(token.isLeftBracket())
	numOpenBracket++;
      else if(token.isLeftCurly())
	numOpenCurly++;
      counter++;
      token = lex->getToken();
    }

    if( token.isEndOfText() && numOpenParens == 0 && numOpenBracket == 0 && numOpenCurly == 0) {
        // We didn't see any open parentheses.
        std::cout << "No input to parse!\n";
        delete lex;
        return 0;
    }

    // We must have gotten a token that is not a left parenthesis.
    // It might be a right parenthesis or something else.

    lex->ungetToken();  // put the last token back!
    
    // We are about to get a new token. In this context, it seems
    // silly to return the token that we just got from Lex and
    // immediately ask for it back in the next statement. However, in
    // a situation where you are trying to process one part of the
    // input, you will often have to read an extra token to know that
    // you are finished. In that case, you would to return that extra
    // token to Lex so that you can retrieve it when you're ready to
    // process the next piece of the input.

    token = lex->getToken();  // get a new token.


    //    cout << "counter: " << counter << endl;
    // cout << "made it to halfway point" << endl;

    counter--;// counter was incremented one too many times when looking for opening parens, decrement
    
    //the nested if statements check to see if the closing paren/brack/curly corresponds correctly with the first half of tokens stored in firstHalf[] 
    while( token.isRightParen() || token.isRightBracket() || token.isRightCurly() ) {

      //      cout << "counter: " << counter << endl;

      if (token.isRightParen()){
	if (firstHalf[counter].isLeftParen())
	  numOpenParens--;
      } else if(token.isRightBracket()){
	if (firstHalf[counter].isLeftBracket())
	  numOpenBracket--;
      }else if(token.isRightCurly()){
	if (firstHalf[counter].isLeftCurly())
	  numOpenCurly--;
      }
      token = lex->getToken();
      counter--;
    }

    /*
    cout << "value of numOpenParens: " << numOpenParens << endl;
    cout << "value of numOpenBrackets: " << numOpenBracket << endl;
    cout << "value of numOpenCurly: " << numOpenCurly << endl;
    */
    
    if( numOpenParens != 0 || numOpenBracket != 0 || numOpenCurly != 0  || ! token.isEndOfText())
        std::cout << "The input string is not a well-formed nested parenthetical.\n";
    else
        std::cout << "Input is a well-formed nested parenthetical.\n";

    delete lex;
    return 0;
}
