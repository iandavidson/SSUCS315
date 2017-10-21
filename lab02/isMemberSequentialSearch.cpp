// Assignment : Lab 02
// File : isMemberSequentialSearch.cpp
// Author : Ian Davidson
// Date  : Spring 2017

#include"isMemberSequentialSearch.hpp"
#include<iostream>
#include<cstdlib>


bool isMemberSequentialSearchIterative(int list[], int n, int key)
// list contains n unordered elements. The function uses an iterative
// solution to determine if key is a member of the list or not. That is,
// it returns true if there is an i, 0 < i < n,
// and list[i] == key. Otherwise, the function returns false.
{
  for (int i = 0; i < n; i++){
    if (list[i] == key)
      return true;
  }

  return false;
}


bool isMemberSequentialSearchRecursive(int list[], int n, int key)
// list contains n unordered elements. The function uses a recursive
// solution to determine if key is a member of the list or not. That is,
// it returns true if there is an i, 0 < i < n,
// and list[i] == key. Otherwise, the function returns false.
{
  if (n == 0)
    return false;

  if (list[n-1] == key){

    return true;

  }else{
    return isMemberSequentialSearchRecursive(list, n-1, key);
  }
  
}
