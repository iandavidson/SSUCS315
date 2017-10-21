Ian Davidson
cs315 SSU
Spring 2017
Project3

	My .json parser works correctly as instructed, the classes Token and Lex are used
	to parse the json file. Main also takes the input file as an argument. So the steps
	to build executable would first be "make", then "project.x nameOfInputFile.json" will
	run the executable. Of course with nameOfInputFile.json being the .json input to be
	parsed.
	
	Line 53 in my project_sample_input.json demonstrateds the usage of using
	a backslash to escape a character.
	
	The class Token only has one implementation in the .cpp file because print()
	is the only function requiring more than one line of implementation. I also
	added some helper functions Token, to make checking for expected tokens easier.

	The class Lex has added functions called parseElement(), isValue() and parseValue().
	The function parseElement() deals with the unquoted strings, while parseValue() deals
	singly quoted strings. In addition, isValue() is used to check for accepted
	syntax while parsing quoted strings.

	
