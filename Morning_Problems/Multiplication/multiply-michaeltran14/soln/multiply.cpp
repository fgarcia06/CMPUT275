
#include <iostream>
using namespace std;

int main() {
    int n = 0, m = 0, first[100], second[100], product[200] = {0};
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> first[i];
    }

    for (int j = 0; j < m; j++) {
        cin >> second[j];
    }

    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            product[i + j + 1] = product[i + j + 1] + first[i] * second[j];
        }
    }

    for (int k = n + m; k > 0; k--) {
        while (product[k] > 9) {
            product[k] = product[k] - 10;
            product[k - 1] = product[k - 1] + 1;
        }
    }


    for (int i = 0; i < n + m; i++) {
      if (i == n+m-1){
        cout << product[i] << endl;
      } else {
        cout << product[i] << " ";
      }
    }
    return 0;
}