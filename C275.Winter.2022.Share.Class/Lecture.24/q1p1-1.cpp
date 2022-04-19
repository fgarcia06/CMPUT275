unsigned int cnt = 0;
for( int i =0; str[i] != '\0'; i++ ) {
	if( 'a' <= str[i] && str[i] <= 'z' ) {
		++cnt;
	}	
}
