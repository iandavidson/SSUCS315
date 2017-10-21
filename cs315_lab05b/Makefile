CFLAGS = --std=c++11 -Wall

binTree.x: main.o BinSearchTree.o
	g++ $(CFLAGS) main.o BinSearchTree.o -o binTree.x


BinSearchTree.o: BinSearchTree.cpp BinSearchTree.hpp TreeNode.hpp
	g++ $(CFLAGS) -c BinSearchTree.cpp -o BinSearchTree.o

main.o: main.cpp BinSearchTree.hpp TreeNode.hpp
	g++ $(CFLAGS) -c main.cpp -o main.o

clean:
	rm -f *.o *.x *~
