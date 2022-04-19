#include <iostream>
#include <unordered_set>
#include "digraph.h"
using namespace std;

void reachability(const Digraph& graph, const int start, unordered_set<int> & reached) {
	reached.insert(start);
	unordered_set<int> unexplored = {start};

	while (unexplored.size() > 0) {
		// Pick some unexplored vertex u
		// NOTE: it may be any vertex as the set does not keep track of
		// the order in which vertices are added to it
		int u = *unexplored.begin();

		unexplored.erase(unexplored.begin());

		// Iterate over all neighbours of u
		for (auto itr = graph.neighbours(u); itr != graph.endIterator(u); itr++) {

			// Check if it has been reached previously
			if (reached.find(*itr) == reached.end()) {

				// If it's reached for the first time add it to both sets
				reached.insert(*itr);
				unexplored.insert(*itr);
			}
		}
	}
}

int main() {
	Digraph graph;

	int nv, ne;
	cin >> nv >> ne;

	// Read vertex IDs
	for (int i = 0; i < nv; ++i) {
		int label;
		cin >> label;
		graph.addVertex(label);
	}

	// Read directed edges
	for (int i = 0; i < ne; ++i) {
		int u, v;
		cin >> u >> v;
		graph.addEdge(u, v);
	}

	// Read the start vertex
	int start;
	cin >> start;

	// Solve the graph reachability problem
	unordered_set<int> reachable_set = {};
	reachability(graph, start, reachable_set);

	// Print the subset of all vertices reachable from 'vertex'
	cout << "Set of vertices reachable from " << start << ":" << endl;
	for (unordered_set<int>::iterator it = reachable_set.begin(); it != reachable_set.end(); ++it) {
		cout << (*it) << endl;
	}
	cout << endl;

	return 0;
}
