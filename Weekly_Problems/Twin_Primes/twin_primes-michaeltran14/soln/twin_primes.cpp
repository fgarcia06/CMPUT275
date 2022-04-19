#include <iostream>
using namespace std;


bool isPrime(int n){
	if (n < 2){ //to avoid for loop error
		return false;
	}
	for (int i = 2; i < n; i++){ //checking all values up to, but not including, n
		if (n%i == 0){ //if there is no remainder, n is not prime
			return false;
		}
	}
	return true;
}

void twinPrimes(int k){
	int counter = 0, i = 0;
	while(counter != k){ //loop stops when the counter hits the wanted value
		i++;
		if(isPrime(i) && isPrime(i+2)){ //check if both p, p+2 are both prime
			cout << i << " " << i+2 << endl;
			counter += 1;
		}
	}	
}

int main(){
	int number;
	string choice;
	cin >> choice >> number;

	if (choice == "p") {
		if (isPrime(number)) cout << "prime" << endl;
		else cout << "not prime" << endl;
	} else if (choice == "t") {
		twinPrimes(number);
	}

	return 0;
}
