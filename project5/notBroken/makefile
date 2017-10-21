
screen.x: getChar.o screen.o board.o coord.o worm.o game.o
	g++ $(CFLAGS)  screen.o getChar.o board.o coord.o worm.o game.o $(CURSES) -o screen.x

screen.o: screen.cpp Game.hpp 
	g++ -c $(CFLAGS) screen.cpp -o screen.o

game.o: Game.hpp Game.cpp Board.hpp
	g++ -c $(CFLAGS) Game.cpp -o game.o

coord.o:  Coord.hpp Coord.cpp
	g++ -c $(CFLAGS) Coord.cpp -o coord.o

worm.o:  WormQueue.cpp WormQueue.hpp Coord.hpp 
	g++ -c $(CFLAGS) WormQueue.cpp -o worm.o


getChar.o: getChar.cpp getChar.hpp
	gcc -c $(CFLAGS) getChar.cpp -o getChar.o
#       g++ -c -ggdb getChar.cpp -o getChar.o

board.o: Board.hpp Board.cpp Coord.hpp WormQueue.hpp
	g++ -c $(CFLAGS) Board.cpp -o board.o

clean:
	/bin/rm -f screen.x screen.o getChar.o *~ *.o

CFLAGS = -ggdb -std=c++11     #-Wall
CURSES = -lcurses -ltermcap


#test recipies
board.x: board_main.o board.o worm.o coord.o
	g++ $(CFLAGS) board_main.o board.o worm.o coord.o -o board.x

board_main.o:	Board_main.cpp
	g++ $(CFLAGS) -c  Board_main.cpp -o board_main.o
