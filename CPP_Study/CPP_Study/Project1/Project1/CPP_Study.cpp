#include <iostream>

using namespace std;

class Pet
{
public:
	Pet()
	{
	}
	Pet(const Pet& _pet)
	{

	}
};

class Player
{
public:
	Player()
	{
	}
	Player(const Player& _player)
	{
		Level = _player.Level;
	}
	~Player()
	{
	}

	int Level = 0;
};
class Knight : public Player
{
public:
	Knight()
	{
		m_Pet = new Pet;
		cout << "생성자" << endl;
	}

	Knight(const Knight& _knight) : Player(_knight), m_Pet(_knight.m_Pet)
	{
		m_Hp = _knight.m_Hp;
		m_Pet = new Pet(*(_knight.m_Pet));
		cout << "복사 생성자" << endl;
	}

	Knight& operator = (const Knight& _knight)
	{
		Player::operator=(_knight);
		m_Hp = _knight.m_Hp;
		m_Pet = new Pet(*(_knight.m_Pet));
		cout << "복사 대입 연산자" << endl;
		return *this;
	}
	~Knight()
	{
		delete m_Pet;
	}

	int m_Hp = 100;
	Pet* m_Pet;
};

int main()
{
	Pet* pet = new Pet;
	Knight knight1;
	knight1.m_Hp = 200;
	knight1.m_Pet = pet;
	knight1.Level = 200;


	Knight knight2 = knight1;

	Knight knight3;
	knight3 = knight1;

}