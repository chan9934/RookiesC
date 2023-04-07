#include <iostream>

using namespace std;

int main()
{

	struct Player
	{
		int Hp;
		int Damage;
	};

	Player Pla;
	Pla.Hp = 100;
	Pla.Damage = 10;

	Player* PlayerPtr = &Pla; // PlayerPtr라는 포인터에 Pla구조체의 주소가 저장 되어있고
	// 현재 int 형이기에 Hp는 해당 주소에 + 0 Damage는 해당 주소에 + 4 위치에 있다.
	// 그리고 해당 포인터를 사용해 해당 구조체에 접근 하려면
	(*PlayerPtr).Hp = 200;
	(*PlayerPtr).Damage = 200;
	

	return 0;
}