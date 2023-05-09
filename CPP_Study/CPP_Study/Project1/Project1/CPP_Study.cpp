#include <iostream>

#include <deque>

using namespace std;

int main()
{
	deque<int>dq (3, 1);
	dq.push_back(1);
	dq.push_back(2);
	dq.push_front(1);
	dq.push_front(2);
	

}