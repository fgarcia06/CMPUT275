/*----------------------------------------------------------------------------------------------------
  Name: Michael Tran
  SID: 1662870
  CCID: mtran7
  CMPUT 275, Winter 2022

 Weekly Exercise #7: Makefile Dependencies
----------------------------------------------------------------------------------------------------*/
#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <sstream>
using namespace std;

/*----------------------------------------------------------------------------------------------------
	Description: 
		Given a specific target, recursively build that target by building the order of dependencies in which they are found, building main_target when finished.

	Arguments:
		c_target (string): the current target to build
		main_target (string): the initial target called by make during user input
		targets (unordered_map<string, string>&): unordered map passed by reference, where keys are targets and the values are the respective dependecies
		constructed (unordered_map<string, string>&): unordered map passed by reference, where keys are the targets that are built.

	 Returns: 
	 	Does not return anything.
----------------------------------------------------------------------------------------------------*/
void build(string c_target, string main_target, unordered_map<string, string>& targets, unordered_map<string, string>& constructed){
	string depend = targets[c_target], c_depend;
	stringstream cin(depend); //take in string stream as dependency list from the current target

	while (getline(cin, c_depend, ' ')){
		if (targets.find(c_depend) != targets.end() && constructed.find(c_depend) == constructed.end()){ //check to see if dependencies are built
			build(c_depend, main_target, targets, constructed); //recursively build
		}
	}

	constructed[c_target]; //setting the key to current target to indicates that it has been constructed

	if (c_target != main_target){ //if the current target is not the main target
		cout << c_target << " ";
	} else {
		cout << c_target << endl;
	}
}

/*----------------------------------------------------------------------------------------------------
	Description: 
		Given a specific target, check to see if the target has already been built, if not, build it. If it has been built, output to out stream that is has already been built.

	Arguments:
		targets (unordered_map<string, string>&): unordered map passed by reference, where keys are targets and the values are the respective dependecies
		constructed (unordered_map<string, string>&): unordered map passed by reference, where keys are the targets that are built.

	 Returns: 
	 	Does not return anything.
----------------------------------------------------------------------------------------------------*/
void check_built(unordered_map<string, string>& constructed, unordered_map<string, string>& targets){ 
	string make, targetname; //make is filler string, just to take the 'make' query, targetname is build target

	cin >> make >> targetname;

	if (constructed.find(targetname) == constructed.end()){ //if target is not built yet, build the target
		build(targetname, targetname, targets, constructed);
	} else {
		cout << "make: `" + targetname + "' is up to date." << endl;
	}
}


int main() {
	int n, m, k;
	string targetname, dependents;
	unordered_map<string, string> targets;

	cin >> n >> m;

	for (int i = 0; i < n; i++){
		cin >> k >> targetname;
		targetname.erase(remove(targetname.begin(), targetname.end(), ':'), targetname.end()); //remove the colon at the end of target

		string depend = ""; //set empty dependency string for the target
		for (int j = 0; j < k; j++){
			cin >> dependents;

			depend += dependents + " "; //concatenate the dependency string as more dependents are added
		}

		targets[targetname] = depend; //set the key target to value of depend
	}

	unordered_map<string, string> constructed; //set an unordered map to track already constructed targets
	for (int i = 0; i < m; i++) {
		check_built(constructed, targets); //check to see if inputted target has already been built 
	}
	return 0;
}