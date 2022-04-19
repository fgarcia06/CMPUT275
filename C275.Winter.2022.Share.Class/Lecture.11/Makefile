CC = g++
C_FLAGS = -std=c++11 -Wall -g

OBJS = digraph.o digraph_test.o digraph_builder.o account.o
BINS = digraph builder account

builder: digraph_builder.o digraph.o
	$(CC) digraph_builder.o digraph.o -o builder

digraph: digraph_test.o digraph.o
	$(CC) digraph_test.o digraph.o -o digraph

digraph_builder.o: digraph_builder.cpp digraph.h
	$(CC) $(C_FLAGS) -c digraph_builder.cpp

digraph_test.o: digraph_test.cpp digraph.h
	$(CC) $(C_FLAGS) -c digraph_test.cpp

digraph.o: digraph.cpp digraph.h
	$(CC) $(C_FLAGS) -c digraph.cpp

account: account.o
	$(CC) account.o -o account

account.o: account.cpp account.h
	$(CC) $(C_FLAGS) -c account.cpp

clean:
	-rm -rf $(BINS) $(OBJS)