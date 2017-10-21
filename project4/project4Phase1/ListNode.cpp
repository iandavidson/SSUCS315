#include "ListNode.hpp"
#include <iostream>
#include <string>

using namespace std;


void ListNode::printNode()
{

  if(!this)
    {
      return;
      
    }
  this->printHelper(this,0);

  return;
}

void ListNode::printHelper(ListNode *parent,int gen)
{
  if (parent == nullptr)
    return;

  string tab = "";
  for(int i = 0; i < gen ; i++)
    tab += "    ";
  if(parent->isAtom()){
    cout << tab << parent->getAtom() << endl;
  }else {
    cout << tab << "(" << endl;

    //for(  vector<ListNode *>::iterator it = parent->getChildren(); it != 
    //for(ListNode *child = this->children.begin(); this->children != this->children.end(); ++child)
    for(uint j = 0; j < parent->children.size() ; j++)
      printHelper(parent->children[j], gen+1);
    cout << tab << ")" << endl;
  }
}
