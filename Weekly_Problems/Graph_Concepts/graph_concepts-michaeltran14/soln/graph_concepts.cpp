/*----------------------------------------------------------------------------------------------------
  Name: Michael Tran
  SID: 1662870
  CCID: mtran7
  CMPUT 275, Winter 2022

  Weekly Exercise #6: Graph Concepts
----------------------------------------------------------------------------------------------------*/

#include <iostream>
#include "digraph.h"
using namespace std;

/*----------------------------------------------------------------------------------------------------
	Description: 
		Recursively calls the depth-first-search algorithm, marking off visited vertices until a vertex has been reached before.
			This portion of code was taken from Lecture 13 in-class discussion.

	Arguments:
		graph (const Digraph&): the graph to perform depth-first-search on.
		u (const int): integer representing the vertex being checked.
		prev (const int): the previous vertex to u.
		reached (unordered_map<int, int>): map where key's are the vertices just reached and values are the vertices reached prior to the one currently.

	 Returns: 
	 	Does not return anything.
----------------------------------------------------------------------------------------------------*/

void recursive_dfs(const Digraph& graph, const int u, const int prev, unordered_map<int, int> & reached) {
	if (reached.find(u) != reached.end())
		return; // it was visited before

	reached[u] = prev;

	// Iterate over all neighbours of u
	for (auto itr = graph.neighbours(u); itr != graph.endIterator(u); ++itr) {
		recursive_dfs(graph, *itr, u, reached);
	}
}

/*----------------------------------------------------------------------------------------------------
	Description: 
		The count_components(const Digraph& graph) function returns the amount of connected components in a given graph by recursively calling depth-first-search
			on each unvisited nodes.

	Arguments:
		graph (const Digraph&): the graph to perform perform count_components on.

	Returns: 
	 Returns the unsigned integer value of the count.
----------------------------------------------------------------------------------------------------*/

unsigned int count_components(const Digraph& graph){
	int count = 0;
	unordered_map<int, int> reached;
	vector<int> vertices = graph.vertices();
	for (int i : vertices){
		if (reached.find(i) == reached.end()){
			count++;
			recursive_dfs(graph, i, i, reached);
		}
	}
	return count;
}

/*----------------------------------------------------------------------------------------------------
	Description: 
		read_city_graph_undirect() creates a graph using the values given in each line from the file.

	Arguments:
		Takes no arguments.

	Returns: 
	 	Returns a graph of type class Digraph with the specifications given by the lines read in the file.
----------------------------------------------------------------------------------------------------*/
Digraph read_city_graph_undirect(){
	Digraph graph;
	string cmd, name, line, value;
	float Lat, Lon;
	int ID, start, end;

	while (!cin.eof()){ //while cin continues
		getline(cin, line); //get each line ran through cin

		cmd = line.substr(0, 1); //check whether query is V or E

		if (cmd == "V"){
			int comma1 = line.find(','); 
			int comma2 = line.find(',', comma1+1);
			value = line.substr(comma1+1, (comma2-comma1-1)); //find ID value as a string

			ID = stoi(value); //string to integer

			graph.addVertex(ID);
		} else if (cmd == "E"){

			int comma1 = line.find(',');
			int comma2 = line.find(',', comma1+1);
			int comma3 = line.find(',', comma2+1);

			string s_start = line.substr(comma1+1, (comma2-comma1-1)); //find start as a string
			string s_end = line.substr(comma2-comma1+2, comma3-comma2-1); //find end as a string

			start = stoi(s_start); //convert to integer
			end = stoi(s_end);

			graph.addEdge(start, end);
			graph.addEdge(end, start);
		}
	}
	return graph;
}

int main(){
	cout << count_components(read_city_graph_undirect()) << endl;

	return 0;
}
