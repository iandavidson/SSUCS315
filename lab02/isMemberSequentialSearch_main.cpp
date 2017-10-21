// Assignment : Lab 02
// File : isMemberSequentialSearch_main.cpp
// Author : Ian Davidson
// Date  : Spring 2017

#include <iostream>
#include "isMemberSequentialSearch.hpp"
#include <string>

int *readNValues(int numInputValues)
{
  int *numbers = new int[numInputValues];
  int numRead = 0;
  for( int i = 0; i < numInputValues && std::cin >> numbers[numRead++]; i++ )
    ;
  if( numInputValues != numRead ) {
    std::cerr << "Wasn't able to read " << numInputValues << " values; read only " << numRead << " Terminating...\n";
    exit(1);
  }
  return numbers;
}


int main()
{
  int numInputValues;
  std::cin >> numInputValues;
  int *numbers = readNValues(numInputValues);

  /*int numMembers;
  std::cin >> numMembers;
  int *members = readNValues(numMembers);
  */

  int *members = new int[numInputValues];
  std::copy(numbers, numbers+numInputValues, members);

    
  for (int i = 0; i < numInputValues; i++){
    //iterative, providing: numbers[], numInputValues, members[i] 
    if (!isMemberSequentialSearchIterative( numbers, numInputValues, members[i]))
	 std::cout << "numInputValues: " << numInputValues <<" iteration: " << i << std::endl;
  }
  /*
      each of the values in "members" should be a member of "numbers"
  */

  int numNonMembers;
  std::cin >> numNonMembers;
  int *nonMembers = readNValues(numNonMembers);
  /*
      each of the values in "nonMembers" should not be a member of "numbers"
  */
  std::cout << "size of nonMembers: " << numNonMembers << std::endl;
  for (int i = 0; i < numNonMembers; i++){

    if (isMemberSequentialSearchRecursive( numbers, numInputValues, nonMembers[i]))
      std::cout << i << " shouldnt be in numbers but is" << std::endl;
    
  }

  delete [] numbers;
  delete [] members;
  delete [] nonMembers;

  return 0;
}
