// Dynamic Programing worksheet
// Question 3
// Omid Ardakanian, 2022

#include <iostream>

using namespace std;

int diceBottomUp(int n, int m, int s) {
	if (n<=0 || s<=0 || s>n*m) return 0;

	int** table = new int*[n+1];
	for(int i=0; i<=n; i++)
    	table[i] = new int[s+1](); // initialize to zero

    // table[i][j] stores the total number of ways we can get j using i dice with m faces
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=s; j++) {
			if (i==1 && j<=m) table[i][j] = 1;
			else {
				for (int k = 1; k <= min(m, j); k++) 
					table[i][j] += table[i-1][j-k]; // aggregation step
			}
		}
	}
	int ans = table[n][s];

	for(int i=0; i<=n; i++)
    	delete[] table[i];
	delete[] table;

	return ans;
}

int main() {
	int n, m, s;
	cin >> n >> m >> s;

	// Assumption: m >= 1, n >= 0
	cout << diceBottomUp(n, m, s) << endl;
	return 0;
}
