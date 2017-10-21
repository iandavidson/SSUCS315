/*
  Author: Ian Davidson
  Course: CS 315
  Assignment: Lab 5 Part B
*/ 
#include <fstream>
#include <iostream>
#include <string>
#include "TreeNode.hpp"
#include "BinSearchTree.hpp"

using namespace std;

int main( int argc, char *argv[] ) {
  // create a tree and then print the values of its nodes
  // from the smallest to the largest.

  if ( argc > 2 || argc < 2){
    cerr << "invalid arguments, need to pass file as first argument" << endl;
    exit(1);
  }

  ifstream input(argv[1]);
  //open input using filename: argv[1]
  if(input.fail()){
    cerr << "input error from: " << argv[1] << endl;
    cerr << "Exiting now" << endl;
    exit(1);
  }
  
  BinSearchTree *tree = new BinSearchTree();

  int value;
  
  for ( string line; getline(input, line); ){
    //    cout << line << endl << endl;
    value = stoi(line);
    tree->insert(value);
  }

  input.close();

  BinSearchTree *tree2 = new BinSearchTree();
  tree2->insert(150);
  tree2->insert(45);
  tree2->insert(90);
  tree2->insert(20);
  
  cout << "in order dump of tree1:" << endl;
  tree->inorderDump();

  cout << "in order dump of tree2:" <<endl;
  tree2->inorderDump();
  
  cout << endl << endl << endl;
  //  tree->valuesAtLevel(3);

  //  cout << tree->kthSmallest(1) << endl;

  //  cout << tree->kthSmallest(3) << endl;

  
  cout << "Tree2->Difference(tree1)" << endl;
  tree2->differenceOf(tree)->inorderDump();

  cout << endl << "lets take 150 out of tree 2" << endl;

  tree2->inorderDump();
  tree2->remove(150);
  cout << endl;
  tree2->inorderDump();
  /*
//intersect debugging
  cout << "in order dump of intersect tree + tree:" << endl;
  tree->intersectWith(tree)->inorderDump();

  cout << "in order dump of intersect tree + tree2:" << endl;
  tree->intersectWith(tree2)->inorderDump();

  cout << "in order dump of tree1:" << endl;
  tree->inorderDump();
  */

  
  /*
  if(tree->hasRootToLeafSum(3))
    cout << "3 nodes is a valid distance from root->leaf" << endl;
  else
    cout << "3 nodes is not a path which goes from root to leaf" << endl;
  */
  //  cout << "got past funct call" << endl;
  /*
  if( tree->areIdentical(tree))
    {
      cout << "works as expected" << endl;
    }
  else{
    cout << "broken" << endl;
  }
  */

  
  /*  
  if( tree->remove(300))
    cout << "fuckin works" << endl;
  else
    cout << "fuckin sucks" << endl;

  tree->inorderDump();
  */


/*  
  int v;
  while( std::cin >> v ) {
    tree->insert( v );

  }
  tree->inorderDump();
  */

  //  cout << "boom done" << endl;



 return 0;
}
