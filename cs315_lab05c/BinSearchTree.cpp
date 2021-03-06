/*                             
  Author: Ian Davidson
  Assignment: Lab5c
  File:BinSearchTree.cpp
  Course: CS315 
*/
#include "TreeNode.hpp"
#include "BinSearchTree.hpp"
#include <iostream>
#include <string>
#include <queue>


using namespace std;


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

void BinSearchTree::levelOrderDump()
{
  
  queue<TreeNode *> con;//short for container

  if (!this->root)
    exit(1);

  TreeNode *tempNode = this->root;
  con.push(tempNode);

  while (!con.empty()){
      tempNode = con.front();
      cout << tempNode->value() << endl;
      con.pop();
      
      if(tempNode->leftSubtree())
	con.push(tempNode->leftSubtree());

      if(tempNode->rightSubtree())
	con.push(tempNode->rightSubtree());
  }
		
	  
	  return;
}

bool BinSearchTree::remove( int v )
{


  bool success = false;
  this->root = removeValue(this->root, v, success);
  
  return success;
}




TreeNode *BinSearchTree::removeMinNode(TreeNode *node, int &nextVal)
{
  if(!node->leftSubtree()){
    //node has no left children, bust out of rec. here
    nextVal = node->value();
    return removeNode(node);
  }
  return removeMinNode(node->leftSubtree(), nextVal);
    
}

TreeNode *BinSearchTree::removeValue(TreeNode *node, int v, bool &success)
{
  if(node == 0)
    {
      success = false;
      return nullptr;
    }
  else if (node->value() == v)
    {
      node = removeNode(node);
      success = true;
      return node;
    }
  else if (node->value() > v)
    {
      TreeNode *temp = removeValue(node->leftSubtree(), v, success);
      node->leftSubtree(temp);
      return node;
    }
  else
    {
      TreeNode *temp = removeValue(node->rightSubtree(), v, success);
      node->rightSubtree(temp);
      return node;
    }
}  

TreeNode *BinSearchTree::removeNode(TreeNode *node)
{
  if(!node->leftSubtree() && !node->rightSubtree()){//hates kids
    delete node;
    node = NULL;
    return node;
    }
  else if((!node->leftSubtree() && node->rightSubtree()) || (node->leftSubtree() && !node->rightSubtree()))//one kid
    {
      TreeNode *newNode = new TreeNode();
      if (node->leftSubtree())//child in left subtree
	newNode = node->leftSubtree();
      else
	newNode = node->rightSubtree();
      delete node;
      node = NULL;
      return newNode;
    }
  else //node has 2 kids
    {
      int newNodeValue = 0;
      TreeNode *tempPtr = removeMinNode(node->rightSubtree(), newNodeValue);
      node->rightSubtree(tempPtr);
      node->value() = newNodeValue;
      return node;
    }
}
int BinSearchTree::kthSmallest( int k )
{
  if (k > this->size())
    return 0;

  //  cout << "calls helper" << endl;
  int value = kthSmallestHelper(this->root, k);

  return value;

}

int BinSearchTree::kthSmallestHelper(TreeNode *node, int k)
{
  if(node == nullptr)
    return 0;
  
  int leftCount = helperSize(node->leftSubtree());

  if((k - 1) == leftCount){ //param "node" is kth smallest 
    return node->value();

  //if leftcount is higher then k then, re call w/ left sub
  }else if(leftCount > k - 1){
    return kthSmallestHelper(node->leftSubtree(), k);

  }else{
    return kthSmallestHelper(node->rightSubtree(), k - leftCount - 1);
  }
  
}

void BinSearchTree::valuesAtLevel( int k )
{
  if (k < 1)
    return;

  //  cout << "made it in valuesAtLevel()" << endl;
  valuesAtLevelRecHelper(root, k);

  //cout << "chocolate rain"<< endl;
  return;
}

void BinSearchTree::valuesAtLevelRecHelper(TreeNode *node, int k)
{
  
  if (node == nullptr){
    //cout << "node is nullptr" << endl;
    return;
  }
  
  if (k == 1){
    //cout << node->value() << endl;
    return;
  }

  //call left, right w/ k-1 then return mafer

  valuesAtLevelRecHelper(node->leftSubtree(), k-1);
  //cout << "called left" << endl;
  valuesAtLevelRecHelper(node->rightSubtree(), k-1);
  //cout << "called right" << endl;
  return;
  
}

void BinSearchTree::iterValuesAtLevel( int k )
{
  if (!this->root)
    exit(1);

  if(k < 1)
    {
      cerr << "bad input, exiting" << endl;
      exit(1);
    }
  
  if(k == 1){ //we print the root, this is level 1
    cout << this->root->value() << endl;
    return;
  }
  queue<TreeNode *> q; 
  
  TreeNode *tempNode = this->root;
  q.push(tempNode);

  int qSize = q.size();

  while(k != 1)
    {
      qSize = q.size(); 
      while(qSize != 0){
	//
	tempNode = q.front();
	if(!tempNode){
	  cerr << "tempNode is null" << endl;
	  exit(1);
	} 
	q.pop();//pop
	qSize--;
	if(tempNode->leftSubtree())//push kids
	  q.push(tempNode->leftSubtree());
      
	if(tempNode->rightSubtree())
	  q.push(tempNode->rightSubtree());
	//
      }
      k--;
      
    }


  //print everything in queue
  if(q.size() == 0)
    {
      cout << "K value assigned too high exiting.." << endl;
      exit(1);
    }
  
  while(q.size() != 0)
    {
      tempNode = q.front();
      q.pop();
      cout << tempNode->value() << endl;

    }
  return;
}



