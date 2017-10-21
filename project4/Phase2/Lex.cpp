/*
Assignment : project4
Author: Ian Davidson
File: Lex.cpp
Date : Spring 2017 
*/

#include "Lex.hpp"
#include <ctype.h>


Lex::Lex(std::string input): inputToTokenize(input), whereToStart(0), haveAnUngottenToken(false), lastToken("") {}

int Lex::skipWhiteSpaces()
{
    // Scan the inputToTokenize string until either we exhaust the input or we find a non-black character.
    while( whereToStart < inputToTokenize.length() && isspace(inputToTokenize[whereToStart]) )
        whereToStart++;
    return whereToStart;
}


Token Lex::parseValue()
{
  // precondition: whereToStart < inputToTokenize.length() is true.
  // That is, there is one single-quote character at inputToTokenize[whereToStart]
  // and must be one more single-quote character acting as a somewhat of a  nullterminator 
  std::string value = "";

  unsigned int idx = whereToStart;

  value += inputToTokenize[idx];
  idx++;

  if (inputToTokenize[idx] == '\'')
    {
      value += inputToTokenize[idx];
      idx++;

      //value.erase(0,1);
      //value.erase(value.length()-1, 1);
      //take off single quotes here^^
      
      lastToken = Token(value);

      whereToStart = idx;

      return lastToken;
    }
  
  while( idx < inputToTokenize.length() && isValue( inputToTokenize[idx])){

    //case for if inTTok[wts] is closing quote
    if (inputToTokenize[idx] == Token::element::QUOTE){
      value += inputToTokenize[idx];
      idx++;
      break;
      
      //if statement for escaped case. if inputToTokenize[idx] == '\'
    }else if ( inputToTokenize[idx] == '\\' && idx < inputToTokenize.length() + 1){ //has to check if the space infront exists.
      value += inputToTokenize[idx];//backslash is added value
      idx++;
      value += inputToTokenize[idx];//escaped character is added to value
      idx++;
    }else{

      value+= inputToTokenize[idx];
      idx++;

    }
  }

  int lengthIndex = value.length() - 1;

  if (value[lengthIndex] == '\'')
    {  
      //rip off first and last quotes here using string::erase
      //value.erase(0,1);
      //value.erase(value.length()-1, 1);

      
      lastToken = Token(value);
      
      whereToStart = idx;
      
      return lastToken;
    }
  
  cout << "quoted string doesnt end with single quote" << endl;
  exit(1);
}

bool Lex::isValue(char value)
{
  if ( isalnum(value)){   // this checks if the passed character is alpha numeric
    return true;
    
  } else if (value == '.'){
    return true;

  } else if (value == '_'){
    return true;

  } else if (value == '~'){
    return true;

  } else if (value == '-'){
    return true;
    
  } else if (value == '\\'){//quote checks for literal backslash, so it can be dealed with in while loop
    return true;
    
  } else if (value == Token::element::QUOTE){
    return true;
    
  }else if (value == '/'){
    return true;
  }
  
  return false;
  
}

// parse element
Token Lex::parseElement()
{
    // precondition: whereToStart < inputToTokenize.length() is true.
    // That is, there is at least one non-space character (may or many not be a name character)
    // left in inputToTokenize.

    std::string name = "";
    
    unsigned int idx = whereToStart;
    while( idx < inputToTokenize.length() && isalpha( inputToTokenize[idx] ) ) {
        name += inputToTokenize[idx];
        idx++;
    } 
    
    if( idx - whereToStart == 0 ) {  // inputToTokenize[whereToStart] must havenot been expected input.
        std::cout << "Unexpected character in input. The character is ->" << inputToTokenize[whereToStart]
                  << "<-" << std::endl;
        exit(1);
    }

    //make instance of token with <name>
    lastToken = Token(name);


    if ( lastToken.isType() || lastToken.isParent() || lastToken.isName() || lastToken.isPath() || lastToken.isChildren() ){
    
    
      //do checking here with functs, if they all return false then exit bc bad case
      whereToStart = idx;
      return lastToken;
    }

    std::cerr << "unexpected string" << endl;
    exit(1);
}

Token Lex::getToken()
{
    if( haveAnUngottenToken ) {
        haveAnUngottenToken = false;
        return lastToken;
    }
    
    skipWhiteSpaces();

    //if statement checks to see if we are at the end of lex
    if( whereToStart == inputToTokenize.length() ) {
        Token token;
        token.makeEndOfText();
        return lastToken = token;
    }

    //this quanified if statement, only cares if the current letter siting in inputToTok[WTS], is recognized as a member of the enum type, element.


    if ( inputToTokenize[whereToStart] == Token::element::OPENCURLY || inputToTokenize[whereToStart] == Token::element::CLOSECURLY || inputToTokenize[whereToStart] == Token::element::OPENBRACKET || inputToTokenize[whereToStart] == Token::element::CLOSEBRACKET || inputToTokenize[whereToStart] == Token::element::COMMA || inputToTokenize[whereToStart] == Token::element::COLON ){
      //looks super sloppy and cant reference using testing functions b/c inputTTok[WTS] is c string not a token
     
        lastToken = Token(inputToTokenize[whereToStart]);
        whereToStart++;
        return lastToken;
    }





    //check for quote then call parseValue()

    if ( inputToTokenize[whereToStart] == Token::element::QUOTE ){
      return parseValue();
    }

    //only cases left are unknown characters/bad input, known unquoted string w/ testing functions

    return parseElement();
}

void Lex::ungetToken()
{
    haveAnUngottenToken = true;
}
