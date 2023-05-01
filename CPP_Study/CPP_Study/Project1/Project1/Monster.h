#pragma once

#include "Creature.h"

enum MonsterType
{
	MT_Slime = 1,
	MT_Orc = 2,
	MT_Goblin = 3
};


class Monster : public Creature
{
public:
	Monster(int _MonsterType)
		: Creature(CT_Monster)
		, m_MonsterType(_MonsterType)
	{

	}
	virtual void PrintInfo();

private:
	int m_MonsterType;
};

class Slime : public Monster
{
public:
	Slime()
		: Monster(MT_Slime)
	{
		m_Hp = 50;
		m_Attack = 5;
		m_Defence = 2;
	}
};
class Orc : public Monster
{
public:
	Orc()
		: Monster(MT_Orc)
	{
		m_Hp = 80;
		m_Attack = 8;
		m_Defence = 3;
	}
};
class Goblin : public Monster
{
public:
	Goblin()
		: Monster(MT_Goblin)
	{
		m_Hp = 100;
		m_Attack = 15;
		m_Defence = 4;
	}
};