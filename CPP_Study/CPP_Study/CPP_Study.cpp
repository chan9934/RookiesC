#include <iostream>

using namespace std;



int main()
{
	// 1-10사이의 홀수 출력

	for (int count = 1; count <= 10; count++)
	{
		bool isEven = ((count % 2) == 0);

		if (isEven)
			continue;
		cout << count << endl;
	}
}