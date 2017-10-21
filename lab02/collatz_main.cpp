// Assignment : Lab 02
// File : collatz_main.cpp
// Author : Ian Davidson
// Date  : Spring 2017

#include "collatz.hpp"
#include <iostream>
#include <string>

int main()
{
  std::cout << "Entering 15 in to iterative, should be 15, 46, 23, 70, 35.." << std::endl; 

  collatzIterative(15);

  std::cout << "Entering 15 in to recursive, should be 15, 46, 23, 70, 35.." <<std::endl;

  collatzRecursive(15);

  return 0;
}
