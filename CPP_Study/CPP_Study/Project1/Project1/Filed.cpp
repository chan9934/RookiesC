#include "Filed.h"
#include "Monster.h"
#include "Player.h"
#include <iostream>
Filed::Filed() : m_Monster(nullptr)
{

}
Filed::~Filed()
{
	if (m_Monster != nullptr)
	{
		delete m_Monster;
		m_Monster = nullptr;
	}
}

void Filed::Update(Player* _Player)
{
	if (m_Monster == nullptr)
		CreateMonster();

	StartBattle(_Player);
}

void Filed::CreateMonster()
{
	int MonsterIndex = 1 + rand() % 3;

	switch (MonsterIndex)
	{
	case MT_Slime:
		m_Monster = new Slime();
		break;
	case MT_Orc:
		m_Monster = new Orc();
		break;
	case MT_Goblin:
		m_Monster = new Goblin();
		break;

	}

}

void Filed::StartBattle(Player* _Player)
{
	while (true)
	{
		_Player->PrintInfo();
		m_Monster->PrintInfo();

		m_Monster->SetDamage(_Player);
		if (m_Monster->IsDead())
		{
			m_Monster->PrintInfo();
			delete m_Monster;
			m_Monster = nullptr;
			break;

		}
		_Player->SetDamage(m_Monster);
			if (_Player->IsDead())
			{

				_Player->PrintInfo();
				break;
			}

	}
}