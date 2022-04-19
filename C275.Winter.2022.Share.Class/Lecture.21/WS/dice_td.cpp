// Dynamic Programing worksheet
// Question 1
// Omid Ardakanian, 2022

#include <iostream>
#include <unordered_map>
#include <utility>

using namespace std;

typedef pair<int,int> PII;

struct PairHash { 
	// a function object class, defines operator() const

	template <class K1, class K2>
	size_t operator()(const pair<K1, K2> &pair) const {
		// std::hash is unary function object class

		auto hash_first = hash<K1>()(pair.first);
		auto hash_second = hash<K2>()(pair.second);

		// is (hash_first ^ hash_second) a good hash function? 
		// too many collisions: hash of (a, a) is always zero 
		// and hash of (a, b) is the same as hash of (b, a)
		if (hash_first != hash_second)
			return hash_first ^ hash_second; // taking xor

		return hash_first;
	}
};

int dice(int n, int m, int s, unordered_map<PII,int,PairHash> &memo) {
	int ways = 0;

	// make the key pair
	PII mpair (n, s); 
	if (memo.find(mpair) == memo.end()) {  
		// this subproblem has not been solved yet
		if (n<=0 || s<=0 || s>n*m) 
			ways = 0; // base case
		else if (n==1 && s>0 && s<=m) 
			ways = 1; // base case
		else {
			for (int i=1; i<=m; i++)
				ways += dice(n-1, m, s-i, memo); // aggregation
		}
		// memoize the solution of this subproblem
		memo[mpair] = ways;
	}
	return memo[mpair];
}

int main() {
	int n, m, s;
	cin >> n >> m >> s;

	// there is no specialization of std::hash for std::pair
	// we need to write our own hash function
	unordered_map<PII, int, PairHash> table;

	cout << dice(n, m, s, table) << endl;
	return 0;
}
