/*                               
Assignment : project4                                                         
Author: Ian Davidson                                                
File: DirectoryEntry.cpp                                                          
Date : Spring 2017                                                                           
*/
#include "DirectoryEntry.hpp"
#include <string>

DirectoryEntry::DirectoryEntry()
{
  this->rootDir = nullptr;
  this->cwd = nullptr;
}



void DirectoryEntry::defaultSetters(DirectoryNode *node)
{
  this->rootDir = node;
  this->cwd = node;
  setParentAssignment();
  return;
  
}

void DirectoryEntry::setParentAssignment()
{
  
  parentAssignmentRec(this->rootDir);
}

void DirectoryEntry::destroy()
//destroys all nodes from root, calls helper
{
  if(this->rootDir)//if root exists lets start garbage collection.
    destroyLocal(this->rootDir);
  this->rootDir = nullptr;
  this->cwd = nullptr;
  delete this;
  return;
}

void DirectoryEntry::destroyLocal(DirectoryNode *node)
//this function destroys nodes and sets all pointers assigned in class to null
{
  if(node->isDirectory()){
    //we want to look through kids
    for(int i = 0; i < node->numEntries(); i++){
      
      destroyLocal(node->getChildren()[i]);
      node->getChildren()[i]->ParentNode(nullptr);
    }
    
  }

  node->getChildren().clear();
  
  delete node;
  
}

void DirectoryEntry::parentAssignmentRec(DirectoryNode *parent)
//goal of this function is to assign the children of param parent, the class member pointer "parentDir"
{
  if(parent->isFile())//hates kids
    return;

  for(uint j= 0; j < parent->getChildren().size(); j++){
    parent->getChildren()[j]->ParentNode(parent);
    if(parent->getChildren()[j]->isDirectory())
      parentAssignmentRec(parent->getChildren()[j]);

  }
  
  return;
}


int DirectoryEntry::depth()
/*
Calculate the depth of the directory entry's root with respect to the current working directory. The depth of the root itself is 1, the depth of a file in the root is 2, etc. Said another way, depth is the number of names in a path, starting at the root. For example, the depth of projects/project3/Token.hpp is 3 when the root is projects.
 */
{
  //start w/ root
  if(this->rootDir == nullptr){
    cerr << "rootDir is a nullptr" << endl;
    exit(1);
  }

  return this->depthHelper(this->rootDir);
  
}

int DirectoryEntry::depthHelper(DirectoryNode *node)
{
  if(node == this->cwd)
    return 1;
 
  if(node->isFile())
    return 1;//cant farther deep with this node



  for (int j = 0; j < node->numEntries(); j++)
    {
      //if kid returns true from depthChecker rec call only on that kid
      if(depthChecker(node->getChildren()[j]))
	return 1 + depthHelper(node->getChildren()[j]);


    }
  return 0;
  
}

bool DirectoryEntry::depthChecker(DirectoryNode *node)
{
  if(node == this->cwd)
    return true;

  if(node->isFile())
    return false;

  for(int i = 0; i < node->numEntries() ; i++){
      if(node->getChildren()[i]->isDirectory())	{
	if(depthChecker(node->getChildren()[i]))
	  return true;

      }
  }

  return false;
  
}

string DirectoryEntry::pwd()
//  Return a string that includes the path to cwd (which includes the name of cwd)
//  if you were in directory project1/RomanCalculatorStudentFiles, then pwd should return projects/project1/RomanCalculatorStudentFiles.
{
  string rootName = this->rootDir->name();
  string cwdPath = this->cwd->path();
  string slash = "/";
  
  //now we need to return string(rootName + '/' + cwdPath)

  rootName.append(slash);
  rootName.append(cwdPath);

  //  cout << "should be: projects/ , root and cwd are same" << endl;

  //  cout << "parent:" << this->rootDir->parent() << endl;
  return rootName;
  
}
string DirectoryEntry::cd()
//will set cwd to rootDir
//return path to cwd
{
  if(this->cwd->path() != this->rootDir->path())
    this->cwd = this->rootDir;

  return this->cwd->name();

}
string DirectoryEntry::cd(string path)
/*  Change to a directory whose name is given as an argument. The last path-component of the argument should be a directory entry of type directory (as opposed to file.) If successful, the cwd changes to the new directory entry. Otherwise, cwd doesn't change.
 */
{
  DirectoryNode *node;
  bool found = false;
  if(this->rootDir->isDirectory())
    node = finderHelper(found, path, this->rootDir);//call this only when ^
  if(found)//if found is false, node is most def a nullptr
    this->cwd = node;

  return this->cwd->name();
}

