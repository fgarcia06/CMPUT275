/*----------------------------------------------------------------------------------------------------
  Name: Michael Tran
  SID: 1662870
  CCID: mtran7
  CMPUT 275, Winter 2022

 Assignment Part II: Client/Server Application
----------------------------------------------------------------------------------------------------*/
#include <iostream>
#include <cassert>
#include <fstream>
#include <string>
#include <list>
#include <cstring>

#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#include "wdigraph.h"
#include "dijkstra.h"

#define MAX_SIZE 1024

struct Point {
    long long lat, lon;
};

// returns the manhattan distance between two points
long long manhattan(const Point& pt1, const Point& pt2) {
  long long dLat = pt1.lat - pt2.lat, dLon = pt1.lon - pt2.lon;
  return abs(dLat) + abs(dLon);
}

// finds the id of the point that is closest to the given point "pt"
int findClosest(const Point& pt, const unordered_map<int, Point>& points) {
  pair<int, Point> best = *points.begin();

  for (const auto& check : points) {
    if (manhattan(pt, check.second) < manhattan(pt, best.second)) {
      best = check;
    }
  }
  return best.first;
}

// read the graph from the file that has the same format as the "Edmonton graph" file
void readGraph(const string& filename, WDigraph& g, unordered_map<int, Point>& points) {
  ifstream fin(filename);
  string line;

  while (getline(fin, line)) {
    // split the string around the commas, there will be 4 substrings either way
    string p[4];
    int at = 0;
    for (auto c : line) {
      if (c == ',') {
        // start new string
        ++at;
      }
      else {
        // append character to the string we are building
        p[at] += c;
      }
    }

    if (at != 3) {
      // empty line
      break;
    }

    if (p[0] == "V") {
      // new Point
      int id = stoi(p[1]);
      assert(id == stoll(p[1])); // sanity check: asserts if some id is not 32-bit
      points[id].lat = static_cast<long long>(stod(p[2])*100000);
      points[id].lon = static_cast<long long>(stod(p[3])*100000);
      g.addVertex(id);
    }
    else {
      // new directed edge
      int u = stoi(p[1]), v = stoi(p[2]);
      g.addEdge(u, v, manhattan(points[u], points[v]));
    }
  }
}

int create_and_open_fifo(const char * pname, int mode) {
  // creating a fifo special file in the current working directory
  // with read-write permissions for communication with the plotter
  // both proecsses must open the fifo before they can perform
  // read and write operations on it
  if (mkfifo(pname, 0666) == -1) {
    cout << "Unable to make a fifo. Ensure that this pipe does not exist already!" << endl;
    exit(-1);
  }

  // opening the fifo for read-only or write-only access
  // a file descriptor that refers to the open file description is
  // returned
  int fd = open(pname, mode);

  if (fd == -1) {
    cout << "Error: failed on opening named pipe." << endl;
    exit(-1);
  }

  return fd;
}

/*----------------------------------------------------------------------------------------------------
    Description: 
      The main function will take in the coordinates from the inpipe, parse the input and find the closest points and conduct the dijkstra algorithm on them.
      Afterwards, the determined values are written to the outpipe.

    Arguments:
      There are no arguments for the main function.

    Returns: 
      Does not return anything.
----------------------------------------------------------------------------------------------------*/
int main() {
  WDigraph graph;
  unordered_map<int, Point> points;

  const char *inpipe = "inpipe";
  const char *outpipe = "outpipe";

  // Open the two pipes
  int in = create_and_open_fifo(inpipe, O_RDONLY);
  cout << "inpipe opened..." << endl;
  int out = create_and_open_fifo(outpipe, O_WRONLY);
  cout << "outpipe opened..." << endl;  

  // build the graph
  readGraph("server/edmonton-roads-2.0.1.txt", graph, points);

  // read a request
  char buffer[MAX_SIZE]; //create a buffer to read into

  Point sPoint, ePoint; //define end start and end points
  
  while (true){
    int bytesRead = read(in, buffer, MAX_SIZE); //number of bytes read from the input coordinates
    buffer[bytesRead] = '\0'; //adding null-terminating character to end of character array

    string parse; //initialize parse string 
    for (int i = 0; i < bytesRead; i++){
      parse += buffer[i]; //concatentate the char array to the string
    }

    string parse1, parse2; //initialize the two parses of the string (which are separated by a new line; \n)
    char delimiter = '\n'; 
    parse1 = parse.substr(0, parse.find(delimiter)); //get first two coordinates
    parse2 = parse.substr(parse.find(delimiter)+1, bytesRead); //get latter two coordinates

    parse = parse1 + " " + parse2; //concatenate them into one string

    string coord[4]; //separate our coordinates
    int at = 0;
    for (auto c : parse) {
      if (c == ' ') {
        // start new string
        ++at;
      }
      else {
        // append character to the string we are building
        coord[at] += c;
      }
    }

    if (at != 3) {
      // empty line
      break;
    }
    
    sPoint.lat = static_cast<long long>(stod(coord[0])*100000); //convert to a form which findClosest is able to utilize them
    sPoint.lon = static_cast<long long>(stod(coord[1])*100000);

    ePoint.lat = static_cast<long long>(stod(coord[2])*100000);
    ePoint.lon = static_cast<long long>(stod(coord[3])*100000);


    // get the points closest to the two points we read
    int start = findClosest(sPoint, points), end = findClosest(ePoint, points);

    // run dijkstra's algorithm, this is the unoptimized version that
    // does not stop when the end is reached but it is still fast enough
    unordered_map<int, PIL> tree;
    dijkstra(graph, start, tree);

    // NOTE: in Part II you will use a different communication protocol than Part I
    // So edit the code below to implement this protocol

    // no path
    if (tree.find(end) == tree.end()) {
        write(out,"E\n", strlen("E\n"));
    } else {

      // read off the path by stepping back through the search tree
      list<int> path;
      while (end != start) {
        path.push_front(end);
        end = tree[end].first;
      }
      path.push_front(start);


      for (int v : path) {
        long double latOut = points[v].lat/100000.0, lonOut = points[v].lon/100000.0; 
        string sLat = to_string(latOut), sLon = to_string(lonOut); //convert the long double to string

        sLat.pop_back(); //get rid of trailing zeros
        sLon.pop_back();

        string combine = sLat + " " + sLon + "\n";
        write(out, combine.c_str(), strlen(combine.c_str())); //write to outpipe

      }
      write(out,"E\n", strlen("E\n")); //write to outpipe
    }
  }
  
  close(in);
  close(out);

  unlink(inpipe);
  unlink(outpipe);

  return 0;
}
