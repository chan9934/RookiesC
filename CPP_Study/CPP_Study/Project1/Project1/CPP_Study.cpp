#include <iostream>

using namespace std;

class Pet
{

};

class Knight
{
public:
	Knight()
	{
	}
	~Knight()
	{
		if (m_Pet)
		{
			delete m_Pet;	
		}
	}
	Knight(const Knight& _Knight)
	{
	}

	void Printf()
	{

	}

	void operator=(const Knight& _Knight)
	{
		m_Pet = _Knight.m_Pet;
		m_Hp = _Knight.m_Hp;
	}

public:
	Pet* m_Pet = nullptr;
	int m_Hp = 100;
};

// lvalue : 단일식을 넘어서 계속 지속되는 개체
// rvalue : lvalue가 아닌 나머지

void Knight_Copy(Knight _Knight)
{
	_Knight.m_Hp = 100;
}

void Knight_LvalueRef(Knight& _Knight)
{

}

void Knight_constLvalueRef(const Knight& _Knight)
{

}

void Knight_RvalueRef(Knight&& _Knight)
{
	_Knight.m_Hp = 100;
	_Knight.Printf();
}
int main()
{
	Knight k1;
	Knight_RvalueRef(Knight());
	Knight_RvalueRef(static_cast<Knight&&>(k1));
}