DirectoryNode *DirectoryEntry::finderHelper(bool &found, string pathway, DirectoryNode *node)
//function should return the directory type node with pathway = "*/dirNodeName"
{
//break off first chunk of pathway, '/' is delimiter, using string::find and string::substring
  if(!node){
    cout << "node is nullptr" << endl;
    found = false;
    return nullptr;
  }

  if(node->path() == pathway){
    cout << "current node is a match with path provided" << endl;
    found = true;
    return node;
  }

  DirectoryNode *child = new DirectoryNode();
  //iterate through kids
  for(int i = 0; i < node->numEntries(); i++){
    //if kid[k].name() == pathChunk && kid[k].isDirectory()
    if(node->getChildren()[i]->isDirectory())
      // return recursive call with(found, pathway, kid[k])   
      
      child = finderHelper(found, pathway, node->getChildren()[i]);
    if(found)
      return child;
  }

  found = false;
  return nullptr;
}

vector<string> DirectoryEntry::ls()
//will return all, string names of children of cwd
{
  vector <string> kids;

  lsChildAdder(kids, this->cwd);
    
  return kids;
}
void DirectoryEntry::lsChildAdder(vector<string> &kids, DirectoryNode *parent)
{

  if(parent == nullptr)
    return;
  
  if(parent->isFile()){
    cout << "Parent is a file type, no kids" << endl;
    return;

    
  }
  
  //  cout << parent->numEntries() << endl;
  for(int i = 0; i < parent->numEntries(); i++)
    {
      //      cout << "i: " << i << endl;
      //cout << "Ith kid name: " << parent->getChildren()[i]->name() << endl;
      kids.push_back(parent->getChildren()[i]->name());


    }    
  return;
  
}

vector<string> DirectoryEntry::ls(string path)
//path goes to directory->then spit out kids 
{
  DirectoryNode *node;
  bool found = false;
  vector<string> kids;
  if(this->rootDir->isDirectory())
    node = finderHelper(found, path, this->rootDir);//we literally need
  if(!found)//if found is false, node is most def a nullptr          
    return kids;

  lsChildAdder(kids, node);

  //kids make it here.

  return kids;
}


DirectoryEntry *DirectoryEntry::duplicate()
//Return a newly created copy of the cwd directory entry.
{
  DirectoryEntry *otherDir = new DirectoryEntry();
  otherDir->defaultSetters(duplicateHelperWithArg(this->cwd, "", true));
  /* otherDir->setRootDir(duplicateHelper(this->cwd));
  otherDir->setcwdToRoot();
  otherDir->setParentAssignment();
  */
  return otherDir;
}

DirectoryEntry *DirectoryEntry::duplicate(string path)
{
  //find node with matching path (File or Dir is OK)

  bool success = false;
  DirectoryNode *node = findPathMatch(success, path, this->rootDir);

  if (!success){
    cerr << "duplicate unsucessful, exiting" << endl;
    exit(1);
  }
  
  DirectoryEntry *otherDir = new DirectoryEntry();
  otherDir->defaultSetters(duplicateHelperWithArg(node, "", true));

  return otherDir;
}


DirectoryNode *DirectoryEntry::findPathMatch(bool &success, string path, DirectoryNode *node)
{
  if(!node){
    //cout << "success is false" <<endl;
    success = false;
    return nullptr;
  }

  if(node->path() == path){
    cout << "current node is a match with path provided" << endl;
    success = true;
    return node;
  }

  DirectoryNode *child = new DirectoryNode();
  //iterate through kids
  for(int i = 0; i < node->numEntries(); i++){
    //if kid[k].name() == path
    //if(node->getChildren()[i]->isDirectory())
      // return recursive call with(found, pathway, kid[k])

      child = findPathMatch(success, path, node->getChildren()[i]);
    if(success)
      return child;

  }

  //  cout << "success is false" << endl;
  success = false;
  return nullptr;
  
}

