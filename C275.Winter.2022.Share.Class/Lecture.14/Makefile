CC = g++
C_FLAGS = -std=c++11 -Wall -g

OBJS = digraph.o dijkstra.o test.o
BINS = dijkstra test

dijkstra: digraph.o dijkstra.o
	$(CC) digraph.o dijkstra.o -o dijkstra

dijkstra.o: dijkstra.cpp wdigraph.h
	$(CC) $(C_FLAGS) -c dijkstra.cpp

test: digraph.o test.o
	$(CC) test.o digraph.o -o test

test.o: weighted_graph_test.cpp wdigraph.h
	$(CC) $(C_FLAGS) -c weighted_graph_test.cpp -o test.o

digraph.o: digraph.cpp digraph.h
	$(CC) $(C_FLAGS) -c digraph.cpp

clean:
	-rm -rf $(BINS) $(OBJS)