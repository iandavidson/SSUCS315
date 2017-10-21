// Assignment : Lab 01
// File : CollectionAU.hpp
// Author : Ian Davidson
// Date  : Spring 2017

#ifndef CollectionAU_hpp
#define CollectionAU_hpp

class CollectionAU {
public:

    CollectionAU();
    CollectionAU(int initialCapacity);

    bool insert(int v);    // insert v into the collection; no duplicates.
    bool remove(int v);    // delete v from the collection.
    bool isMember(int v);  // is v a member of the collection?
    int numMembers();      // how many elements are there in the collection?
    int indexOf(int);      // for testing only.
    ~CollectionAU();

private:

    int *collection;    //* to first
    int numElements;
    int capacity;

    void extendCapacity();

};


#endif
