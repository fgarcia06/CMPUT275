#include <iostream>

using namespace std;

int main(){

    int n, m, num[100000];
    cin >> n >> m;
    
    long long product = 1;
    
    long long* left = new long long[n];
    long long* right = new long long[n];
    
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }

    for (int i = 0; i < (n-1 - m); i++) {
        product *= num[n-1 - i];
        left[n - m - i - 2] = product;
    }
    
    for (int i = (n-1 - m); i < n; i++) {
        left[i] = 0;
    }
    
    for (int i = 0; i <= m; i++) {
        right[i] = 0;
    }

    product = 1;
    
    for (int i = (m + 1); i < n; i++) {
        product *= num[i - 1 - m];
        right[i] = product;
    }

 	for (int i = 0; i < n; i++) {
        
        if (i <= m){
            product = left[i];
        } else if (i >= (n-1 - m)) {
            product = right[i];
        } else {
            product = left[i] * right[i];
        }
        
        if ((m == i) && (i == (n-1)/2)) {
            
            if (n-1 != 0){
                cout << 0 << " ";
            } else {
                cout << 0 << endl;
            }
            
        } else if (n-1 == i) {
            cout << product << endl;
        } else {
            cout << product << " ";
        }
        
    }


    return 0;
}