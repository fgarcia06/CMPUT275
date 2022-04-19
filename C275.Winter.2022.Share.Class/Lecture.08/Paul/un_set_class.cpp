#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int main()
{
	unordered_set<string> my_set;
	unordered_set<int> id_set;

	id_set = { 12345, -98765, 10000, 10001 };
	for( auto item : id_set )
	{
		cout << item << endl;
	}

	return 0;
}
