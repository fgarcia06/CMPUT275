CC = g++
C_FLAGS = -std=c++11 -Wall -g

all:
	make complex
	make complex2

complex: complex.cpp
	$(CC) $(C_FLAGS) complex.cpp -o complex

complex2: complex2.cpp
	$(CC) $(C_FLAGS) complex2.cpp -o complex2

clean:
	-rm complex complex2
