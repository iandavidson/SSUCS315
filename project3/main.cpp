
#include <string>
#include <fstream>
#include <iostream>
#include "Lex.hpp"
#include "Token.hpp"


using namespace std;

int main(int argc, char const * const argv [])
{
  if ( argc > 2 || argc < 2){
    cerr << "invalid arguments, need to pass 1 .json file as an argument" << endl;
    exit(1);
  }

  ifstream input(argv[1]);
  //open input using filename: argv[1]
  if(input.fail()){
    cerr << "input error from: " << argv[1] << endl;
    cerr << "Exiting now" << endl;
    exit(1);

  }

  string totalInputFile = "";
  
  //use tokenizer/lex with the input taken from ifstream
  for ( string line; getline(input, line); ){
    totalInputFile += line;
  }


  input.close();
  
  
  //by having the whole input file in one string, we can go Token by token from
  //start to end without having any problems
  
  Lex *lex = new Lex(totalInputFile); //this is how to make an instance of lex
  Token token = lex->getToken();
  while (! token.isEndOfText()){
    token.print();
    token = lex->getToken();
  }

  return 0;

}
