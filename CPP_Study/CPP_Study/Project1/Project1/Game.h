#pragma once

class Player;
class Filed;

class Game
{
public:
	Game();
	~Game();
public:
	void Init();
	void Update();
	void CreatPlayer();


private:
	Player* m_Player;
	Filed* m_Filed;
};

