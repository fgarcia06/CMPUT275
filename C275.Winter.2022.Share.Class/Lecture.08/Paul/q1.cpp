#include <iostream>

class IntArray {
public :
	IntArray (unsigned int size ) {
		asize = size ;
		array = new int[size];
	}
	~IntArray () {
		std::cout << "HERE" << std::endl;	// Debugging output
		delete[] array;
	}
	int& operator[](unsigned int index) {
		return array [ index ];
	}
private :
	int* array;
	unsigned int asize ;
};

int main() {
	IntArray a(10), b(20);
	std::cout << std::endl;		// Easy line to set a breakpoint
	b = a;
	std::cout << std::endl;		// Easy line to set a breakpoint
};
