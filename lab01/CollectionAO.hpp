// Assignment : Lab 01
// File : CollectionAO.hpp
// Author : Ian Davidson
// Date  : Spring 2017
#ifndef CollectionAO_hpp
#define CollectionAO_hpp

class CollectionAO {
public:

    CollectionAO();
    CollectionAO(int initialCapacity);

    bool insert(int v);    // insert v into the collection; no duplicates.
    bool remove(int v);    // delete v from the collection.
    bool isMember(int v);  // is v a member of the collection?
    int numMembers(); // how many elements are there in the collection?
    int indexOf(int);  // For testing only!
    ~CollectionAO();

private:

    int *collection;
    int numElements;
    int capacity;

    void extendCapacity();
};


#endif
