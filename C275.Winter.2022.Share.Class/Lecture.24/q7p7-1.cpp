string operator*(const string& str, unsigned int n) {
	string rep =n "";
	for(unsigned int i = 0; i < n; i++ ) {
		rep = rep + str;
	}
	return rep;
}
