SRC=src

all:	mexpr clean.o

mexpr:	main.o CStringOp.o CMyParser.o CExprParser.o
	g++ main.o CStringOp.o CMyParser.o CExprParser.o -o mexpr

main.o:
	g++ -c $(SRC)/main.cpp

CStringOp.o:
	g++ -c $(SRC)/CStringOp.cpp

CMyParser.o:
	g++ -c $(SRC)/CMyParser.cpp

CExprParser.o:
	g++ -c $(SRC)/CExprParser.cpp

clean:
	rm -rf *.o mexpr

clean.o:
	rm -rf *.o
