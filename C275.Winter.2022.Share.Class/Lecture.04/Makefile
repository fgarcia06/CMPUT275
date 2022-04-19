CC = g++
C_FLAGS = -std=c++11 -Wall

BINS = struct-test const-ptr-ref passing-arguments
OBJS = struct-test.o const-ptr-ref.o passing-arguments.o

all: $(BINS)

struct-test: struct-test.o 
	$(CC) -o $@ $<

const-ptr-ref: const-ptr-ref.o 
	$(CC) -o $@ $<

passing-arguments: passing-arguments.o 
	$(CC) -o $@ $<

struct-test.o: struct-test.cpp 
	$(CC) $(C_FLAGS) -c $<

const-ptr-ref.o: const-ptr-ref.cpp 
	$(CC) $(C_FLAGS) -c $<

passing-arguments.o: passing-arguments.cpp 
	$(CC) $(C_FLAGS) -c $<

clean:
	rm -rf $(BINS) $(OBJS)