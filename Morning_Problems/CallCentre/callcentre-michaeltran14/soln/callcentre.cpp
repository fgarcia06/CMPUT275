#include <iostream>
using namespace std;


int main() {
    int n, q, start, end, callarray[86400], sumarray[86400], sum = 0, value = 0;
    cin >> n >> q;

    for (int i = 0; i < n; i++){
        cin >> value;
        callarray[i] = value;
        sum += value;
        sumarray[i] = sum;
    }

    for (int i = 0; i < q; i++){
        cin >> start >> end;
        if (start == 1){
            cout << (sumarray[end-1]) << endl;
        } else if (start == end) {
            cout << callarray[start-1] << endl;
        } else {
            cout << sumarray[end-1]-sumarray[start-2] << endl;
        }
    }
    return 0;
}