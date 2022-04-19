CC = g++
C_FLAGS = -std=c++11 -Wall -g

all:
	make shp
	make rhp
	make sf
	make rf


shp: sender-hp.cpp
	$(CC) $(C_FLAGS) sender-hp.cpp -o shp

rhp: receiver-hp.cpp
	$(CC) $(C_FLAGS) receiver-hp.cpp -o rhp

sf: sender-file.cpp
	$(CC) $(C_FLAGS) sender-file.cpp -o sf

rf: receiver-file.cpp
	$(CC) $(C_FLAGS) receiver-file.cpp -o rf

reset:
	-rm sharedch*

clean:
	-rm shp
	-rm rhp
	-rm sf
	-rm rf
	-make reset
	-rm *.o
