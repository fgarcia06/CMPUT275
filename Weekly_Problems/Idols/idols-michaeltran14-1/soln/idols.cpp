/*
  Name: Michael Tran
  ID: 1662870
  CCID: mtran7
  CMPUT 275, Winter 2022

  Weekly Exercise #2: Idols
*/

#include <iostream> //for cin, cout, and endl
using namespace std;


//this function takes parameters of two int pointers; begin and end. 
//while the memory address of the begin pointer is less than the memory address of the end pointer, they will swap.
void reverse (int* begin, int* end) {

	while (begin < end){
		int temp = *begin; //temporary variable holding the dereferenced begin pointer
		if (begin != end) {
			*begin = *end;
			*end = temp;
		}
		begin++; 
		end--;
	}	
}

//idol function takes parameters an int array, and an int variable
//the purpose of this function is find the idols of a given string of integers, by looping through the array checking if the particular index is greater than the values after it
int idols(int a[], int n) {
	int idol_array[100000], c_idol = a[n-1], n_index = 0, o_index = n-1, index = 1, *p;
	p = a; //setting the pointer to the array

	idol_array[0] = c_idol; //the last index is an idol
	for (int i = n-1; i >= 0; i--){
		if (a[i] > c_idol){ //checking if current index is an idol
			n_index = i;
			c_idol = a[i];
			idol_array[index] = a[i];
			index += 1;

			if (p+n_index+1 != p+o_index){ //checking if the pointer is at the same index
				reverse((p+n_index+1), (p+o_index-1));
			}
			o_index = n_index; //set the new idol as an old idol
		} else if ((i == 0) && a[i] <= c_idol && n_index == 0){ //taking the case where the only idol is the last index
			reverse(p, p+(n-2));
		} else if ((i == 0) && a[i] <= c_idol) {
			reverse(p, p+o_index-1);
		}
	}


	for (int i = index-1; i >= 0; i--){
		if (i > 0){
			cout << idol_array[i] << " ";
		} else {
			cout << idol_array[i] << endl;
		} 
	}

	for (int i = 0; i < n; i++){
		if (i != n-1){
			cout << *(p+i) << " ";
		} else {
			cout << *(p+i) << endl;
		} 
	}
	return 0;
}

//setting the const size of the array, and taking the array indexes as input
//calls idols
int main(){
	const int size = 100000;
	int n, array[size];

	cin >> n;

	for (int i = 0; i < n; i++){
		cin >> array[i];
	}

	idols(array, n);
	return 0;
}