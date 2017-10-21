/*                                                                                                                   Author: Ian Davidson                                                                                               Course: CS 315                                                                                                     Assignment: Lab 5 Part B                                                                                         */


// Forward declaration of TreeNode class below.
// Since BinSearchTree uses TreeNode pointers rather
// than objects, we can get away with this in the .hpp.
// You should include "TreeNode.hpp" in the BinSearchTree.cpp

class TreeNode;


#ifndef __BINSEARCHTREE_HPP
#define __BINSEARCHTREE_HPP

//#include "TreeNode.hpp"

using namespace std;

class BinSearchTree {
public:
  void insert( int v );
  bool find( int v ); //recursive helper funct called: helperFind.
  bool iterFind( int v );
  int size(); //helper called helperSize(TreeNode*root)
  void inorderDump();// helper called : recursiveInDump()
  int maxDepth();// helper function is called:  height
  

private:

  int height(TreeNode *node);
  void recursiveInDump(TreeNode *node);
  bool helperFind(TreeNode *node, int v);
  int helperSize(TreeNode *node);
  TreeNode *local_insert( TreeNode *r, int );
  TreeNode *root;
};

#endif
