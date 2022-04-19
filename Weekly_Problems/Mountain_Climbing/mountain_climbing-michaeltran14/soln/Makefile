TARGET = we7_solution
CC = g++
CFLAGS = -std=c++11 -g
OBJ = climbing.o

all: we7_solution

$(TARGET): $(OBJ)
	$(CC) -o $(TARGET) $(OBJ)

climbing.o: climbing.cpp
	$(CC) $(CFLAGS) -c climbing.cpp

clean: 
	rm -f we7_solution *.o