#include "Game.h"
#include "Player.h"
#include "Filed.h"
#include <iostream>

using namespace std;

Game::Game()
	: m_Player(nullptr)
	, m_Filed(nullptr)
{

}
Game::~Game()
{
	if (m_Player != nullptr)
	{
		delete m_Player;
		m_Player = nullptr;
	}

	if (m_Filed != nullptr)
	{
		delete m_Filed;
		m_Filed = nullptr;
	}
	
}

void Game::Init()
{
	m_Filed = new Filed();
}

void Game::Update()
{
	if (m_Player == nullptr)
	{
		CreatPlayer();
	}
	if (m_Player->IsDead())
	{
		delete m_Player;
		m_Player = nullptr;
		CreatPlayer();
	}
	m_Filed->Update(m_Player);

}

void Game::CreatPlayer()
{
	while (m_Player == nullptr)
	{

		cout << "*******************************" << endl;
		cout << "캐릭터를 생성하세요!" << endl;
		cout << "(1) 기사 (2) 궁수 (3) 법사" << endl;
		cout << "*******************************" << endl;
		int PlayerType;
		cin >> PlayerType;
		switch (PlayerType)
		{
		case PT_Knight:
			m_Player = new Knight();
			break;
		case PT_Archer:
			m_Player = new Archer();
			break;
		case PT_Mage:
			m_Player = new Mage();
			break;
		}

	}
}

