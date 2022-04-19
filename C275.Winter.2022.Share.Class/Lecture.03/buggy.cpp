#include <iostream>
using namespace std;

int adder(int a, int b)
{
	int *ptr = nullptr;
	*ptr = 100;
	cout << ptr << " " << *ptr << endl;
	return a + b;
}

int main()
{
	int sum = adder(10, -2);
	return 0;
}