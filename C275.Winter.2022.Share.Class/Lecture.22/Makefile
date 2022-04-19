CC = g++
C_FLAGS = -std=c++11 -Wall -g
EXE = knapsack
OBJ = knapsack.o

knapsack: knapsack.o
	$(CC) knapsack.o -o knapsack

knapsack.o: knapsack.cpp
	$(CC) $(C_FLAGS) -c knapsack.cpp

clean:
	-rm -f $(EXE) $(OBJ)