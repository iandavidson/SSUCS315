#Ian Davidson, 315, Lab01, Spring 2017

all: collectionAU.x collectionAO.x

FLAGS= -ggdb -std=c++11 -Wall -Wextra

CollectionAU.o: CollectionAU.hpp CollectionAU.cpp
	g++ $(FLAGS) -c CollectionAU.cpp -o CollectionAU.o

main_CollectionAU.o: main_CollectionAU.cpp CollectionAU.hpp
	g++ $(FLAGS) -c main_CollectionAU.cpp -o main_CollectionAU.o

collectionAU.x: CollectionAU.o main_CollectionAU.o
	g++ $(FLAGS) CollectionAU.o main_CollectionAU.o -o collectionAU.x

CollectionAO.o: CollectionAO.hpp CollectionAO.cpp
	g++ $(FLAGS) -c CollectionAO.cpp -o CollectionAO.o

main_CollectionAO.o: main_CollectionAO.cpp CollectionAO.hpp
	g++ $(FLAGS) -c main_CollectionAO.cpp -o main_CollectionAO.o

collectionAO.x: CollectionAO.o main_CollectionAO.o
	g++ $(FLAGS) CollectionAO.o main_CollectionAO.o -o collectionAO.x

clean:
	rm *.o *.x *~
