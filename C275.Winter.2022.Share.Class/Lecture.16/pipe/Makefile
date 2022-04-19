CC = g++
C_FLAGS = -std=c++11 -Wall -g

all:
	make r1
	make w1
	make r2
	make w2

r1: reader.cpp
	$(CC) $(C_FLAGS) reader.cpp -o r1

w1: writer.cpp
	$(CC) $(C_FLAGS) writer.cpp -o w1

r2: multiline_reader.cpp
	$(CC) $(C_FLAGS) multiline_reader.cpp -o r2

w2: multiline_writer.cpp
	$(CC) $(C_FLAGS) multiline_writer.cpp -o w2

reset:
	-rm pipe*

clean:
	-rm r1 w1
	-rm r2 w2
	make reset
	-rm *.o
