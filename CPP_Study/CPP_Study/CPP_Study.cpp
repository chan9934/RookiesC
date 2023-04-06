#include <iostream>

using namespace std;


enum PlayerType
{
	PT_Knight = 1,
	PT_Archer = 2,
	PT_Mage = 3,
};

enum MonsterType
{
	MT_Slime = 1,
	MT_Orc,
	MT_Skeleton,
};

int PlayerType;
int Hp;
int Attack;
int Defence;

int MonsterType;
int MonsterHp;
int MonsterAttack;
int MonsterDefence;

void EnterLobby();
void SelectPlayer();
void EnterFiled();
void CreateRandomMonster();
void EnterBattle();

int main()
{
	// 랜덤 시드 설정
	srand(time(0));

	EnterLobby();
	return 0;
}

void EnterLobby()
{

	while (true)
	{
		cout << "----------------------------" << endl;
		cout << "로비에 입장했습니다!" << endl;
		cout << "---------------------------" << endl;

		//플레이어 직업 선택
		SelectPlayer();

		cout << "----------------------------" << endl;
		cout << "(1) 필드 입장 (2) 게임 종료" << endl;
		cout << "----------------------------" << endl;

		int input;
		cin >> input;

		if (input == 1)
		{
			EnterFiled();
		}
		else
		{
			return;
		}

		
	}
}

void SelectPlayer()
{
	while (true)
	{
		cout << "----------------------------" << endl;
		cout << "직업을 골라주세요!" << endl;
		cout << "(1) 기사 (2) 궁수 (3) 법사" << endl;
		cout << "> ";

		cin >> PlayerType;

		switch (PlayerType)
		{
		case PlayerType::PT_Knight:
			cout << "기사 생성중...!" << endl;
			Hp = 150;
			Attack = 10;
			Defence = 5;
			return;

		case PlayerType::PT_Archer:
			cout << "궁수 생성중...!" << endl;
			Hp = 100;
			Attack = 15;
			Defence = 3;
			return;

		case PlayerType::PT_Mage:
			cout << "마법사 생성중...!" << endl;
			Hp = 80;
			Attack = 25;
			Defence = 0;
			return;

		default:
			break;

		}
	}

}

void EnterFiled()
{
	while (true)
	{
		cout << "----------------------------" << endl;
		cout << "필드에 입장했습니다!" << endl;
		cout << "----------------------------" << endl;

		cout << "[PLAYER] HP : " << Hp << " / ATT : " << Attack << " / DEF : " << Defence << endl;

		CreateRandomMonster();

		cout << "----------------------------" << endl;
		cout << "(1) 전투 (2) 도주" << endl;
		cout << "> ";

		int input;
		cin >> input;

		if (input == 1)
		{
			EnterBattle();
			if (Hp == 0)
			{
				return;
			}
		}
		else
		{
			return;
		}

	}
	
}

void CreateRandomMonster()
{
	// 1-3
	MonsterType = 1 + rand() % 3;

	if (MonsterType == MT_Slime)
	{
		cout << "슬라임 생성중...! (HP:15 / ATT:5 / DEF:0)" << endl;
		MonsterHp = 15;
		MonsterAttack = 5;
		MonsterDefence = 0;
	}
	else if (MonsterType == MT_Orc)
	{

		cout << "오크 생성중...! (HP:40 / ATT:10 / DEF:3)" << endl;
		MonsterHp = 40;
		MonsterAttack = 10;
		MonsterDefence = 3;
	}
	else
	{

		cout << "해골 생성중...! (HP:80 / ATT:15 / DEF:5)" << endl;
		MonsterHp = 80;
		MonsterAttack = 15;
		MonsterDefence = 5;
	}
}

void EnterBattle()
{
	while (true)
	{
		int Damage = Attack - MonsterDefence;
		if (Damage < 0)
			Damage = 0;

		// 선빵
		MonsterHp -= Damage;
		if (MonsterHp < 0)
			MonsterHp = 0;

		cout << "몬스터 남은 체력 : " << MonsterHp << endl;

		if (MonsterHp == 0)
		{
			cout << "몬스터를 처치했습니다!" << endl;
			return;
		}

		Damage = MonsterAttack - Defence;
		if (Damage < 0)
			Damage = 0;

		// 반격
		Hp -= Damage;
		if (Hp < 0)
			Hp = 0;

		cout << "플레이어 남은 체력 : " << Hp << endl;

		if (Hp == 0)
		{
			cout << "당신은 사망했습니다..." << endl;
			return;
		}
	}
}