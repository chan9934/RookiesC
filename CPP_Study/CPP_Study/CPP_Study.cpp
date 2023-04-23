#include <iostream>

using namespace std;

class Player
{
public:
	Player() {}

	virtual void vAttack() = 0;
};

class Knight : public Player
{
public:
	virtual void vAttack() { cout << "ㅎㅇ" << endl; }
};

int main()
{
	Knight a;
	a.vAttack();
}