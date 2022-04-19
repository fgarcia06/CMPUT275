#include <iostream>

using namespace std;

int main() {
  int S, A, pointer[1000], index = 0, stop = 0;
  cin >> S >> A;



  for (int i = 0; i < A; i++){  
    cin >> index;
    if (index >= 0) {
      index = index - S;
    } 
    pointer[i] = index;
  }
  index = 0;


  while (stop < A) {
    if (pointer[index] < 0){
      cout << pointer[index] << endl;
      break;
    } else if (pointer[index] >= 0) {
      index = pointer[index];
      stop += 1;
    }
  } 

  if (stop >= A){
    cout << "There was a cycle" << endl;
  }

  return 0;
}
