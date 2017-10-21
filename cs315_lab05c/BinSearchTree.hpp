/*
Author: Ian Davidson                                                       
Course: CS 315                                                                             
Assignment: Lab 5 Part C     
*/
// Forward declaration of TreeNode class below.
// Since BinSearchTree uses TreeNode pointers rather
// than objects, we can get away with this in the .hpp.
// You should include "TreeNode.hpp" in the BinSearchTree.cpp

class TreeNode;


#ifndef __BINSEARCHTREE_HPP
#define __BINSEARCHTREE_HPP

//#include "TreeNode.hpp"

#include <queue>

using namespace std;

class BinSearchTree {
public:

  void insert( int v );
  bool find( int v ); //recursive helper funct called: helperFind.
  bool iterFind( int v );//no helpers
  int size(); //helper called helperSize(TreeNode*root)
  void inorderDump();// helper called : recursiveInDump()
  int maxDepth();// helper function is called:  height
  void levelOrderDump();
  
  bool remove( int v );//helpers: removeValue(), removeNode(), removeMinNode()
  int kthSmallest( int k );
  void valuesAtLevel( int k );
  void iterValuesAtLevel( int k );
  int iterMaxDepth();
  bool hasRootToLeafSum( int sum );
  bool areIdentical( BinSearchTree *bst );
  BinSearchTree *intersectWith( BinSearchTree *bst );
  BinSearchTree *unionWith( BinSearchTree *bst );
  BinSearchTree *differenceOf( BinSearchTree *bst );

private:

  void differenceHelper(BinSearchTree *dif, TreeNode *otherN);//will heavily use 'this'
  void intersectHelper(BinSearchTree *intersect, BinSearchTree *otherTree, TreeNode *thisN);
  void unionHelper(queue<int> &q, TreeNode *root);//helper of union
  
  int height(TreeNode *node);
  void valuesAtLevelRecHelper(TreeNode *node, int k);

  bool IDHelper(TreeNode *thisNode,TreeNode *other);

  bool rootToLeafRec(int sum, TreeNode *node);

  int kthSmallestHelper(TreeNode *node, int k);
  void recursiveInDump(TreeNode *node);
  bool helperFind(TreeNode *node, int v);
  int helperSize(TreeNode *node);
  TreeNode *local_insert( TreeNode *r, int );

  TreeNode *removeNode(TreeNode *node);
  TreeNode *removeValue( TreeNode *node, int value, bool &success);
  TreeNode *removeMinNode(TreeNode *node, int &nextVal);
  
  TreeNode *root;
};

#endif
