/*----------------------------------------------------------------------------------------------------
  Name: Michael Tran
  SID: 1662870
  CCID: mtran7
  CMPUT 275, Winter 2022

 Assignment: Trivial Navigation System Part I
----------------------------------------------------------------------------------------------------*/

#include <iostream>
#include <unordered_map>
#include <list>
#include <utility> 
#include <queue>
#include "wdigraph.h"
#include "dijkstra.h"

using namespace std;

// typedef creates an alias for the specified type
// PIL is the value type of our searchTree 
typedef pair<int, long long> PIL;

// PIPIL is used to insert a key-value pair in our searchTree
// if we declare a variable 'x' as follows:  PIPIL x;
// x.first gives the start vertex of the edge, 
// x.second.first gives the end vertex of the edge, 
// x.second.second gives the cost of the edge
typedef pair<int, PIL> PIPIL;

/*----------------------------------------------------------------------------------------------------
    Description: 
        compare (bool): overloads the () operator to allow for comparison of the two 'd' values of two PIPIL objects

     Returns: 
        returns a boolean of whether comparison was greater than or not.
----------------------------------------------------------------------------------------------------*/

struct compare { //we are comparing the two d, rather than v of the left and right
public:
    bool operator() (const PIPIL& left, const PIPIL& right) const {
        return (left.second.second > right.second.second);
    }
};

void dijkstra(const WDigraph& graph, int startVertex, 
    unordered_map<int, PIL>& searchTree) {

    // each active fire is stored as (v, (u, d)) 
    // which implies that it is a fire started at u
    // currently burning the (u,v) edge 
    // and will reach v at time d

    priority_queue<PIPIL, vector<PIPIL>, compare> fires;


    // at time 0, the startVertex burns, we set the predecesor of
    // startVertex to startVertex (as it is the first vertex)
    fires.push(PIPIL(startVertex, PIL(startVertex, 0)));

    // while there is an active fire
    while (!fires.empty()) {
        // finding the fire that reaches its endpoint earliest
        auto earliestFire = fires.top();

        int v = earliestFire.first; 
        int u = earliestFire.second.first; 
        long long d = earliestFire.second.second;

        // remove this fire
        fires.pop();

        // if v is already "burned", there nothing to do
        if (searchTree.find(v) != searchTree.end()) {
            continue;
        }

        // record that 'v' is burned at time 'd' by a fire started from 'u'
        searchTree[v] = PIL(u, d);

        // now start fires from all edges exiting vertex 'v'
        for (auto iter = graph.neighbours(v); iter != graph.endIterator(v); iter++) {
            int nbr = *iter;

            // 'v' catches on fire at time 'd' and the fire will reach 'nbr'
            // at time d + (length of v->nbr edge)
            long long t_burn = d + graph.getCost(v, nbr);
            fires.push(PIPIL(nbr, PIL(v, t_burn)));
        }
    }
}
