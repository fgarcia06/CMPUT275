TARGET = we6_solution

CC = g++
CFLAGS = -std=c++11 -g
OBJ = graph_concepts.o digraph.o

all: we6_solution

we6_solution: $(OBJ)
	$(CC) -o $(TARGET) $(OBJ)

graph_concepts.o: graph_concepts.cpp
	$(CC) $(CFLAGS) -c graph_concepts.cpp

digraph.o: digraph.cpp
	$(CC) $(CFLAGS) -c digraph.cpp 

run: we6_solution
	./$(TARGET) < "edmonton-roads-2.0.1.txt"

clean: 
	rm -f we6_solution *.o