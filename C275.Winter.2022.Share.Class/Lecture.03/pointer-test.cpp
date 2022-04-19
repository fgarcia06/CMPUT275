#include <iostream>
using namespace std;

int main()
{
	int coins[8] = {1, 5, 10, 25, 50, 100, 200}; // last element is set to zero
	cout << *(coins + 6) << " " << coins[6] << endl;

	int *i_ptr = coins;				// array name is address of the 1st element
	i_ptr = &coins[0];
	
	// increases the ptr value by sizeof(int)
	i_ptr++;	// i_ptr += 1

	cout << *i_ptr + 1 << endl;		// prints 6
	cout << i_ptr[2] << endl;		// prints 25
	cout << *(i_ptr + 1) << endl;	// prints 10

	return 0;
}