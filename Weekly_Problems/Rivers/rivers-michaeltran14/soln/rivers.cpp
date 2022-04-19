/*
  Name: Michael Tran
  SID: 1662870
  CCID: mtran7
  CMPUT 275, Winter 2022

  Weekly Exercise #4: Rivers
*/

#include <iostream>
using namespace std;

/*
Description: Finds the largest # of river where both river u, and river v, meet.

Arguments: 
	a (int pointer): pointer pointing to array of size n
	n (int): size of the array - amount of rivers
	u (int): river u
	v (int): river v

Returns:
	value of highest river #.
*/

int query(int *a, int n, int u, int v){	
	int u_init = u; //store initial values of u and v
	int v_init = v;

	if (u_init == v_init){ //checking if both initial rivers are equal
		return u_init;
	}

	u -= 1;
	v -= 1;

	bool cFlag = true;
	while (cFlag) {
		if (a[u] == a[v]){
			return a[u];
		} else if (a[v] == u_init) { 
		 	return u_init;
		} else if (a[u] == v_init) {
			return v_init;
		} else if (a[v] > a[u]){
			v = a[v] - 1;
		} else if (a[v] < a[u]){
			u = a[u] - 1;
		}
	}
	return 0;
}


/*
Description: the main() function, initializes int n, q, u, v, calls query function. Establishes a
	dynamically allocated array using the new operator, does various for loops for inputs from the terminal

Returns:
	an integer representing the largest value that u and v share in common, printed to the terminal
*/

int main(){
	int n, q, u, v;
	cin >> n >> q;

	int* river = new int[n]; //dynamically allocated array, from the heap

	for (int i = 0; i < n; i++){
		cin >> river[i];
	}

	for (int i = 0; i < q; i++){
		cin >> u >> v;
		cout << query(river, n, u, v) << endl;
	}

	return 0;
}