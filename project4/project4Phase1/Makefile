CFLAGS = -ggdb -std=c++11 -Wall	

phase1.x: buildRecursiveList.o Lex.o ListNode.o
	g++ $(CFLAGS) buildRecursiveList.o Lex.o ListNode.o -o phase1.x

buildRecursiveList.o: buildRecursiveList.cpp Lex.hpp Token.hpp ListNode.hpp
	g++ $(CFLAGS) -c buildRecursiveList.cpp -o buildRecursiveList.o

#linearlyNested_rec.x: linearlyNestedParentheses_rec.o Lex.o 
#	g++ $(CFLAGS) linearlyNestedParentheses_rec.o Lex.o -o linearlyNested_rec.x

ListNode.o: ListNode.hpp ListNode.cpp
	g++ $(CFLAGS) -c ListNode.cpp -o ListNode.o

Lex.o: Lex.cpp Lex.hpp Token.hpp
	g++ $(CFLAGS) -c Lex.cpp  -o Lex.o 

#Token.o: Token.hpp
#	g++ $(CFLAGS) -c Token.hpp -o Token.o
#linearlyNestedParentheses_rec.o: linearlyNestedParentheses_rec.cpp Lex.hpp Token.hpp
#	g++ $(CFLAGS) -c linearlyNestedParentheses_rec.cpp -o linearlyNestedParentheses_rec.o 

clean:
	rm -f *.o *.x *~
