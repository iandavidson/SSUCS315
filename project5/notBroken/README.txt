Ian Davidson
Cs315
Project 5
Spring 2017


	This project works as the instructions say it should. The command to build the
	executable is "make",  the executable should be called screen.x. Then to
	run the executable the command would be " ./screen.x <rows> <cols>" the number
	of rows wanted would be argv[1], and the number of cols wanted would be argv[2].

	I used the class Game to work with curses and provide an interface to main(). My class
	Board holds the specific structures used such as the WormQueue, FreePool, and 2d Board.
	For the 2d board structure I actually used a vector of ints. My FreePool and WormQueue
	structures held instances, of a class I made called Coord. The Class Coord has an XY Value
	that is very appropriate to use as my 2d grid as an inverted list referencing the FreePool
	indicies.



	

	
