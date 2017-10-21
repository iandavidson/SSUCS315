// Assignment : Lab 02
// File : isMemberBinarySearch.cpp
// Author : Ian Davidson
// Date  : Spring 2017

#include"isMemberBinarySearch.hpp"
#include<iostream>
#include<cstdlib>


bool isMemberBinarySearchIterative(int list[], int n, int key)
// list contains n ordered elements. The function uses an iterative
// solution to determine if key is a member of the list or not. That is,
// it returns true if there is an i, 0 < i < n,
// and list[i] == key. Otherwise, the function returns false.
{

  int start = 0;
  int end = n - 1;
  while (true)
    {
      int middleIndex = (start + end)/2;
      int middleValue = list[middleIndex];

      if (middleValue > key){
	end = middleIndex - 1;

      } else if (middleValue < key){
	start = middleIndex + 1;

      } else if (middleValue == key){
	return true;
      }
      if (start > end)
	return false;
    }
}


bool isMemberBinarySearchRecursive(int list[], int n, int key)
// list contains n ordered elements. The function uses a recursive
// solution to determine if key is a member of the list or not. That is,
// it returns true if there is an i, 0 < i < n,
// and list[i] == key. Otherwise, the function returns false. Hint: you may
// have to define another function (a helper function) that would take more
// arguments that provided here. Think about the role of parameter first
// in the recursive function-prototype for the palindrome problem above.
{
  if (n == 0)
    return false;
  
  int start = 0;
  int end = n-1;
  int middleIndex = (start + end)/2;
  int middleValue = list[middleIndex];

  return binarySearchAction( list, key, start, end, middleIndex, middleValue);
  
}

bool binarySearchAction(int list[], int key, int start, int end, int middleIndex, int middleValue)

{
  middleIndex = (start + end)/2;
  middleValue = list[middleIndex];
  
  if (middleValue == key){
    return true;

  }else if( middleValue > key){
    end = middleIndex -1;

  }else{
    start = middleIndex + 1;
  }

  if (start > end)
    return false;

  return binarySearchAction(list, key, start, end, middleIndex, middleValue);
}
