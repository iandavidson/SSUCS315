// Assignment : Lab 02
// File : isSorted.cpp
// Author : Ian Davidson
// Date  : Spring 2017

#include <iostream>
#include "isSorted.hpp"



bool isSortedIterative(int list[], int n)
// list is an array with n elements. The function uses an
// iterative algorithm to return true if the numbers in the array are sorted from
// the smallest (list[0]) to the largest (list[n-1]). An empty
// list is a sorted list!
{
  if (n < 2)
    return true;

  for (int i = 1; i < n - 1; i++){
    if (list[i] < list[i-1])
      return false;
  }
  return true;
}

  

bool isSortedRecursive(int list[], int n)
// list is an array with n elements. The function uses a
// recursive algorithm to return true if the numbers in the array are sorted from
// the smallest (list[0]) to the largest (list[n-1]). An empty
// list is a sorted list!
{
  if (n == 1)
    return true;
  int next = isSortedRecursive( list, n-1);
  if (list[n-1] > next) //see if we can throw in call to iterative in place of return statements;
    return true;
  else
    return false;
}
