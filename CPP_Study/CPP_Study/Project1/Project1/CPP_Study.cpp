#include <iostream>
#include<set>

using namespace std;

int main()
{
	set<int> S;

	S.insert(10);
	S.insert(20);
	S.insert(30);
	S.insert(40);
	S.insert(50);
	S.insert(60);
	S.insert(70);
	S.insert(80);
	S.insert(90);
	S.insert(100);

	S.erase(40);

	set<int>::iterator SF = S.find(50);
	if (SF != S.end())
	{
		cout << "찾음" << endl;
	}
	else
	{
		cout << "못 찾음" << endl;
	}

	for (set<int>::iterator it = S.begin(); it != S.end(); ++it)
	{
		cout << *it << endl;
	}
}