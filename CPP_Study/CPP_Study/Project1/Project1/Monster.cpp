#include "Monster.h"
#include <iostream>

using namespace std;
void Monster::PrintInfo()
{
	cout << "--------------------------" << endl;
	cout << "[ 몬스터 정보 ] " << "Hp : " << m_Hp << "Attack : " << m_Attack << "Defence : " << m_Defence << endl;
	cout << "--------------------------" << endl;
}