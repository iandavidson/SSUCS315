/*
Ian Davidson
project4 Phase1
cs315 spring2017
Dr. Kooshesh
 */

#include "ListNode.hpp"
#include "Lex.hpp"
#include "Token.hpp"
#include <vector>
#include <string>
#include <iostream>

using namespace std;


ListNode *buildList(Lex *lex);
void parseChildren(ListNode *parent, Lex *lex);
void printList(ListNode *list);
void destroy(ListNode *list);


ListNode *buildList(Lex *lex)
{
  // build the internal representation of a recursive list and return a pointer to it.

  //  cout << "enter buildlist()" << endl;

  Token token = lex->getToken();
  //  cout << token.getChar() << endl;

  if (token.isEndOfText())
    exit(1);

  if(token.isName()){
    ListNode *node = new ListNode(token.getName());

    lex->ungetToken();
    return node;
  }
  if(!token.isLeftParen()){
    cerr << "bad input here, exiting" << endl; 
    exit(1);
  }
  ListNode *node = new ListNode();
  lex->ungetToken();
  parseChildren(node,lex);
 
  
  lex->ungetToken();
  return node;

}

void parseChildren(ListNode *parent,Lex *lex)
{
  Token token = lex->getToken();
  // cout << token.getChar() << endl;
  
  while(!token.isRightParen()){

    parent->addChildNode(buildList(lex));

    token = lex->getToken();
    //cout << token.getChar()  << endl;


    token = lex->getToken();
    if (token.isRightParen()){
      //  cout << "break out" << endl;
      break;
    }

    lex->ungetToken();
  }

  //  cout << "return from parse child" << endl;
  
  return;
}

void printList(ListNode *list)
{
  if( list == nullptr )
    return;  // an empty list doesn't have any representation.
  else if( list->isAtom() ) {
    std::cout << " " << list->getAtom() << " ";
  } else {
    std::cout << "(";
    std::vector<ListNode *> children = list->getChildren();
    for( auto child = children.begin(); child != children.end(); ++child )
      printList(*child);
    std::cout << ")";
  }
}

void destroy(ListNode *list)
{
  // delete the nodes of the list that "list" points to.

  while(!list->getChildren().empty())
    {
      destroy(list->getChildren().back());
      list->getChildren().pop_back();
    }
  delete list;
  list = NULL;
  return;
}

int main()
{
  //  std::string input = "(a b (  ( (f g) e (((f) g) h) (h (i)))) )";
  
  std::string input = "(a b (c d ((e) f ) ((a b (c d ((e) f )) a b (c d ((e) f ) ))) (c d ((e) f ) )) )";
    

  Lex *lex = new Lex(input);

  ListNode *list = buildList(lex);
  list->printNode();
  //printList(list);
  std::cout << std::endl;

  destroy(list);
  delete lex;
  
  return 0;

}
