CC = g++
C_FLAGS = -std=c++11 -g -Wall
BIN = fib make_change make_change_bu
OBJ = fib.o make_change.o make_change_bu.o

fib: fib.o
	$(CC) fib.o -o fib

fib.o: fib.cpp
	$(CC) $(C_FLAGS) -c fib.cpp

make_change: make_change.o
	$(CC) make_change.o -o make_change

make_change.o: make_change.cpp
	$(CC) $(C_FLAGS) -c make_change.cpp

make_change_bu: make_change_bu.o
	$(CC) make_change_bu.o -o make_change_bu

make_change_bu.o: make_change_bu.cpp
	$(CC) $(C_FLAGS) -c make_change_bu.cpp

clean:
	-rm -f $(BIN) $(OBJ)
