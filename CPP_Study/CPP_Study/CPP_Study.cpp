#include <iostream>

using namespace std;

void Swap(int& A, int& B)
{
	int Temp = A;
	A = B;
	B = Temp;
}

void Sort(int Number[], int Count)
{
	for (int i = 0; i < Count; ++i)
	{
		for (int j = i + 1; j < Count; ++j)
		{
			if (Number[i] > Number[j])
			{
				Swap(Number[i], Number[j]);
			}

		}
	}

}

void ChooseLotto(int Number[])
{
	srand((unsigned)(time(0)));
	
	for (int i = 0; i < 6; )
	{
		int Temp = rand() % 45 + 1;

		if (i >= 1)
		{
			for (int j = 0; j < i; ++j)
			{
				if (Number[j] == Temp)
				{
					break;
				}
				
				if(i - 1 == j)
				{
					Number[i] = Temp;
					++i;
					break;
				}
			}
		}
		else
		{
			Number[i] = Temp;
			++i;
		}
	}
	Sort(Number, 6);
}

int main()
{
	int a = 1;
	int b = 2;
	cout << a << b << endl;

	Swap(a, b);
	cout << a << b << endl;

	int Number[6] = { 1, 42, 3, 15, 5, 6 };

	for (int i = 0; i < sizeof(Number) / sizeof(int); ++i)
	{
		cout << Number[i] << " ";
	}
	cout << endl;

	Sort(Number, sizeof(Number) / sizeof(int));
	for (int i = 0; i < sizeof(Number) / sizeof(int); ++i)
	{
		cout << Number[i] << " ";
	}
	cout << endl;
	int Number2[6] = {};
	for (int i = 0; i < sizeof(Number) / sizeof(int); ++i)
	{
		cout << Number2[i] << " ";
	}
	cout << endl;
	ChooseLotto(Number2);
	for (int i = 0; i < sizeof(Number) / sizeof(int); ++i)
	{
		cout << Number2[i] << " ";
	}


}