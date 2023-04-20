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

char* StrCpy(char* des, char* src)
{
	int count = 0;
	while (src[count] != '\0')
	{
		des[count] = src[count];
		++count;
	}
	des[count] = src[count];

	return des;

}

char* Cpy(char* des, char* src)
{
	

	StrCpy(des + StrLen(des), src);

	return des;
	
}

int StrCmp(char* a, char* b)
{
	char* first = nullptr;
	char* second = nullptr;
	if (StrLen(a) > StrLen(b))
	{
		first = a;
		second = b;
	}

	else
	{
		first = b;
		second = a;
	}
	
	for (int i = 0; i < StrLen(first); ++i)
	{
		bool Last = false;
		if ((i + 1) == StrLen(first))
		{
			Last = true;
		}
		if (a[i] > b[i])
		{
			return 1;
		}
		else if (a[i] == b[i])
		{
			if (Last)
			{
				return 0;
			}
			continue;
		}
		else
		{
			return -1;
		}
	}

}

char* ReverseString(char* a)
{
	char Temp[BUF_SIZE];

	StrCpy(Temp, a);
	int Count = StrLen(a);
	for (int i = 0; i < Count; ++i)
	{
		a[i] = Temp[Count - 1 - i];
	}
	a[Count] = '\0';

	
	return a;
}

int main()
{
	
	char a[BUF_SIZE] = "aa";

	char b[BUF_SIZE] = "a";

	char c[BUF_SIZE] = "HelloWorld";
	cout << ReverseString(c);
}