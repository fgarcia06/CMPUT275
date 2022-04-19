CC = g++
C_FLAGS = -g -Wall -std=c++11
OBJS = heaptest.o pqueuetest.o
BINS = heaptest pqueuetest

heaptest: heaptest.o
	$(CC) heaptest.o -o heaptest

heaptest.o: heaptest.cpp min-heap.h
	$(CC) $(C_FLAGS) -c heaptest.cpp

pqueuetest: pqueuetest.o
	$(CC) pqueuetest.o -o pqueuetest

pqueuetest.o: pqueuetest.cpp
	$(CC) $(C_FLAGS) -c pqueuetest.cpp

clean:
	-rm -f $(BINS) $(OBJS)