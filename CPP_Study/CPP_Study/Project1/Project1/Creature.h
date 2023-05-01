#pragma once

enum CreatureType
{
	CT_Player = 1,
	CT_Monster = 2
};
class Creature
{

public:
	Creature(int _CreatureType)
		: m_CreatureType(_CreatureType)
		, m_Hp(0)
		, m_Attack(0)
		, m_Defence(0)
	{

	}
	virtual ~Creature()
	{

	}
	virtual	void PrintInfo() = 0;
	void SetDamage(Creature* Attacked);
	bool IsDead()
	{
			return (m_Hp <= 0);
	}
	

protected:
	int m_CreatureType;
	int m_Hp;
	int m_Attack;
	int m_Defence;
};

