/*
	Variation 2

	A simple demonstration of how to use command-line arguments.

	The second half of the program assumes the parameters are "A <num1> <num2>"
	and it will print the sum of the two numbers.

	Course: CMPUT 275
	Zac Friggstad, 2021

	Modified by Paul Lu, 2022
*/

#include <iostream>
using namespace std;

// In C++/C:
//    "string"	--> char name[40];
//		--> char * name;   name = new char[40]
// int main(int argc, char** argv) {

int main(int argc, char* argv[]) {
	char * name;
	name = new char[40];
	name[0] = 'X';
	name[1] = '\0';

	cout << "Number of parameters: " << argc << endl;

	// now print out each parameter
	cout << "Parameters:" << endl;
	for (int i = 0; i < argc; i++) {
		cout << "argv[" << i << "] = " << argv[i] << endl;
	}
	cout << endl;

	return 0;
}
