// Assignment : Lab 02
// File : isMemberBinarySearch.hpp
// Author : Ian Davidson
// Date  : Spring 2017

#ifndef _isMemberBinarySearch_hpp
#define _isMemberBinarySearch_hpp

#include<iostream>
#include<cstdlib>

extern bool isMemberBinarySearchIterative(int list[], int n, int key);

extern bool isMemberBinarySearchRecursive(int list[], int n, int key);

//helper function for recursive binary search
extern bool binarySearchAction(int list[], int key, int start, int end, int middleIndex, int middleValue);
  

#endif
