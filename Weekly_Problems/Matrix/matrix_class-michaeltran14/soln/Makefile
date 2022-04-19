TARGET = we5_solution

CC = g++
CFLAGS = -std=c++11 -g -Wall
OBJ = we5_test.o matrix.o

all: we5_solution

we5_solution: $(OBJ)
	$(CC) -o $(TARGET) $(OBJ)

matrix.o: matrix.cpp matrix.h
	$(CC) $(CFLAGS) -c matrix.cpp matrix.h

we5_test.o: we5_test.cpp
	$(CC) $(CFLAGS) -c we5_test.cpp

clean: 
	rm -f we5_solution *.o