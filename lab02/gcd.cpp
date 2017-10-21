// Assignment : Lab 02
// File : gcd.cpp
// Author : Ian Davidson
// Date  : Spring 2017

#include"gcd.hpp"
#include<iostream>
#include<cstdlib>

int gcdIterative(int a, int b)
// pre-condition: a < b is true.
// The function finds and returns the gcd of a and b using an
// iterative solution.
{
  while (a != b){

    if (a < b){
	b-=a;
      
    } else {
       a-=b;
    }
  }
    return a;
}


  
int gcdRecursive(int a, int b)
// pre-condition: a < b is true.
// The function finds and returns the gcd of a and b using a
// recursive solution.
{
  if (a < b){
    //    std::cout << a << std::endl << b << std::endl << std::endl;
    return gcdRecursive(a, b-a);
    
  }if (a > b){
    //std::cout << a << std::endl << b << std::endl << std::endl;
    return gcdRecursive(a-b, b);
  }else{

    return a;
  }
}
