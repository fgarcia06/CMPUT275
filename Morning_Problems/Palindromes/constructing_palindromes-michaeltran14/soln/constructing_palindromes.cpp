#include <iostream>
using namespace std;


int main(){
	int n, count = 0, length = 0;
	string letters;
	cin >> n >> letters; 

	string alphabet = "abcdefghijklmnopqrstuvwxyz";

	for(char c : alphabet) {
		for (char i : letters){
			if (c == i){
				count += 1;
			}
		}
		while (count >= 2) {
			count = count-2;
			length += 2;
		}
		count = 0;
	}

 	if (length == n){
 		cout << length << endl;
 	} else {
 		cout << length + 1 << endl;
 	}


	return 0;
}

