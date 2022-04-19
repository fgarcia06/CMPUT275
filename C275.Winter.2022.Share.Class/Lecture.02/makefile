# Defining some variables
CC = g++
CC_FLAGS = -c -O2 -Wall -std=c++11

BINARIES = typecheck interactive
OBJS = typecheck.o interactive.o

all: $(BINARIES)

typecheck: typecheck.o
	$(CC) -o typecheck typecheck.o

interactive: interactive.o
	$(CC) -o interactive interactive.o

typecheck.o: typecheck.cpp
	$(CC) $(CC_FLAGS) typecheck.cpp

interactive.o: interactive.cpp
	$(CC) $(CC_FLAGS) interactive.cpp

clean:
	rm -f $(BINARIES) $(OBJS) *.out