#include <iostream>

using namespace std;

struct StatInfo
{
	int hp; // +0
	int attack; // +4
	int defence; // +8
};

void EnterLobby();
StatInfo CreatePlayer();

void CreateMonster(StatInfo* info);
bool StartBattle(StatInfo*, StatInfo*);

int main()
{

	EnterLobby();
	return 0;
}
void EnterLobby()
{
	cout << "로비에 입장했습니다" << endl;
	
	StatInfo Player;

	Player.attack = 0xbbbbbbbb;
	Player.hp = 0xbbbbbbbb;
	Player.defence = 0xbbbbbbbb;

	Player = CreatePlayer();

	StatInfo Monster;

	Monster.attack = 0xbbbbbbbb;
	Monster.hp = 0xbbbbbbbb;
	Monster.defence = 0xbbbbbbbb;

	CreateMonster(&Monster);

	bool Victory = StartBattle(&Player, &Monster);

	if (Victory == true)
	{
		cout << "승리!" << endl;
	}
	else
		cout << "패배!" << endl;
}

StatInfo CreatePlayer()
{
	StatInfo Ret;

	cout << "플레이어 생성" << endl;
	

	Ret.hp = 100;
	Ret.attack = 10;
	Ret.defence = 2;

	return Ret;
}

void CreateMonster(StatInfo* Info)
{
	cout << "몬스터 생성" << endl;

	Info->hp = 40;
	Info->defence = 8;
	Info->attack = 1;
}

bool StartBattle(StatInfo* Player, StatInfo* Monster)
{
	while (true)
	{
		int Damage = Player->attack - Monster->defence;
			if (Damage < 0)
				Damage = 0;

			Monster->hp -= Damage;
			if (Monster->hp < 0)
			{
				Monster->hp = 0;
			}

			cout << "몬스터 HP : " << Monster->hp << endl;

			if (Monster->hp == 0)
			{
				return true;
			}

			int damage = Monster->attack - Player->defence;
			if (Damage < 0)
			{
				Damage = 0;
			}

			cout << "플레이어 HP : " << Player->hp << endl;

			Player->hp -= damage;

			if (Player->hp < 0)
				Player->hp = 0;

			if (Player->hp == 0)
				return false;
	}

}

