#include <iostream>

using namespace std;

class Monster
{
public:
	int x;
	int y;
	int Hp;
};

int main()
{
	void* Pointer = malloc(sizeof(Monster));

	Monster* m1 = (Monster*)Pointer;
	m1->x = 3;
	m1->y = 1;
	m1->Hp = 100;

	free(Pointer);

	Pointer = nullptr;
	m1 = nullptr;

	Monster* m2 = new Monster;

	m2->x = 1;
	m2->y = 3;
	m2->Hp = 50;

	delete m2;

	Monster* m3 = new Monster[5];
	delete[] m3;
}