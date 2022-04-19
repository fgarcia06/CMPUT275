#include <iostream>

using namespace std;

int main() {
  int n, floors[1000], count = 0;

  cin >> n;

  for (int i = 0; i < n; i++){
    cin >> floors[i];
  }

  floors[n] = 0;

  for (int i = 0; i < n; i++){
    if (floors[i] < floors[i+1]){
      count += (floors[i+1]-floors[i]);
    }
  }

  cout << count << endl;

  return 0;
}
