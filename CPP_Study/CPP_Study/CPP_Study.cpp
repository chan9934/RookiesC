#include <iostream>

using namespace std;

enum PlayerType
{
	PT_Knite = 1,
	PT_Archer = 2,
	PT_Mage = 3
};

enum MonsterType
{
	MT_Slime = 1,
	MT_Orc = 2,
	MT_Skeleton = 3
};

struct StatInfo
{
	int Hp = 0;
	int Deffence = 0;
	int Attack = 0;
};

void EnterLobby();
void PrintMessage(const char* msg);
void CreatePlayer(StatInfo* PlayerInfo);
void PrintStatInfo(const char* name, const StatInfo& Info);
void EnterGame(StatInfo* PlayerInfo);
void CreateMonsters(StatInfo MonsterInfo[], int Count);
bool EnterBattle(StatInfo* PlayerInfo, StatInfo* MonsterInfo);


int main()
{
	EnterLobby();
}

void EnterLobby()
{
	while (true)
	{
		PrintMessage("로비에 입장했습니다");
		StatInfo Player;
		
		CreatePlayer(&Player);
		PrintStatInfo("Player", Player);
	}
}

void PrintMessage(const char* msg)
{
	cout << "******************************" << endl;
	cout << msg << endl;
	cout << "******************************" << endl;
}

void CreatePlayer(StatInfo* PlayerInfo)
{
	PrintMessage("캐릭터 생성창");
	PrintMessage("[1] 기사 [2] 궁수 [3] 법사");
	int Input;
	cin >> Input;
	switch (Input)
	{
	case PT_Knite:
		(*PlayerInfo).Hp = 100;
		(*PlayerInfo).Attack = 10;
		(*PlayerInfo).Deffence = 5;
		break;
	case PT_Archer:
		(*PlayerInfo).Hp = 80;
		(*PlayerInfo).Attack = 15;
		(*PlayerInfo).Deffence = 3;
		break;
	case PT_Mage:
		(*PlayerInfo).Hp = 50;
		(*PlayerInfo).Attack = 25;
		(*PlayerInfo).Deffence = 1;
		break;
	}
}

void PrintStatInfo(const char* name, const StatInfo& Info)
{
	cout << "******************************" << endl;
	cout << name << " : " << "HP= " << Info.Hp << "ATT= " << Info.Attack << "DEF= " << Info.Deffence << endl;
	cout << "******************************" << endl;
}

void EnterGame(StatInfo* PlayerInfo)
{
}

void CreateMonsters(StatInfo MonsterInfo[], int Count)
{
}

bool EnterBattle(StatInfo* PlayerInfo, StatInfo* MonsterInfo)
{
	return false;
}