DirectoryNode *DirectoryEntry::duplicateHelperWithArg(DirectoryNode *thisNode, string currentPath, bool root)
{
  DirectoryNode *otherNode = new DirectoryNode();

  //cases depending on if is first call or not
  if(root){
    otherNode->parent("..");
    otherNode->path("");
    //  otherNode->name(thisNode->name());
    //otherNode->type(thisNode->type());
  }else{
    //two cases, depenedent if old path is "" or not
    otherNode->parent(currentPath);
    if(currentPath == ""){
      //otherNode->parent(currentPath);//old path
      otherNode->path(thisNode->name());
    }else{
      string modifiedPath = currentPath + "/" + thisNode->name();
      otherNode->path(modifiedPath);
      //currentpath + / + thisNode->name
    }
  }
  
  otherNode->name(thisNode->name());
  otherNode->type(thisNode->type()); 
    
  if(thisNode->isFile()){
    //cout << "this node is a file" << endl;
    otherNode->setFile();
  }
  if(thisNode->isDirectory()){
    //cout << "this node is a directory" << endl;
    otherNode->setDirectory();
    for(int i = 0; i < thisNode->numEntries(); i++){
      otherNode->addDirectoryNode(duplicateHelperWithArg(thisNode->getChildren()[i], otherNode->path(),false));
    }

  }

  return otherNode;

}

/*
DirectoryNode *DirectoryEntry::duplicateHelper(DirectoryNode *thisNode)
{//OUT OF COMMISION YO
  DirectoryNode *otherNode = new DirectoryNode();
  otherNode->parent(thisNode->parent());
  otherNode->path(thisNode->path());
  otherNode->name(thisNode->name());
  otherNode->type(thisNode->type());

  if(thisNode->isFile()){
    //cout << "this node is a file" << endl;
    otherNode->setFile();
  }
  if(thisNode->isDirectory()){
    //cout << "this node is a directory" << endl;
    otherNode->setDirectory();
    for(int i = 0; i < thisNode->numEntries(); i++){
      otherNode->addDirectoryNode(duplicateHelper(thisNode->getChildren()[i]));

    }

  }

  return otherNode; 
}
*/
vector<string> DirectoryEntry::find(string path)
//Find all files and directories whose names contain the path as a substring.
//returned is a vector of node names(string data type)
{
  vector <string>descendants;
  findAdderHelper(this->cwd, path, descendants);
  return descendants;
  
}

void DirectoryEntry::findAdderHelper(DirectoryNode *node,string path, vector<string> &descendants)
//This function will start from cwd,
//Add any node w/ a name having the str param: "path" as a substring to vector: descendants
{
  //cout << "node->name(): " << node->name() << endl;

  if(node->name().find(path) != string::npos){
    //the string path was found inside the name of node, lets push node's name to descendants
    descendants.push_back(node->name());
  }
    //otherwise the path was found at npos(no position)
//only made it in here if path is NOT a substring of node's name
//still want to call on children if node is a directory

  if(node->isDirectory()){
    for (int i = 0; i < node->numEntries(); i++){
      findAdderHelper(node->getChildren()[i], path, descendants);
    }

  }
  return;
  
}

bool DirectoryEntry::hasSubstructure(DirectoryEntry *dirEntry)
{
  if(this->cwd == nullptr || dirEntry->rootDir == nullptr)
    return false;

  //  return hasSubstructure
  return hasSubstructureTraverseHelper(this->cwd, dirEntry->rootDir);
  
}

bool DirectoryEntry::hasSubstructureTraverseHelper(DirectoryNode *thisNode, DirectoryNode *otherNode)
//we want to recursively move through thisNode's children checking a match between thisNode
// against otherNode's structure, in call to "hasSubstructureCheckHelper()
{
  if(hasSubstructureCheckHelper(thisNode, otherNode)){
    //cout << "check helper returned true;" << endl;
    return true;
  }

  if(thisNode->isDirectory()){
    for(int i = 0; i < thisNode->numEntries(); i++){
      
      if(hasSubstructureTraverseHelper(thisNode->getChildren()[i], otherNode))
	return true;
      
    }
  }
  
  return false;
}


bool DirectoryEntry::hasSubstructureCheckHelper(DirectoryNode *thisNode, DirectoryNode *otherNode)
//will return false if the quans are != ; # of kids, type of thisN vs otherN
//if
//recusively call :return  hasSub..Ch..H..r(thisNode->getChildren()[i], otherNode->getChildren()[i])
{
  // if they do not have the same amount of kids then they arent the same structure.
  if(thisNode->getChildren().size() != otherNode->getChildren().size())
    return false;

  for(int i = 0; i < thisNode->numEntries(); i++)
    {

      //if false is ever returned in a call on child it will hit this conditional
      if(thisNode->getChildren()[i]->isDirectory() && otherNode->getChildren()[i]->isDirectory()){
	if(!hasSubstructureCheckHelper(thisNode->getChildren()[i], otherNode->getChildren()[i])){
	  cout << "didnt have match structure" << endl;
	  return false;
	}
      }else if(thisNode->getChildren()[i]->type() != otherNode->getChildren()[i]->type()){

	// if here, it means that one is a directory and one is file, not the same
	return false;
      }

    }

  //return true it made it through all kids of thisnode/othernode
  return true;

  

}

