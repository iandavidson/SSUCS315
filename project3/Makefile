

CFLAGS = -ggdb -std=c++11 -Wall	


project3.x: main.o Lex.o Token.o
	g++ $(CFLAGS) main.o Lex.o Token.o -o project3.x

Lex.o: Lex.cpp Lex.hpp Token.hpp Token.cpp
	g++ $(CFLAGS) -c Lex.cpp  -o Lex.o 

Token.o: Token.hpp Token.cpp
	g++ $(CFLAGS) -c Token.cpp -o Token.o

main.o: main.cpp Lex.hpp Token.hpp
	g++ $(CFLAGS) -c main.cpp -o main.o

clean:
	rm -f *.o *.x *~
