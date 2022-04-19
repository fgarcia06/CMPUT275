#include <iostream>
using namespace std;

int main(){
	int n, m;

	cin >> n >> m;
 	while (m%n == 0) m = m/n;

	if (m == 1 && n != 1) {
		cout << "GOOD" << endl;
	}
	else {
		cout << "BAD" << endl;
	}

	return 0;
}
