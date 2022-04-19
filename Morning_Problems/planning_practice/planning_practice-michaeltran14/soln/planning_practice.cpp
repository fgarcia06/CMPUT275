#include <iostream>
#include <vector>
#include <numeric>
using namespace std;


int main(){
	int n, t, s[50], e[50], start, end, s_erase, e_erase, days;
    cin >> n >> t;
    
    vector<int> time(24);
    iota(time.begin(), time.end(), 1);

    for (int i = 0; i < n; i++) {
    	cin >> s[i] >> e[i];
    }

    for (int i = 0; i < n; i++) {
    	start = s[i];
    	end = e[i];

    	s_erase = 0;
    	e_erase = 0;
    	for (int x : time){
    		if (x <= start){
    			s_erase += 1;
    		} else if (x > end){
    			e_erase += 1;
    		}
    	}
    	time.erase(time.begin(), time.begin()+s_erase);
    	time.erase(time.end()-e_erase, time.end());
    }

    if (time.empty()){
    	cout << "IMPOSSIBLE" << endl;
    } else {
    	while (t > 0) {
    		t = t - time.size();
  			days += 1;
    	}
    	cout << days << endl;
    }

	return 0;
}