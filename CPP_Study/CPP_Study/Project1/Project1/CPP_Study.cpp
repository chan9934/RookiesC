#include <iostream>
using namespace std;

class Knight
{
	Knight()
	{
		cout << "Knight 생성" << endl;
	}
	~Knight()
	{
		cout << "Knight 소멸" << endl;
	}

	void Attack()
	{
		if(_target)
		{
			_target->_hp -= _damage;
			cout << "Hp : " << _target->_hp << endl;
		}
	}

	public:
	int _hp = 100;
	int _damage = 10;
	Knight* _target = nullptr;
}
int main()
{
	Knight* k1 = new Knight();
	Knight* k2 = new Knight();

	k1->_target = k2;
}