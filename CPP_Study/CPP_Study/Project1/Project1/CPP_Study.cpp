#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> V;

	
	
	V.resize(1000);
	for (int i = 0; i < 1000; ++i)
	{
		V.push_back(100);
		cout << V.size() << " " << V.capacity() << endl;
	}
}