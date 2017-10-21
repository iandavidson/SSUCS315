/*                             
  Author: Ian Davidson                                                                                           
  Course: CS 315                                                                              
  Assignment: Lab 5 Part B                                                          
*/
#include "TreeNode.hpp"
#include "BinSearchTree.hpp"
#include <iostream>

bool BinSearchTree::find( int v)
{
  return helperFind(root, v);

}

bool BinSearchTree::helperFind(TreeNode *node, int v)
{
  if (node == nullptr)
    return false;
  if (node->value() == v)
    return true;
  if (node->value() > v)
    return helperFind(node->leftSubtree(), v);//left side call

  return helperFind(node->rightSubtree(), v); //right ride call
}


bool BinSearchTree::iterFind( int v)
{
  TreeNode *node = this->root;

  while(node != nullptr){
    if(node->value() == v)
      return true;
    if(node->value() > v)
      node = node->leftSubtree();
    else {
      node = node->rightSubtree();
    }
      
  }
    return false;
}

int BinSearchTree::size()
{
  return helperSize(root);
}


int BinSearchTree::helperSize( TreeNode *node)
{
  if(node == nullptr)
    return 0;
  return 1 + helperSize(node->leftSubtree()) + helperSize(node->rightSubtree());
}


void BinSearchTree::inorderDump()
{
  recursiveInDump( root);
  
  return;
}

  
void BinSearchTree::recursiveInDump(TreeNode *node)
{
  if (node == nullptr)
    return;
  recursiveInDump(node->leftSubtree());
  cout << node->value() << endl;
  recursiveInDump(node->rightSubtree());
}


int BinSearchTree::maxDepth()
{
  return height(this->root);
}

int BinSearchTree::height(TreeNode *node)
{
  if(node == nullptr)
    return 0;
  int left = height(node->leftSubtree());
  int right = height(node->rightSubtree());
  return 1 + (left > right ? left : right);

}

TreeNode *BinSearchTree::local_insert( TreeNode *root, int v ) {
  if( root == nullptr )
    return new TreeNode( v );
  if( root->value() < v )
    root->rightSubtree( local_insert( root->rightSubtree(), v ) );
  else
    root->leftSubtree( local_insert( root->leftSubtree(), v ) );
  return root;
}

void BinSearchTree::insert(int v) {
  if( ! find(v) )
    root = local_insert( root, v );
}
