#include <iostream>
using namespace std;

int main() {
    int n, a[1000], count = 0, r[1000];
	cin >> n;

	for (int i = 0; i < n; i++){
		cin >> a[i];
	}

	for (int i = n-1; i >= 1; i--){
		if (a[i-1] < a[i]){
			count++;
			r[i-1] = count;
		} else {
			count = 0;
			r[i-1] = count;
		}
	}

	r[n-1] = 0;

	for (int i = 0; i < n; i++){
		if (i != n - 1){
			cout << r[i] << " ";
		} else {
			cout << r[i] << endl;
		}
	}
	return 0;
}