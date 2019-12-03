all: prog4

prog4: prog4.cpp RandomizedFitting.o
	g++ -g -std=c++11 -o prog4 prog4.cpp RandomizedFitting.o

RandomizedFitting.o:
	g++ -c RandomizedFitting.cpp

clean:
	rm -f prog4 *.o
