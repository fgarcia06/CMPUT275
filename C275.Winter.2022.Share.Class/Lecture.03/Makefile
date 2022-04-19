CC = g++
C_FLAGS = -std=c++11 -Wall -g

BINS = buggy array-test pointer-test reverse
OBJS = buggy.o array-test.o pointer-test.o reverse.o

all: $(BINS)

buggy: buggy.o
	$(CC) -o buggy buggy.o

reverse: reverse.o
	$(CC) -o reverse reverse.o

array-test: array-test.o
	$(CC) -o array-test array-test.o

pointer-test: pointer-test.o
	$(CC) -o pointer-test pointer-test.o

buggy.o: buggy.cpp
	$(CC) $(C_FLAGS) -c buggy.cpp

reverse.o: reverse.cpp
	$(CC) $(C_FLAGS) -c reverse.cpp

array-test.o: array-test.cpp
	$(CC) $(C_FLAGS) -c array-test.cpp

pointer-test.o: pointer-test.cpp
	$(CC) $(C_FLAGS) -c pointer-test.cpp

clean:
	rm -f $(BINS) $(OBJS)