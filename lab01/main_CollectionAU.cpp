// Assignment : Lab 01
// File : main_CollectionAU.cpp
// Author : Ian Davidson
// Date  : Spring 2017

#include<cassert>
#include<iostream>
#include<cstdlib>
#include "CollectionAU.hpp"

const int INITIAL_CAPACITY = 30;    // Always start with this value to create
// instances of Collection data type.

int main()
{
    CollectionAU *collection = new CollectionAU(INITIAL_CAPACITY);

    collection->insert(25);
    if( ! collection->isMember(25) ) {
        std::cout << "Insert not reliable!\n";
        exit(1);
    }
    collection->remove(25);
    if( collection->numMembers() != 0 ) {
        std::cout << "Not able to count right!\n";
        exit(2);
    }
    for( int i = 0; i < 100; i++ )
      {
	std::cout << i;
	collection->insert(i);
      }
    for( int i = 0; i < 100; i++ )
        assert( collection->isMember(i) );

    for( int i = 99; i >= 0 ; i-- ) {
        collection->remove(i);
        // i shouldn't be a member as we just removed it
        assert( ! collection->isMember(i) );
        // all other members should still be present
        for( int j = 0; j < i ; j++ )
            assert( collection->isMember(j) );
    }
    delete collection;
    return 0;
}
