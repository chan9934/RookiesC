#include <iostream>

using namespace std;

class Position
{
public:
	int x = 3;

public:
	Position operator+(int a)
	{
		Position Temp;
		Temp.x = x + a;
		return Temp;
	}

	Position operator*(const Position& a)
	{
		Position Temp;
		Temp.x = x + a.x;
		return Temp;
	}

	bool operator==(const Position& a)
	{
		return x == a.x;
	}

	Position& operator=(int a)
	{
		x = a;

		return *this;
	}

	Position& operator=(const Position& a)
	{
		x = a.x;
		return *this;
	}

};

Position operator+(int a, const Position& b)
{
	Position Temp;
	Temp.x = b.x + a;
	return Temp;
}

int main()
{
	Position A;
	cout << (A + 1).x << endl;
	cout << (1 + A).x << endl;
	Position B;
	B.x = 3;

	cout << (A == B) << endl;
	A = 1;
	cout << A.x << endl;
	
	A = 3;
	cout << A.x << endl;


}