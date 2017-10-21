// Assignment : Project 1
// File : README.txt
// Author : Ian Davidson
// Date  : Spring 2017

The purpose of this text file is to explain what works and doesnt work.

All programs compile using Makefile .


Number class:
	works fine, Both intValue() and romanValue() do their specific jobs correctly,
       	testing done with MakeFile and main is in Number_main.cpp.

Tokenizer class's function Tokenize():
	correctly inputs Tokens to vector, but the vector returned (with a eol Token at last
	element) won't be accepted by the InfixToPostfix, member function convert(). This class
	is tested using Tokenizer_main.cpp.

PostEvaluator class:
	The functionality of the class is to take the vector of Token* (originally created by Tokenizer class) and
	return the int value of the expression. This class was tested using Post_main.cpp.


Token class:
	I made mutator and accessor functs for Token being able to interpret/store integer type.


TokenIterator class:
	Didn't edit, used directly from resources provided.

InfixToPostfix class:
	Nothing edited. I had trouble getting my Tokenizer class to work properly with this class in Post_main.cpp.
	

	  


