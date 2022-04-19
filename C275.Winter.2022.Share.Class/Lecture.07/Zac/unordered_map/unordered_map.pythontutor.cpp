// Paul Lu.  Interesting, but incomplete info within PythonTutor
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
  unordered_map<string, int> my_dict = {
    {"Zac", 7}, {"Omid", -11}, {"Ray", 9},
    {"Ragur", 5}, {"Rebecca", 9}, {"Saidur", 0}
  };

  if (my_dict.find("Omid") == my_dict.end()) {
    cout << "key Omid not found" << endl;
  }
  else {
    cout << "key Omid found" << endl;
  }

  return 0;
}
