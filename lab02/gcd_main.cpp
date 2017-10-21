// Assignment : Lab 02
// File : gcd_main.cpp
// Author : Ian Davidson
// Date  : Spring 2017

#include"gcd.hpp"
#include<iostream>
#include<cstdlib>
#include<string>


int main()
{
  int tinyNum = 18;
  int bigNum = 45;

  std::cout << "gcdItr() should be 9: " << gcdIterative(tinyNum, bigNum) << std::endl;

  std::cout << "gcdRec() should be 9: " << gcdRecursive(tinyNum, bigNum) << std::endl;





  return 0;
}
