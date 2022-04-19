/*
  A simple demonstration of how to use unordered sets.

  Course: CMPUT 275
  Omid Ardakanian, 2022
*/

#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int main() {
  // variable declaration and initialization syntax
  unordered_set<string> my_set = {
    {"Zac", "Paul", "Omid"}
  };

  unordered_set<int> id_set;

  // operator= is overloaded for unordered_sets
  id_set = {12345, -98765, 10000, 10001};

  // printing the contents of the map
  // using a C++11 range-based for loop
  // OBSERVE: the order they are printed does not
  // correspond to the order they were inserted
  for (auto item : my_set) {
    cout << item << endl;
  }
  cout << endl;

  // NOTE: the iterator type name is very long
  // you can use the auto keyword here
  unordered_set<string>::const_iterator got = my_set.find("Omid");

  if (got == my_set.end()) {
    cout << "key Omid not found" << endl;
  } else {
    cout << "key Omid found" << endl;
  }
  cout << endl;

  // size() returns the number of elements in the unordered_set
  cout << "Number of elements: " << my_set.size() << endl;

  // insert() adds new elements in the unordered_set
  cout << "Adding a new element" << endl;
  my_set.insert("Megan");

  // size() returns the number of elements in the unordered_set
  cout << "Number of elements: " << my_set.size() << endl;

  // elements must have unique values to be added successfully
  cout << "Adding a new element (not unique)" << endl;
  my_set.insert("Omid");

  // size() returns the number of elements in the unordered_set
  cout << "Number of elements: " << my_set.size() << endl;

  cout << "Now erasing Omid" << endl;
  my_set.erase("Omid");

  if (my_set.find("Omid") == my_set.end()) {
    cout << "key Omid not found" << endl;
  } else {
    cout << "key Omid found" << endl;
  }
  cout << endl;

  // deletes all elements of the unordered_set
  // the size of the container will be zero
  cout << "Deleting all elements" << endl;
  my_set.clear();
  cout << "Number of elements: " << my_set.size() << endl;

  return 0;
}
