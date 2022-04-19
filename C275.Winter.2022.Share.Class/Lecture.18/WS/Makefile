CC = g++
C_FLAGS = -std=c++11 -Wall -g

all:
	make sf
	make rf

sf: sender-file.cpp
	$(CC) $(C_FLAGS) sender-file.cpp -o sf

rf: receiver-file.cpp
	$(CC) $(C_FLAGS) receiver-file.cpp -o rf

reset:
	-rm sharedch*

clean:
	-rm sf
	-rm rf
	-make reset
	-rm *.o
	-rm copy.*
