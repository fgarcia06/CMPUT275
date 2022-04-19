#include <iostream>

using namespace std; 
// Be careful! there's a function called binary_search
// in namespace std

void bsearch(int * sorted_array, int size, int q) {
	int high = size, low = 0, mid;
	while (low < high) {
		mid = (high + low)/2;
		if (sorted_array[mid] == q) {
			cout << mid << endl;
			return;
		} else if (sorted_array[mid] > q) {
			high = mid;
		} else {
			low = mid + 1;
		}
	}
	cout << "Not found" << endl;
	return;
}

int main() {
	int count, query;
	cin >> count;

	// numbers in ascending order
	int * sorted_array = new int[count];

	for (int i=0;i<count;++i)
		cin >> sorted_array[i];

	cin >> query;
	bsearch(sorted_array, count, query);

	delete [] sorted_array;
	sorted_array = NULL;

	return 0;
}
