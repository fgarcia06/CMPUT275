// Based on Zac Friggstad example
#include <iostream>
#include <string>

using namespace std;

template <typename T>
void swapItems(T& arg1, T& arg2) {
	T arg3 = arg1;
	arg1 = arg2;
	arg2 = arg3;
}

short int GX = 0, GY = 100;

int main() {
	int a = 4, b = 0;
	float c = 4.1, d = 0.1;

/*
Python:
a = 4
b = 0
b,a = a,b
print(a,b)

C++:
	int a = 4, b = 0, x = -1;
  x = b;
  b = a;
  a = x;
*/
	swapItems(a,b);
	swapItems(c,d);
	swapItems(GX,GY);

	string k = "there";
	string l = "hello";
	swapItems(k,l);


	cout << a << ' ' << b << endl;
	cout << GX << ' ' << GY << endl;
	cout << c << ' ' << d << endl;
	cout << k << ' ' << l << endl;
}
