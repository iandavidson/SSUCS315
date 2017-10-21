#ian davidson, project4, spring2017, Dr. Kooshesh cs315

CFLAGS = -ggdb -std=c++11 -Wall


de.x: main.o Lex.o Token.o DirectoryNode.o DirectoryEntry.o #buildDirectoryEntry.o
	g++ $(CFLAGS) main.o Lex.o Token.o DirectoryNode.o DirectoryEntry.o -o de.x  # buildDirectoryEntry.o -o de.x


DirectoryEntry.o: DirectoryEntry.cpp DirectoryEntry.hpp DirectoryNode.cpp DirectoryNode.hpp
	g++ $(CFLAGS) -c DirectoryEntry.cpp -o DirectoryEntry.o

DirectoryNode.o: DirectoryNode.cpp DirectoryNode.hpp
	g++ $(CFLAGS) -c DirectoryNode.cpp -o DirectoryNode.o

Lex.o: Lex.cpp Lex.hpp Token.hpp Token.cpp
	g++ $(CFLAGS) -c Lex.cpp  -o Lex.o 

Token.o: Token.hpp Token.cpp
	g++ $(CFLAGS) -c Token.cpp -o Token.o

main.o: main.cpp Lex.hpp Token.hpp buildDirectoryEntry.cpp DirectoryEntry.hpp DirectoryEntry.cpp DirectoryNode.hpp DirectoryNode.cpp
	g++ $(CFLAGS) -c main.cpp -o main.o

#buildDirectoryEntry.o: buildDirectoryEntry.cpp
#	g++ $(CFLAGS) -c buildDirectoryEntry.cpp -o buildDirectoryEntry.o

clean:
	rm -f *.o *.x *~
