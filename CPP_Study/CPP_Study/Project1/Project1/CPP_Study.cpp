#include <iostream>

using namespace std;

class Player
{
public:
	virtual ~Player() {}
};

class Knight :public Player
{
public:
};

class Archer : public Player
{
public:
};

class Dog
{
public:
};
void PrintName(char* str)
{
	cout << str << endl;
}


int main()
{
	int Hp = 100;
	int MaxHp = 200;
	float Ratio = static_cast<float>(Hp) / MaxHp;

	Player* p1 = new Archer();
	Knight* k1 = static_cast<Knight*>(p1);

	Knight* k2 = dynamic_cast<Knight*>(p1);

	PrintName(const_cast<char*>("Rookiess"));

	__int64 Test = reinterpret_cast<__int64>(k1);

	Dog* d1 = reinterpret_cast<Dog*>(k1);

}