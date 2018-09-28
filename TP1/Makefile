exe: tools.o main.o champions.o
	g++ -std=c++11 tools.o main.o champions.o -o exe
main.o: main.cpp tools.h champions.h
	g++ -std=c++11 -g -c main.cpp
tools.o: tools.h tools.cpp
	g++ -std=c++11 -g -c tools.cpp
champions.o: champions.h tools.h champions.cpp
	g++ -std=c++11 -g -c champions.cpp

clean:
	rm *.o *.gch
	rm mont
