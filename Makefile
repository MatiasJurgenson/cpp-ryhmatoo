CXXFLAGS := -std=c++20 -Werror -Wall -Wpedantic -Wconversion

funktsioonid.o: funktsioonid.cpp	
	g++  $(CXXFLAGS) -c funktsioonid.cpp

.FORCE:

roulette: main.cpp funktsioonid.o .FORCE
	g++  $(CXXFLAGS) -o roulette main.cpp funktsioonid.o
	./roulette