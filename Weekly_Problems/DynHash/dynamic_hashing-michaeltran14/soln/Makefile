CC = g++
CFLAGS = -std=c++11 -g -Wall
OBJ = we4_test.o

all: we4_solution

we4_solution: $(OBJ)
	$(CC) -o we4_solution $(OBJ)

we4_test.o: we4_test.cpp dynarray.h linked_list.h hash_table.h
	$(CC) $(CFLAGS) -c we4_test.cpp

clean: 
	rm -f we4_solution *.o