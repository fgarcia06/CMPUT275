#include <iostream>
#include <string>
#include <map>
using namespace std;



int main() {
	string c_pos = "west";
    int west_num, east_num, west, east, time = 0;

    cin >> west_num >> east_num;

    map<int, string> timelocations;

    for (int i = 0; i < west_num; ++i) {
        cin >> west;
        timelocations[west] = "west";
    }

    for (int i = 0; i < east_num; ++i) {
        cin >> east;
        timelocations[east] = "east";
    }

    while (!timelocations.empty()) {
        int longest = timelocations.begin()->first;
        string long_pos = timelocations.begin()->second;

        if (time < longest) {
            time = longest;
        }

        if (long_pos == c_pos) {
            time += 100;

            if (c_pos != "east") {
                c_pos = "east";
            } else {
                c_pos = "west";
            }

        } else {
            time += 200;
        }

        timelocations.erase(longest);
    }

    cout << time << endl;

    return 0;
}