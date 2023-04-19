#include <iostream>

using namespace std;

enum
{
	PT_Knite = 1,
	PT_Archer = 2,
	PT_Mage = 3
};

enum
{
	MT_Slime = 1,
	MT_Ork = 2,
	MT_Skeleton = 3
};

struct StatInfo
{
	int Hp;
	int Attack;
	int Deffence;
};

void EnterLobby();
void PrintMessage(const char* msg);
void CreatePlayer(StatInfo* playerinfo);
void PrintStatInfo(const char* Name, const StatInfo& info);
void EnterGame(StatInfo* playerInfo);
void CreateMonsters(StatInfo monsterInfo[], int count);
bool EnterBattle(StatInfo* playerinfo, StatInfo* monsterinfo);

int main()
{
	EnterLobby();
}

void EnterLobby()
{
	while (true)
	{
		PrintMessage("캐릭터 생성창");
		PrintMessage("[1] 기사 [2] 궁수 [3] 마법사");
		StatInfo playerinfo;
		CreatePlayer(&playerinfo);
		PrintStatInfo("Player", playerinfo);
		EnterGame(&playerinfo);


	}
}

void PrintMessage(const char* msg)
{
	cout << "*************************" << endl;
	cout << msg << endl;
	cout << "*************************" << endl;
}

void CreatePlayer(StatInfo* playerinfo)
{
	int input;
	cin >> input;

	bool unselect = true;
	while(unselect)
	{
		switch (input)
		{
		case PT_Knite:
			playerinfo->Hp = 100;
			playerinfo->Attack = 10;
			playerinfo->Deffence = 5;
			unselect = false;
			break;
		case PT_Archer:
			playerinfo->Hp = 80;
			playerinfo->Attack = 15;
			playerinfo->Deffence = 3;
			unselect = false;
			break;
		case PT_Mage:
			playerinfo->Hp = 50;
			playerinfo->Attack = 25;
			playerinfo->Deffence = 1;
			unselect = false;
			break;
		default:
			break;
		}
	}
}

void PrintStatInfo(const char* Name, const StatInfo& info)
{
	cout << "*************************" << endl;
	cout << Name << " : " << "Hp="<<info.Hp <<" ATT=" << info.Attack << " DEF=" << info.Deffence << endl;
	cout << "*************************" << endl;

}

void EnterGame(StatInfo* playerInfo)
{
	PrintMessage("게임에 입장했습니다");
	StatInfo monsterinfo;
	CreateMonsters(&monsterinfo, 2);
	if (EnterBattle(playerInfo, &monsterinfo))
	{
		PrintMessage("Game Over");
	}
}

void CreateMonsters(StatInfo monsterInfo[], int count)
{
	srand(time(0));
	

	for (int i = 0; i < count; ++i)
	{
		int Temp = rand() % 3;
		switch (Temp)
		{
		case MT_Slime:
			monsterInfo[i].Hp = 30;
			monsterInfo[i].Attack = 5;
			monsterInfo[i].Deffence = 1;
			break;
		case MT_Ork:
			monsterInfo[i].Hp = 40;
			monsterInfo[i].Attack = 8;
			monsterInfo[i].Deffence = 2;
			break;
		case MT_Skeleton:
			monsterInfo[i].Hp = 50;
			monsterInfo[i].Attack = 15;
			monsterInfo[i].Deffence = 3;
			break;
		}
		
		PrintStatInfo("Monster", monsterInfo[i]);
	}
}

bool EnterBattle(StatInfo* playerinfo, StatInfo* monsterinfo)
{
	while (true)
	{

	}
	return true;
}
