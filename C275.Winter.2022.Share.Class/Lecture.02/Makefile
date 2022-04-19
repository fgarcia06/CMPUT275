# Defining some variables
CC = g++
CC_FLAGS = -c -O2 -Wall -std=c++11

BINARIES = typecheck interactive
OBJS = typecheck.o interactive.o

all: $(BINARIES)

%: %.o
	$(CC) -o $@ $<

%.o: %.cpp
	$(CC) $(CC_FLAGS) $<

clean:
	rm -f $(BINARIES) $(OBJS) *.out
