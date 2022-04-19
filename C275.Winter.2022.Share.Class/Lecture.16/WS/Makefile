CC = g++
C_FLAGS = -std=c++11 -Wall -g

all:
	make sdelim
	make rdelim

sdelim: sender-delim.cpp
	$(CC) $(C_FLAGS) sender-delim.cpp -o sdelim

rdelim: receiver-delim.cpp
	$(CC) $(C_FLAGS) receiver-delim.cpp -o rdelim

reset:
	-rm sharedch*

clean:
	-rm r1 sdelim
	-rm r2 rdelim
	make reset
	-rm *.o
