/*----------------------------------------------------------------------------------------------------
  Name: Michael Tran
  SID: 1662870
  CCID: mtran7
  CMPUT 275, Winter 2022

 Assignment: Trivial Navigation System Part I
----------------------------------------------------------------------------------------------------*/

#include "dijkstra.h"
#include "wdigraph.h"
#include <list>
#include <string>
#include <climits>
#include <fstream>
using namespace std;

/*----------------------------------------------------------------------------------------------------
    Description: 
        struct where objects (the ID) contain members of latitude and longitude for each object.
----------------------------------------------------------------------------------------------------*/
struct Point {
    long long lat; // latitude of the point
    long long lon; // longitude of the point
};

/*----------------------------------------------------------------------------------------------------
    Description: 
        calculates the distance between two Point objects by doing the manhattan distance.

    Arguments:
        pt1 (const Point&): object of struct Point
        pt2 (const Point&): object of struct Point

     Returns: 
        distance between the two vertices
----------------------------------------------------------------------------------------------------*/
long long manhattan(const Point& pt1, const Point& pt2){
    long long distance = abs((pt1.lat) - (pt2.lat)) + abs((pt1.lon) - (pt2.lon));
    return distance; 
}

/*----------------------------------------------------------------------------------------------------
    Description: 
        changes the data type of a double to a long long

    Arguments:
        number (double&): number to be converted

     Returns: 
        returns the changed number
----------------------------------------------------------------------------------------------------*/
long long d_to_ll(double& number){
    static_cast<long long>(number*100000);
    return number;
}

/*----------------------------------------------------------------------------------------------------
    Description: 
        creates a weighted graph from the text file given

    Arguments:
        filename (string): name of text file
        graph (WDigraph&): the graph object
        points (unordered_map<int, Point>&): unordered_map with vertex ID's as keys and struct objects as values

     Returns: 
        returns nothing.
----------------------------------------------------------------------------------------------------*/
void readGraph (string filename, WDigraph& graph, unordered_map<int, Point>& points){

    string cmd, name, line, value, line_ar[4], lat, lon;
    int ID, start, end;

    ifstream file(filename);
    while(getline(file, line)){
        cmd = line.substr(0, 1); //checking query of whether it is 'V' or 'E'

        if (cmd == "V"){

            int comma1 = line.find(','); //find the commas in the string
            int comma2 = line.find(',', comma1+1);
            int comma3 = line.find(',', comma2+1);

            lat = line.substr(comma2+1, (comma3-comma2-1)); //segment off the latitude and longitude in the string
            lon = line.substr(comma3+1);

            double d_lat = stod(lat); //convert the latitude and longitude from string type to double type
            double d_lon = stod(lon);

            long long ll_lat = static_cast<long long>(d_lat*100000); //convert the latitude and longitude from double type to long long type
            long long ll_lon = static_cast<long long>(d_lon*100000);

            ID = stoi(line.substr(comma1+1, (comma2-comma1+1))); //get the vertex ID as an integer

            graph.addVertex(ID);
            
           	Point instance; //make an object instance of the struct, and set the members to the latitude and longitude
           	instance.lat = ll_lat;
            instance.lon = ll_lon;

            points[ID] = instance; //set the key in the unordered_map as the ID, with value of the struct object

        } else if (cmd == "E"){

            int comma1 = line.find(','); //find the commas in the string
            int comma2 = line.find(',', comma1+1);
            int comma3 = line.find(',', comma2+1);

            start = stoi(line.substr(comma1+1, (comma2-comma1-1))); //find the two vertix IDs
            end = stoi(line.substr(comma2-comma1+2, comma3-comma2-1));

            graph.addEdge(start, end, manhattan(points[start], points[end])); //calculate distance between the two IDs
        }

    }

}

/*----------------------------------------------------------------------------------------------------
    Description: 
        finds the closest vertext to the point the user inputted

    Arguments:
        pt1 (Point): object of Point struct, has data members of latitude and longitude that the user inputted
        points (unordered_map<int, Point>&): unordered_map with vertex ID's as keys and struct objects as values

     Returns: 
        returns the vertex ID of the closest vertex.
----------------------------------------------------------------------------------------------------*/

int findclose(Point pt1, unordered_map<int, Point>& points){
    int close_id;
    long long closest_distance = LLONG_MAX; //initalizing to the largest possible distance long long can hold

    unordered_map<int, Point>::iterator it = points.begin(); //iterator

    while (it != points.end()){
        if (manhattan(it ->second, pt1) < closest_distance){ //check if the distance from the it point and the user point is smaller than the closest distance
            closest_distance = manhattan(it -> second, pt1); //new closest distance
            close_id = it -> first; //ID of that iterator vertex
        }
        it++;
    }
    return close_id;
}

int main() {
    WDigraph graph;
    string request, input;

    long long lat1, lon1, lat2, lon2;

    unordered_map<int, PIL> searchTree; //initialize searchTree and points
    unordered_map<int, Point> points;

    readGraph("edmonton-roads-2.0.1.txt", graph, points); //create weighted graph

    cin >> request >> lat1 >> lon1 >> lat2 >> lon2;

    Point temp1;
    temp1.lat = lat1;
    temp1.lon = lon1;

    Point temp2;
    temp2.lat = lat2;
    temp2.lon = lon2;

    int closest_vertex1 = findclose(temp1, points); //find the closests vertices to the start and end
    int closest_vertex2 = findclose(temp2, points);
    
    dijkstra(graph, closest_vertex1, searchTree);

    list<int> path;
    if (searchTree.find(closest_vertex2) == searchTree.end()) { //if there are no nodes
      cout << "N 0" << endl;
      cout << "E" << endl;

    } else {
      int stepping = closest_vertex2;
      while (stepping != closest_vertex1) {
        path.push_front(stepping);

        // crawl up the search tree one step
        stepping = searchTree[stepping].first;

      }
      path.push_front(closest_vertex1);
      cout << "N " << path.size() << endl;

      for (auto it : path) {
        cin >> input;
        if (input == "A"){
            cout << "W " << points[it].lat << " " << points[it].lon << endl;
        }
      }
      cout << "E" << endl;
    } 


    return 0;
}
