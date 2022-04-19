# Makefile for the implementation of Kruskal's MST algorithm and the
# union-find data structure.

CC=g++
CFLAGS=-std=c++11 -g -Wall
OBJS=unionfind.o kruskal.o
PROJECT=kruskal

$(PROJECT): $(OBJS)
	$(CC) $(OBJS) -o $(PROJECT)

kruskal.o: kruskal.cpp unionfind.h
	$(CC) -c kruskal.cpp -o kruskal.o $(CFLAGS)

unionfind.o: unionfind.cpp unionfind.h
	$(CC) -c unionfind.cpp -o unionfind.o $(CFLAGS)

clean:
	-rm -f $(OBJS) $(PROJECT)