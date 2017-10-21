// Assignment : Lab 02
// File : isPal.hpp
// Author : Ian Davidson
// Date  : Spring 2017

#include"isPal.hpp"
#include<iostream>
#include<cstdlib>


bool isPalIterative(const char *s, int n)
// s contains n characters. The function uses an iterative
// algorithm to determine if s contains a string that is a palindrome or
// not.
{
  if (n < 2){
    return true;
  }
  
  for (int i = 0; i < n/2; i++){
    if (s[i] != s[n-1-i])
      return false;
  }
  return true;

}
  /*
{
  if (n % 2 == 1){
    for (int i = 1; i < n/2 + 1; i++){
      if ((n/2 + i) != (n/2 - i))
	return false;
    }return true;

  }else{
    for (int i = 0; i < n/2; i++){
      if (n/2 + i != n/2 - (i + 1))
	return false;
    }
  }
    
}
*/


bool isPalRecursive(const char *s, int start, int n)
// s contains n characters. The function uses a recursive
// algorithm to determine if s contains a string that is a palindrome or
// not. When the function is called for the first time,  start will
// contain zero, the index of the first element of s.
{
  if (n < 2)
    return true;

  //  std::cout << s[start] << std::endl;
  // std::cout << s[n-1] << std::endl;
  if (s[start] != s[n-1])
    return false;
  return isPalRecursive(s, start + 1, n - 1);



}
