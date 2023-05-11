#include <iostream>

#include <deque>

#include <map>

using namespace std;

int main()
{
	map<int, int>mp;

	srand(static_cast<unsigned int>(time(nullptr)));

	for (int i = 0; i < 100000; ++i)
	{
		mp.insert(make_pair(i, i + 100));
	}

	for (int i = 0; i < 50000; ++i)
	{
		int RandIndex = rand() % 100000;

		mp.erase(RandIndex);
	}

	map<int, int>::iterator mpf = mp.find(50000);
	if (mpf != mp.end())
	{
		cout << mpf->second << endl;
		cout << mp[50000] << endl;
	}
	else
	{
		cout << "없다" << endl;
	}

	mp.clear();
	for (map<int, int>::iterator it = mp.begin(); it != mp.end(); ++it)
	{
		cout << it->second << endl;
	}
}