bool DirectoryEntry::areTheSame(DirectoryEntry *dirEntry)
//Return true if the given directory entry identical in structure and name to the entry at cwd.
{
  if(dirEntry->cwd == nullptr || this->cwd == nullptr)
    return false;

  if(this->cwd->name() == dirEntry->cwd->name())
    return identicalHelper(this->cwd, dirEntry->cwd);

  return false;
}

bool DirectoryEntry::identicalHelper(DirectoryNode *thisNode, DirectoryNode *otherNode)
//helper for areTheSame()
{
  // if they do not have the same amount of kids then they arent the same structure.
  if(thisNode->getChildren().size() != otherNode->getChildren().size())
    return false;

  for(int i = 0; i < thisNode->numEntries(); i++)
    {
      if(thisNode->getChildren()[i]->name() != otherNode->getChildren()[i]->name())
	return false;
      
      //if false is ever returned in a call on child it will hit this conditional
      if(thisNode->getChildren()[i]->isDirectory() && otherNode->getChildren()[i]->isDirectory()){
	if(!identicalHelper(thisNode->getChildren()[i], otherNode->getChildren()[i])){
	  cout << "fucked up somewhere " << endl;
	  return false;
	}
      }else if(thisNode->getChildren()[i]->type() != otherNode->getChildren()[i]->type()){

	// if here, it means that one is a directory and one is file, not the same
	return false;
      }

      
    }


  //return true it made it through all kids of thisnode/othernode
  return true;
    
}

void DirectoryEntry::move(string fromPath, string toPath)
/*
  Move the directory entry specified by the fromPath to the directory entry at toPath.
  No changes will be made if the two arguments have the same string value.
*/
{
  if (fromPath == toPath)
    return;

  //check if toPath is valid path
  //check if fromPath is valid path

  //instantiate all 3 DN*s here
  DirectoryNode *fromNode = new DirectoryNode();
  DirectoryNode *toNode = new DirectoryNode();
  DirectoryNode *fromNodeParent = new DirectoryNode();
  
  // assign them here
  // should break & exit if dir @ path doesnt exist
  bool foundFrom = false;
  fromNode = findPathMatch(foundFrom, fromPath, this->rootDir);

  bool foundTo = false;
  cout << "going to look for toPath" << endl;
  toNode = findPathMatch(foundTo, toPath, this->rootDir);
  

  fromNodeParent = fromNode->ParentNode();
  // fromNode = moveFinder(fromPath, this->rootDir)
  // toNode = moveFinder(toPath, this->rootDir)
  // toNodeParent =  toNode->ParentNode();
  //  if(!toNode || toNode->isDirectory()){
  //  cout << "pathTo does not match a directory, returning" << endl;
  //  return;
  //}
  
  //we want to take fromNode out of its parent's vector of children,
  vector<DirectoryNode *> kids;
  //iterate through fromNode's parents
  for(int i = 0; i < fromNodeParent->numEntries() ; i++){
    //add all into vector "kids" execpt pointer matching fromNode
    if(fromNodeParent->getChildren()[i]->path() != fromNode->path())
    //reassign vector to fromNodeParent using N->setDirectoryKidVector(kids)
      kids.push_back(fromNodeParent->getChildren()[i]);

  }
  fromNodeParent->setDirectoryKidVector(kids);
  
  //also we want to reassign the *parentDir of fromN to parent of toNode,
  fromNode->ParentNode(toNode);
  
  //finally, push fromNode into toNodeParent's child vector
  toNode->addDirectoryNode(fromNode);
  
  //we need to push all kids from fromPathNode, into directy sitting at path of toPath
  movePathParentHelper(toNode->path(),fromNode);
  cout << "from nodes path:  " ;
  cout << fromNode->path() << endl;
  
  return;
   
}


void DirectoryEntry::movePathParentHelper(string currentPath, DirectoryNode *node)
//
{
  node->parent(currentPath);
  string modifiedPath = currentPath + "/" + node->name();
  node->path(modifiedPath);

  for(int i = 0; i < node->numEntries(); i++){
    movePathParentHelper(node->path(), node->getChildren()[i]);

  }
  return;
}
