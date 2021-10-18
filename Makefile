
CCPP=g++
# SOURCES=sdl_functions.cpp main.cpp
CPPFLAGS= -lm -O2 -pedantic -Wall
FLAGS=$(CPPFLAGS)

all:
	$(CCPP) -o executable main.cpp $(wildcard *.o) $(CPPFLAGS)

2dkp.o: src\2dkp.cpp
	$(CCPP) -c src\2dkp.cpp $(CPPFLAGS)

functions.o: src\functions.cpp 2dkp.o
	$(CCPP) -c src\functions.cpp $(CPPFLAGS)



