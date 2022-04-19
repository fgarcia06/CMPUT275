#include <iostream>
#include <cstdlib>   // for rand()
using namespace std;

void swap_vals(int& x, int& y) {
	int z = x;
	x = y;
	y = z;
}

int partition(int array[], int num) {
	swap_vals(array[num/2], array[num - 1]);

	int lo_index = 0, hi_index = num - 2;

	while (lo_index <= hi_index) {
		if (array[lo_index] < array[num - 1]) {
			lo_index++;
		}
		else if (array[hi_index] >= array[num - 1]) {
			hi_index--;
		}
		else {
			swap_vals(array[lo_index], array[hi_index]);
		}
	}

	swap_vals(array[num - 1], array[hi_index + 1]);
	return hi_index + 1;
}

int quick_select(int array[], int num, int k) {
	int pivot_index = partition(array, num);

	if (k == pivot_index) {
		return array[k];
	}
	else if (k < pivot_index) {
		return quick_select(array, pivot_index, k);
	}
	else {
		int skipped = pivot_index+1;
		return quick_select(array + skipped, num - skipped, k - skipped);
	}
}


int main(int argc, char** argv) {
        int *array;
	int num = 8;

        array = new int[num];

        cout << "Filling an array with " << num << " random values..." << endl;

        for (int i = 0; i < num; i++) {
                array[i] = rand();
        }

        int k = 3;

        int kth_value = quick_select(array, num, k);

        cout << "The value at index " << k << " in the sorted array is: " << kth_value << endl << endl;

        delete[] array;

        return 0;
}
