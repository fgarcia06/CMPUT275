CC = g++
C_FLAGS = -std=c++11 -Wall

cl: commandline.cpp
	$(CC) $(C_FLAGS) commandline.cpp -o cl
	$(CC) $(C_FLAGS) -g commandline.cpp -o clg

argv: argv.cpp
	$(CC) $(C_FLAGS) -g argv.cpp -o argv

pc:
	make argv
	./argv a b c d
	python3 ./argv.py a b c d

clean:
	-rm cl clg argv
