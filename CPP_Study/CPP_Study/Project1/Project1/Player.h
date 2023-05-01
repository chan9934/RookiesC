#pragma once
#include "Creature.h"

enum PlayerType
{
	PT_Knight = 1,
	PT_Archer = 2,
	PT_Mage = 3
};

class Player : public Creature
{

public:
	Player(int _PlayerType)
		: Creature(CT_Player)
		, m_PlayerType(_PlayerType)
	{

	}
	virtual ~Player()
	{
	}
	virtual void PrintInfo();

protected:
	int m_PlayerType;
};

class Knight : public Player
{
public:
	Knight() : Player(PT_Knight)
	{
		m_Hp = 50;
		m_Attack = 5;
		m_Defence = 2;
	}
};
class Archer : public Player
{
public:
	Archer() : Player(PT_Archer)
	{
		m_Hp = 80;
		m_Attack = 8;
		m_Defence = 3;
	}
};
class Mage : public Player
{
public:
	Mage() : Player(PT_Mage)
	{
		m_Hp = 100;
		m_Attack = 15;
		m_Defence = 4;
	}
};