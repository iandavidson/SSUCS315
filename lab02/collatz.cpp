// Assignment : Lab 02
// File : collatz.cpp
// Author : Ian Davidson
// Date  : Spring 2017

#include "collatz.hpp"
#include <iostream>
#include <string>

void collatzIterative(int n)
// Generate a Collatz sequence for n iteratively.
// parameter n should be a positive integer.
{
  
  do {

    std::cout << n << std::endl;
    
    if (n % 2 == 1){
      n = 3 * n + 1;
    }else{
      n = n/2;
    }  
    

  }while (n != 1);
  
  std::cout << n << std::endl;
  
}



void collatzRecursive(int n)
// Generate a Collatz sequence for n recursively.
// Parameter n should be a positive integer or else function will not terminate.  
{
  if (n == 1){
    std::cout << n << std::endl;
    return;
  }

  std::cout << n << std::endl;

  if (n % 2 == 1)
    return collatzRecursive(n*3 + 1);
  
  return collatzRecursive(n/2);

}
