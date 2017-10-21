#Ian Davidson, Project1, MakeFile, Spring 2017, cs315


CFLAGS=-std=c++11 -Wall -Wextra -g

# dependencies for PostEvaluator.x:
#PostEvaluator.o, Token.o, Post_main.o, Tokenizer.o, TokenIterator.o, Number.o

Post_main.x : PostEvaluator.o Post_main.o Token.o TokenIterator.o Tokenizer.o Number.o InfixToPostfix.o
	g++ $(CFLAGS) Post_main.o PostEvaluator.o Token.o TokenIterator.o Tokenizer.o Number.o InfixToPostfix.o -o Post_main.x

PostEvaluator.o : PostEvaluator.hpp PostEvaluator.cpp Token.cpp Token.hpp Number.cpp Number.hpp
	g++ $(CFLAGS) PostEvaluator.cpp -o PostEvaluator.o -c

Post_main.o : Post_main.cpp PostEvaluator.hpp Token.hpp InfixToPostfix.hpp TokenIterator.hpp
	g++ $(CFLAGS) Post_main.cpp -o Post_main.o -c



#continue making this





infixToPostfix.x: InfixToPostfix.o Token.o TokenIterator.o main.o
	g++ $(CFLAGS) InfixToPostfix.o Token.o TokenIterator.o main.o -o infixToPostfix.x

InfixToPostfix.o: InfixToPostfix.hpp InfixToPostfix.cpp TokenIterator.hpp Token.hpp
	g++ $(CFLAGS) InfixToPostfix.cpp -o InfixToPostfix.o -c

TokenIterator.o: TokenIterator.hpp TokenIterator.cpp Token.hpp
	g++ $(CFLAGS) TokenIterator.cpp -o TokenIterator.o -c

Token.o: Token.hpp Token.cpp
	g++ $(CFLAGS) Token.cpp -o Token.o -c

main.o: main.cpp Token.hpp InfixToPostfix.hpp TokenIterator.hpp
	g++ $(CFLAGS) main.cpp -o main.o -c

# dependencies for Number
Number.x: Number.o Number_main.o
	g++ $(CFLAGS) -o Number.x Number.o Number_main.o

Number.o: Number.hpp Number.cpp
	g++ $(CFLAGS) -c -o Number.o Number.cpp

Number_main.o: Number.hpp Number_main.cpp
	g++ $(CFLAGS) -c -o Number_main.o Number_main.cpp

# dependencies for Tokenizer
Tokenizer.x: Tokenizer.o Tokenizer_main.o Token.o TokenIterator.o
	g++ $(CFLAGS) Tokenizer.o Tokenizer_main.o Token.o TokenIterator.o -o Tokenizer.x

Tokenizer.o: Tokenizer.hpp Tokenizer.cpp Token.hpp
	g++ $(CFLAGS) -c -o Tokenizer.o Tokenizer.cpp

Tokenizer_main.o: Tokenizer.hpp Tokenizer_main.cpp Token.hpp
	g++ $(CFLAGS) -c -o Tokenizer_main.o Tokenizer_main.cpp


clean:
	rm -f *.o *~ *.x
