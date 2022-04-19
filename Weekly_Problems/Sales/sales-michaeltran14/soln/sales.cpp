/*
  Name: Michael Tran
  SID: 1662870
  CCID: mtran7
  CMPUT 275, Winter 2022

  Weekly Exercise #3: Sales
*/

#include <iostream> //cout, cin
using namespace std;

//sales takes n, target price T, and the prices array, and calculates whether there is a pair sum in the array matches the target price
//if the sum equals the target price, "YES" is printed, "NO" otherwise.
void sales(int n, int T, unsigned long long p[250000]) {
	int min_p, drop = 0, up = 0, max_p, sum;
	bool cFlag = true;

	max_p = p[n-1]; //set the max price equal to the last index in the array


	for (int i = n; i >= 0; i--){
		min_p = p[up];
		sum = (max_p + min_p);

		if (sum > T) { //if the sum > T drop the max price by 1 index
			drop += 1;
			max_p = p[n-1-drop];
		} else if (sum < T) { //if the sum < T, increase the min price by 1 index
			up += 1; 
		} else if ((sum == T) && (max_p != min_p)) { //checking for the case where the same integer added to itself is the sum
			cout << "YES" << endl;
			cFlag = false;
			break;
		}
	}
	if (cFlag == true) {
		cout << "NO" << endl;
	}
}
//main function initializes n, T, and prices array, and calls sales
int main() {
	int n, T;
	unsigned long long prices[250000]; 
	cin >> n >> T;

	for (int i = 0; i < n; i++){
		cin >> prices[i];
	}

	sales(n, T, prices);

	return 0;
}