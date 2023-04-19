#include<iostream>

using namespace std;

#define BUF_SIZE 100

int StrLen(char msg[])
{
	int Count = 0;
	while(true)
	{
		if (msg[Count] == '\0')
		{
			break;
		}
		++Count;
	}
	return Count;

}

int main()
{
	
	char a[BUF_SIZE] = "Hello";

	cout << sizeof(a) << endl;

	cout << StrLen(a);
}