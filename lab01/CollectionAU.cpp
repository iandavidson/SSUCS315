// Assignment : Lab 01
// File : CollectionAU.cpp
// Author : Ian Davidson
// Date  : Spring 2017

#include<cassert>
#include<iostream>
#include "CollectionAU.hpp"

static const int defaultCapacity = 30;

CollectionAU::CollectionAU(): numElements(0), capacity(defaultCapacity)
{
    collection = new int[defaultCapacity];
}

CollectionAU::CollectionAU(int initialCapacity): numElements(0)
{
    capacity = initialCapacity <= 0 ? defaultCapacity : initialCapacity;
    collection = new int[capacity];
}

bool CollectionAU::insert(int v)
{
    // Since for this example, we don't expand the capacity of the
    // array, insert terminates the program if the array is full.
    if (isMember(v))
        return false;
    if (numElements >= capacity)
        extendCapacity();
    
    //assert( numElements < capacity );
    collection[numElements++] = v;
    return true;
}

bool CollectionAU::remove(int v)
{
    int idx = indexOf(v);
    if ( idx < 0)
        return false; // v is not a member

    // the collection is unordered, swap the element to be removed
    // with the last element.
    int tmp = collection[idx];
    collection[idx] = collection[numElements-1];
    collection[numElements-1] = tmp;
    numElements--;
    return true;    //successfully removed v

}

bool CollectionAU::isMember(int v)
{
    return indexOf(v) >= 0;
}

int CollectionAU::indexOf(int v)
{
    // Return i, 0 <= i < numMembers(), if collection[i] == v. Otherwise, return -1.
    for( int i = 0; i < numElements; i++)
        if (collection[i] == v)
	  return i; // search was successful
    return -1; // report an unsuccessful search
}

int CollectionAU::numMembers()
{
    return numElements;
}

void CollectionAU::extendCapacity()
{
    capacity = capacity + (capacity/2);     //creates new capacity 50% larger
    int* newC = new int[capacity]; //creates the to-be new array
    std::copy(collection, collection+numElements, newC);
    delete [] collection;
    collection = newC;

}


CollectionAU::~CollectionAU()
{
    // [] in Delete uses the same form to recycle the memory.
    delete [] collection;

}
