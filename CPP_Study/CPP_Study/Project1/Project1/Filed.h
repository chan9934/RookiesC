#pragma once
class Player;
class Monster;

class Filed
{
public:
	Filed();
	~Filed();
	void Update(Player* _Player);
	void CreateMonster();
	void StartBattle(Player* _Player);

private:
	Monster* m_Monster;
};

