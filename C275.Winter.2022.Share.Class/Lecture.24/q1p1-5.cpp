unsigned int countPositiveEven(list<int> *mylist) {
	unsigned ans = 0;
	for( int x: *mylist ) {
		if( x > 0 && (x%2) == 0 ) {
			ans++;
		}
	}
	return ans;
}
