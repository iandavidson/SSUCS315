// Assignment : Lab 01
// File : CollectionAO.cpp
// Author : Ian Davidson
// Date  : Spring 2017
#include<cassert>
#include<iostream>
#include "CollectionAO.hpp"

static const int defaultCapacity = 30;

CollectionAO::CollectionAO(): numElements(0), capacity(defaultCapacity)
{
    collection = new int[defaultCapacity];
}

CollectionAO::CollectionAO(int initialCapacity): numElements(0)
{
    capacity = initialCapacity <= 0 ? defaultCapacity : initialCapacity;
    collection = new int[capacity];
}

bool CollectionAO::insert(int v)
{
    // insert adds more space via extendCapacity() if the array is full.
    if (isMember(v))
      return false;
    if (numElements == capacity)// if the # of elements == capacity, means were full capacity
      extendCapacity();
    
    
    //correct placement to keep order

    //size 0 case handled
    if (numElements == 0){
      collection[0] = v;
      numElements++;
      return true;
    }

    //this loop walkes from the end of the array until the index of where param v belongs
    int v_idx = numElements - 1;
    
    while ((v_idx > 0) && (v < collection[v_idx - 1])){

      collection[v_idx] = collection[v_idx-1];
    }

    collection[v_idx] = v;	 

    numElements++;
    // collection is now sorted and ready to hit it
    return true;
}

bool CollectionAO::remove(int v)
{
  
  int idx = indexOf(v);
    if ( idx < 0)
        return false; // v is not a member

    // the collection is ordered, swap the element to be removed
    // with the last element.

    for (int i = 0; i < (numElements - (idx + 1)); i++){
      collection[idx + i] = collection[idx + (i + 1)];
    }


    numElements--;
    return true;
}

bool CollectionAO::isMember(int v)
{
        //has to be in log time, use binary search
  int start = 0;
  int end = numElements - 1;
  while (true)
    {
      int middle_index = (start + end)/2;
      int middle_value = collection[middle_index];

      if (middle_value > v){
	end = middle_index - 1;

      } else if (middle_value < v){
	start = middle_index + 1;
	
      } else if (middle_value == v){
	return true;
      }
      if (start > end)
	return false;

    }
  
}

int CollectionAO::indexOf(int v)
{
    // Return i, 0 <= i < numMembers(), if collection[i] == v. Otherwise, return -1.
    for( int i = 0; i < numElements; i++)
        if (collection[i] == v)
            return i;
    return -1; // report an unsuccessful search
}

int CollectionAO::numMembers()
{
    return numElements;
}

void CollectionAO::extendCapacity()
{
    capacity = capacity + (capacity/2);     //creates new capacity 50% larger
    int* newC = new int[capacity]; //creates the to-be new array
    std::copy(collection, collection+numElements, newC);
    delete [] collection;
    collection = newC;

}

CollectionAO::~CollectionAO()
{
    // Pay attention to the array declarator symbols, [] in Delete uses the same form
    // to recycle the memory.
    delete [] collection;

}
