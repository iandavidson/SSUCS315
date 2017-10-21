/*
Assignment: project4
Author: Ian Davidson
File : DirectoryNode.hpp
Date : Spring 2017
cs315
 */
#ifndef __DIRECTORYNODE_HPP
#define __DIRECTORYNODE_HPP

#include<iostream>
#include<vector>
#include<string>

using namespace std;

class DirectoryNode {
public:
  DirectoryNode(): _isFile(false), _isDirectory(false),_isLast(false), _parent(""), _path(""), _name(""), _type("") {}
  ~DirectoryNode();
  bool isFile() { return _isFile; }  // is this a file directory type?
  bool isDirectory() { return _isDirectory; }  // is this a directory?
  bool isLast() { return _isLast;}

  //all of these set the member variables to true
  void setLast();
  void setFile();
  void setDirectory();
  
  void setDirectoryKidVector(vector<DirectoryNode *> kids);
  void addDirectoryNode(DirectoryNode *list) { children.push_back(list); }
  int numEntries() { return children.size(); }
  vector<DirectoryNode *> &getChildren() { return children; }

  string parent() { return _parent; }
  void parent(string pStr) { _parent = pStr; }

  string path() { return _path; }
  void path(string pStr) { _path = pStr; }

  string name() { return _name; }
  void name(string pStr) { _name = pStr; }

  string type() { return _type; }
  void type(string pStr) { _type = pStr; }

  void ParentNode( DirectoryNode *node) { parentDir = node;}
  DirectoryNode *&ParentNode() {return parentDir;}

  //helper to check if 2 nodes are equivelent used checking root vs cwd
  
private:
  bool _isFile, _isDirectory, _isLast;
  DirectoryNode *parentDir;
  string _parent, _path, _name, _type;
  vector<DirectoryNode *> children;

};
#endif
