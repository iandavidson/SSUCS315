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
  
  BinSearchTree *tree = new BinSearchTree();

  int value;
  
  for ( string line; getline(input, line); ){
    value = stoi(line);
    tree->insert(value);
  }

  input.close();
  
  tree->inorderDump();

  if(tree->iterFind( 199904)) //this number does not exist in the cs315.. inputfile inside pwd
    cout << "test for iterFind came back true" << endl;
  else
    cout << "test for iterFind came back false" <<endl;
  
    
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
