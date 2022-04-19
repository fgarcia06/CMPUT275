CC = g++
C_FLAGS = -std=c++11 -Wall -g

OBJS = digraph.o reachability.o bfs.o dfs.o
BINS = reachability bfs dfs

dfs: dfs.o digraph.o
	$(CC) dfs.o digraph.o -o dfs

dfs.o: dfs.cpp digraph.h
	$(CC) $(C_FLAGS) -c dfs.cpp

bfs: bfs.o digraph.o
	$(CC) bfs.o digraph.o -o bfs

bfs.o: bfs.cpp digraph.h
	$(CC) $(C_FLAGS) -c bfs.cpp

reachability: reachability.o digraph.o
	$(CC) reachability.o digraph.o -o reachability

reachability.o: reachability.cpp digraph.h
	$(CC) $(C_FLAGS) -c reachability.cpp

digraph.o: digraph.cpp digraph.h
	$(CC) $(C_FLAGS) -c digraph.cpp

clean:
	-rm -rf $(BINS) $(OBJS)