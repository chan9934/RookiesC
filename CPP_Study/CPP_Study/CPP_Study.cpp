#include <iostream>

using namespace std;

struct StatInfo
{
	int Hp = 0xAAAAAAAA;
	int Attack = 0xBBBBBBBB;
	int Deffence = 0xCCCCCCCC;

};

int main()
{
	StatInfo Monster[10];

	StatInfo* Monster_0 = Monster;
	Monster_0->Hp = 100;
	Monster_0->Attack = 10;
	Monster_0->Deffence = 1;
	
	StatInfo* Monster_1 = Monster + 1;
	Monster_0->Hp = 200;
	Monster_0->Attack = 20;
	Monster_0->Deffence = 2;

	StatInfo& Monster_2 = *(Monster + 2);
	Monster_2.Hp = 300;
	Monster_2.Attack = 30;
	Monster_2.Deffence = 3;

	StatInfo Temp = *(Monster + 3);

	const char *B = "Hello World";

	cout << B << endl; // Hello World"
	cout << *B << endl; // H


	char A[] = "Hello World";

	cout << A << endl; // Hello World"
	cout << *A << endl; // H

}

void Test(char B[])
{
	B[0] = 'X';
}