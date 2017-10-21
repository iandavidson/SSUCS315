/*                                                                               
Assignment : project4                                                                  
Author: Ian Davidson                                                                 
File: DirectoryNode.cpp                                                                          
Date : Spring 2017                                                                       
*/

#include "DirectoryNode.hpp"


void DirectoryNode::setDirectoryKidVector(vector<DirectoryNode *> kids)
{
  this->children = kids;
  return;

}

DirectoryNode::~DirectoryNode()
{
  //recusively delete children then parent recursively

}


void DirectoryNode::setFile()
{
  _isFile = true;
  return;
}

void DirectoryNode::setDirectory()
{
  _isDirectory = true;
  return;
}

void DirectoryNode::setLast()
{
  _isLast = true;
  return;
  
}
