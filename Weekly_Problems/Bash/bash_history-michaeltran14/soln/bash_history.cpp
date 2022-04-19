/*----------------------------------------------------------------------------------------------------
  Name: Michael Tran
  SID: 1662870
  CCID: mtran7
  CMPUT 275, Winter 2022

  Weekly Exercise #6: Bash History
----------------------------------------------------------------------------------------------------*/

#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>
using namespace std;

/*----------------------------------------------------------------------------------------------------
	Description: 
		getpath() finds the path of the directories up till an index of length.

	Arguments:
		path (string*): the dynamically allocated array representing the path components.
		length (int): the distance for the array to find the path up till that point.
	
	Returns: 
	 	main_path (string): a string of the directory path.
----------------------------------------------------------------------------------------------------*/


string getpath(string* path, int length) {
	
	string main_path = ""; //resetting each main path starting with the root
	
	if (length != 1) { 
		for (int i = 1; i < length; i++)
			main_path += ("/" + path[i]);
	} else if (length == 1){ //if the length of the path is only 1, there is only the root present
		main_path = path[0]; //set the main path just to "/"
	}
	
	return main_path;
}

/*----------------------------------------------------------------------------------------------------
	Description: 
		In the map, prints out all files for the specific directory as well as the pathway, which is then printed via cout.

	Arguments:
		files (map<string, set <string>>&): a map of sets where each key is a specific path, and the value of that path contains the files
	
	Returns: 
	 	Does not return anything.
----------------------------------------------------------------------------------------------------*/

void file_print(map<string, set<string>>& files){
	for (auto& map: files) { 

		string path_files = ""; //empty path file string
		
		for (auto itr = map.second.begin(); itr != map.second.end(); itr++){
			if ((itr == --map.second.end())){ //if itr is at the last index in the set, add to path files string without a space
				path_files += *itr;
			} else {
				path_files += *itr + " "; //repeated appending to the path string
			}
		}

		cout << map.first << path_files << endl; //cout the path of directories, then the files of the last directory	
	}
}

int main() {
	int n, main_dir = 0;
	string cmd, file, next_dir, main_path = "/";
	cin >> n;


	map<string, set<string>> files; //map of sets for directory files
	files[main_path].insert(""); //initialize root path with empty set

	string* path = new string[100000]; 
	path[main_dir] = "/"; //root as starting directory

	main_path = getpath(path, main_dir); //find the path with this directory
	main_dir += 1; //increase index

    path[main_dir] = "";

 	for (int i = 0; i < n; i++){
 		cin >> cmd; //check for which query
 		if (cmd == "ls"){

 			main_path = getpath(path, main_dir); //get current path
 			cin >> file;

 			files[main_path].insert(file); //insert file at set of that path

 		} else if (cmd == "cd"){

 			cin >> next_dir; //find what next directory to index to

 			if (next_dir != ".."){

 				path[main_dir] = next_dir; //adding it to the path and increment
 				main_dir += 1;
 				main_path = getpath(path, main_dir); 

 				if (files.find(main_path) == files.end()){
 					files[main_path].insert(""); 
 				}

 			} else if (next_dir == ".."){

 				main_dir -= 1; //decrement to go back a directory
 				path[main_dir] = "";
 			}
 		}
 	}
 	
 	file_print(files); //print the unique directories
 	delete[] path;
	return 0;
}