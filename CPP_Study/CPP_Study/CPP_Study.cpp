#include <iostream>
#include<iomanip>

using namespace std;

#define MAX 100

int board[MAX][MAX];
int n;

void PrintBoard()
{
	for (int y = 0; y < n; ++y)
	{
		for (int x = 0; x < n; ++x)
		{
			cout << setfill('0') << setw(2) << board[y][x] << " ";
		}
		cout << endl;
	}
}

bool CanGo(int y, int x)
{
	if (x < 0 || x >= n || y < 0 || y >= n)
	{
		return false;
	}

	else if (board[y][x] != 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}

void SetBoard()
{

	cin >> n;


	enum DIR
	{
		Right,
		Down,
		Left,
		Up
	};

	int y = 0;
	int x = 0;

	int num = 1;

	int dy[4] = { 0, 1, 0, -1 };
	int dx[4] = { 1, 0, -1, 0 };

	int Dir = Right;

	while (true)
	{
		if (CanGo(y, x))
		{
			board[y][x] = num;
			if (num == n * n)
			{
				return;
			}
			++num;
		}
		else
		{
			y = y - dy[Dir];
			x = x - dx[Dir];
			Dir = (Dir + 1) % 4;
		}

		y = y + dy[Dir];
		x = x + dx[Dir];
	}



}


int main()
{
	SetBoard();
	PrintBoard();
}