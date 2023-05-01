#include "Player.h"
#include <iostream>

using namespace std;

void Player::PrintInfo()
{

		cout << "--------------------------" << endl;
		cout << "[ 플레이어 정보 ] " << "Hp : " << m_Hp << "Attack : " << m_Attack << "Defence : " << m_Defence << endl;
		cout << "--------------------------" << endl;
	
}