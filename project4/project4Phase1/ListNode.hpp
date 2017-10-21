#include<iostream>
#include<vector>

#ifndef __LISTNODE_HPP
#define __LISTNODE_HPP



using namespace std;

class ListNode {
public:
  ListNode(): _isAtom(false), atomStrValue("") {}
  ListNode(std::string st): _isAtom(true), atomStrValue(st)  {}


  bool isAtom() { return _isAtom; }
  string getAtom() { return atomStrValue; }

  void printNode(); 
  void addChildNode(ListNode *list) { children.push_back(list); }
  int numChildren() { return children.size(); }
  std::vector<ListNode *> &getChildren() { return children; }

private:
  void printHelper(ListNode *parent,int gen);
  std::vector<ListNode *> children;
  bool _isAtom;
  string atomStrValue;
};

#endif
