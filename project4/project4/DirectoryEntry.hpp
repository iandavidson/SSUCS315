/*                                                                         
Assignment : project4        
Author: Ian Davidson                                   
File: DirectoryEntry.hpp                                                               
Date : Spring 2017                                                           
*/

#include "DirectoryNode.hpp"

#include <vector>
#include <string>
#ifndef __DIRECTORYENTRY_HPP
#define __DIRECTORYENTRY_HPP



using namespace std;

class DirectoryEntry {
public:
  enum EntryType { FILE, DIRECTORY };
  DirectoryEntry();
  void destroy();
  void destroyLocal(DirectoryNode *node);
  void defaultSetters(DirectoryNode *node);
  int depth();
  string pwd();
  string cd();
  string cd(string path);
  vector<string> ls();
  vector<string> ls(string path);
  DirectoryEntry *duplicate();
  DirectoryEntry *duplicate(string path);
  vector<string> find(string path);
  bool hasSubstructure(DirectoryEntry *dirEntry);
  bool areTheSame(DirectoryEntry *dirEntry);
  void move(string fromPath, string toPath);

  //private setters, needed to initalize
private:
  void setParentAssignment();
  void setRootDir(DirectoryNode *root) {rootDir = root;}
  void setCWD(DirectoryNode *root) {cwd = root;}
  void setcwdToRoot() {cwd = rootDir;}


  //private helpers:
  void findAdderHelper(DirectoryNode *node, string path, vector<string> &descendants);
  void movePathParentHelper(string path, DirectoryNode *node);
  
  bool hasSubstructureTraverseHelper(DirectoryNode *thisNode, DirectoryNode *otherNode);
  bool hasSubstructureCheckHelper(DirectoryNode *thisNode, DirectoryNode *otherNode);
  DirectoryNode *findPathMatch(bool &success, string path, DirectoryNode * node);
  DirectoryNode *duplicateHelper(DirectoryNode *thisNode);
  DirectoryNode *duplicateHelperWithArg(DirectoryNode *thisNode, string currentPath, bool root);
  void lsChildAdder(vector<string> &kids, DirectoryNode *parent);
  int depthHelper(DirectoryNode *node);
  bool depthChecker(DirectoryNode *node);
  DirectoryNode *finderHelper(bool &found, string pathway, DirectoryNode *node);

  bool identicalHelper(DirectoryNode *thisN, DirectoryNode *otherN);
  void parentAssignmentRec(DirectoryNode *parent);

  DirectoryNode *rootDir;
  DirectoryNode *cwd;
};

#endif
