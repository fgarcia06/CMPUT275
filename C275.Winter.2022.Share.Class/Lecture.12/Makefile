CC = g++
C_FLAGS = -std=c++11 -Wall -g
BIN = leaks
OBJ = leaks.o

all: leaks memcheck

memcheck:
	valgrind --tool=memcheck --leak-check=full ./$(BIN)

leaks: leaks.o
	$(CC) leaks.o -o $(BIN)

leaks.o: leaks.cpp
	$(CC) $(C_FLAGS) -c leaks.cpp

clean:
	-rm -f $(BIN) $(OBJ)