int BinSearchTree::iterMaxDepth()
{
  queue<TreeNode *> q;//short for container

  if (!this->root){
    cerr << "broken, root is nullptr" << endl;
    exit(1);
    
  }
  if(!this->root->leftSubtree() && !this->root->rightSubtree())
    return 1;

  int qSize;
  
  TreeNode *tempNode = this->root;
  q.push(tempNode);
  int height = 0;
  
  while(true)
    {
      qSize = q.size();
      if (qSize == 0)
	return height;

      height++;


      while(qSize != 0)
	{
	  TreeNode *node = q.front();
	  q.pop();
	  if(node->leftSubtree())
	    q.push(node->leftSubtree());
	  if(node->rightSubtree())
	    q.push(node->rightSubtree());
	  qSize--;
	}
    }
   
}


bool BinSearchTree::hasRootToLeafSum( int sum )
{

  if(sum < 1)
    return false;
  
  return rootToLeafRec(sum, this->root);


}

bool BinSearchTree::rootToLeafRec(int sum, TreeNode *node)
{
  if(node == nullptr){
    cout << "returned false because node is nullptr" << endl;
    return false;
  }
  if (sum == 1 && node->leftSubtree() == nullptr && node->rightSubtree() == nullptr){
    cout << "returned true, both kids null, sum = 1" << endl;
    return true;
  }
  if (sum == 1 && node->leftSubtree() != nullptr && node->rightSubtree() == nullptr){
    return false;
    cout << "returned false, sum is 1, right kid real left null" << endl;
  }
  if (sum == 1 && node->leftSubtree() == nullptr && node->rightSubtree() != nullptr){
    return false;
    cout << "returned false, sum =1 left kid real, right null" << endl;
  }

  return rootToLeafRec(sum - 1, node->leftSubtree()) || rootToLeafRec(sum - 1, node->rightSubtree());

  
}
bool BinSearchTree::areIdentical( BinSearchTree *bst )
{
  if(bst->root && this->root)//if both roots are non null then continue, otherwise false
    if (this->IDHelper(this->root ,bst->root))
      return true;

  return false;

}

bool BinSearchTree::IDHelper(TreeNode *thisNode,TreeNode *otherNode)
{  
  //good cases checks
      //both kids of both nodes are null => return true;
  if(!thisNode->leftSubtree() && !thisNode->rightSubtree() && !otherNode->rightSubtree() && !otherNode->leftSubtree()){
    if(thisNode->value() == otherNode->value())
      return true;
  }      //left is null, right isnt for both nodes=>return IDHelper on both root->right
  if(!thisNode->leftSubtree() && thisNode->rightSubtree() && otherNode->rightSubtree() && !otherNode->leftSubtree()){
    if(thisNode->value() == otherNode->value())
      return IDHelper(thisNode->rightSubtree(), otherNode->rightSubtree());
}      //right is null, left is good for both=> return IDhelper on both root->left
  if(thisNode->leftSubtree() && !thisNode->rightSubtree() && !otherNode->rightSubtree() && otherNode->leftSubtree()){
    if(thisNode->value() == otherNode->value())
      return IDHelper(thisNode->leftSubtree(), otherNode->leftSubtree());
  }
      //if neither kids are null, on both nodes => return (IDHelper(right) && IDHelper(left))
  if(thisNode->leftSubtree() && thisNode->rightSubtree() && otherNode->rightSubtree() && otherNode->leftSubtree())
    {
      if(thisNode->value() == otherNode->value())
	return IDHelper(thisNode->leftSubtree(), otherNode->leftSubtree()) && IDHelper(thisNode->rightSubtree(), otherNode->rightSubtree());
    }
    //every other case will return false
  return false;

  
}


BinSearchTree *BinSearchTree::intersectWith( BinSearchTree *bst )
{
  BinSearchTree *intersect = new BinSearchTree();

  intersectHelper(intersect, bst, this->root);

  return intersect;
}

void BinSearchTree::intersectHelper(BinSearchTree *intersect, BinSearchTree *otherTree, TreeNode *thisN)

{

  if(thisN == nullptr)
    return;
  
  if(otherTree->find(thisN->value()))
    //insert to intersect
    intersect->insert(thisN->value());
  
  intersectHelper(intersect, otherTree, thisN->leftSubtree());

  intersectHelper(intersect, otherTree, thisN->rightSubtree());  

  return;
}

BinSearchTree *BinSearchTree::unionWith( BinSearchTree *bst )
{
  BinSearchTree *tree = new BinSearchTree();

  //  tree->CopyBinSearchTree(bst);
  queue<int> q;

  unionHelper(q, this->root);
  unionHelper(q, bst->root);

  while(!q.empty())
    {
      int valueToBePumped = q.front();
      q.pop();
      tree->insert(valueToBePumped); //if the nodevalue already exists in 'this' instance
                                     //it won't be added to tree via insert(), insert prohibits having same values in nodes

    }
  return tree;
}

void BinSearchTree::unionHelper(queue<int> &q, TreeNode *node)
{
  if(node->leftSubtree())
    unionHelper(q, node->leftSubtree());

  q.push(node->value());

  if(node->rightSubtree())
    unionHelper(q, node->rightSubtree());  
  

}

BinSearchTree *BinSearchTree::differenceOf( BinSearchTree *bst )
{
  BinSearchTree *dif = new BinSearchTree();
  differenceHelper(dif, bst->root);
  return dif;
}

void BinSearchTree::differenceHelper(BinSearchTree *dif, TreeNode *otherN)
{
  if(!otherN)
    return;

  if(!this->find(otherN->value()))
    dif->insert(otherN->value());

  differenceHelper(dif, otherN->leftSubtree());//left call

  differenceHelper(dif, otherN->rightSubtree());//rightcall

  return;
}
