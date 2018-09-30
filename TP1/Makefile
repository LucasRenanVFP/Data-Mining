exe: tools.o main.o champions.o matches.o pattern.o
	g++ -O2 -std=c++11 tools.o main.o champions.o pattern.o matches.o -o exe
main.o: main.cpp tools.h champions.h
	g++ -O2 -std=c++11 -g -c main.cpp
tools.o: tools.h tools.cpp
	g++ -O2 -std=c++11 -g -c tools.cpp
champions.o: champions.h tools.h champions.cpp
	g++ -O2 -std=c++11 -g -c champions.cpp
matches.o: matches.h tools.h champions.h matches.cpp
	g++ -O2 -std=c++11 -g -c matches.cpp
pattern.o: pattern.h matches.h tools.h champions.h pattern.cpp
	g++ -O2 -std=c++11 -g -c pattern.cpp

clean:
	rm *.o *.gch
	rm mont
