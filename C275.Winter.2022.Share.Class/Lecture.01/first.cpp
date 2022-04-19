#include <iostream>
// using namespace std;
#include "second.h"
#include "third.h"

short implement_budget_cut(short, short);
// int square(int); // function prototype

int main() // function header 
{
	int var = 2; 
	// std::cout << "The value of local variable is: " << var << std::endl;
	std::cout << square(var) << std::endl;
	std::cout << sizeof(int) << " " << sizeof(short) << std::endl;
	std::cout << implement_budget_cut(30000,1500) << std::endl;
	return 0;
}