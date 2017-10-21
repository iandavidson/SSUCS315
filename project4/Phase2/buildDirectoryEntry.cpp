#include <string>
#include <iostream>
#include "Token.hpp"
#include "Lex.hpp"
#include "DirectoryEntry.hpp"
#include "DirectoryNode.hpp"

using namespace std;


void parseChildren(Lex *lex, DirectoryNode *root);
DirectoryNode *parseSingular(Lex *lex);
DirectoryEntry *buildDirEnt(Lex *lex);


//function which  builds an intance of DirectoryEntry, return DE*, calls parse kids with
//DE->root and lex as params

DirectoryEntry *buildDirEnt(Lex *lex)
{

  DirectoryEntry *internalRep = new DirectoryEntry();

  //this function takes care of some default setters  
  internalRep->defaultSetters(parseSingular(lex));

  return internalRep;


}


void parseChildren(Lex *lex, DirectoryNode *root)
{
  //lex is currently sitting at '{' in all cases
  Token token = lex->getToken();
  //  token.print();

  if(!token.isOpenBracket())
    exit(1);

  do{

    root->addDirectoryNode(parseSingular(lex));
    lex->ungetToken();
    token = lex->getToken();

    if(token.isCloseBracket())
      break;

    token = lex->getToken();
    if(!token.isCloseBracket())
      lex->ungetToken();//
    //token.print();

  }while(!token.isCloseBracket());

  token = lex->getToken();
  //token.print();

  token = lex->getToken();
  //token.print();

  return;
}



DirectoryNode *parseSingular(Lex *lex)
{
  //assuming lex is at open curly right now
  Token token = lex->getToken();
  //token.print();


  if (!token.isOpenCurly())
    {
      cerr << "first token found should be an opening curly brace" << endl;
      exit(1);
    }

  //would assign "parent" to token ^

  DirectoryNode *node = new DirectoryNode(); // = &DirectoryNode();

  string quoteRipped = "";

  for(int i = 0; i < 4; i++){
    //do more syntax checking here

    //first get == expected unquoted

    token = lex->getToken();
    //token.print();

    if(! token.isExpectedString())
      exit(1);//should break program too/exit


    token = lex->getToken();
    //token.print();
    //second get == :

    if (!token.isColon()){
      cerr << "token printed should be an a colon" << endl;
      exit(1);
    }

    //third get == quoted string
    token = lex->getToken();
    quoteRipped = token.getStringValue();

    //these lines take the first and last character out of the string quoteRipped (single quotes)
    quoteRipped.erase(0,1);//rips first char
    quoteRipped.erase(quoteRipped.length()-1, 1); //rips last char


    //different assignment of token.print() in *node here in loop

    if (i == 0){
      node->parent(quoteRipped);
    } else if (i == 1){
      node->path(quoteRipped);

    } else if (i == 2){
      node->name(quoteRipped);

    } else if (i == 3){
      node->type(quoteRipped);
      if(token.isFile())
	node->setFile();
      if(token.isDirectory())
	node->setDirectory();
    }


    //fourth get == comma
    token = lex->getToken();
    //token.print();

    //On last iteration at this point, token will hold diff values
    //dependent on node being a file or directory
  }

  //to get to next "{" :

  token = lex->getToken();
  //token.print();

  if(token.isCloseBracket()){
    lex->ungetToken();
    //cout << "unget here" << endl;
    return node; // now needs 4 more gets till ready for next
  }


  if(token.isEndOfText()){
    lex->ungetToken();
    //cout << "unget here" << endl;
    return node;
  }

  //move lex to child '{' of node, if node is dir type, otherwise its at correct token
  if(node->isDirectory())
    {
      token = lex->getToken();
      //token.print();
      parseChildren(lex,node);

    }

  return node;

}



