#include <iostream>

using namespace std;

int a = 1;
int b = 2;

bool isSame;
bool isDifferent;
bool isGreater;
bool isSmaller;

bool test;

int hp = 100;
bool isInvincible = true;

int main()
{

#pragma region 비교 연산

	// 언제 필요한가?
	// ex) 체력이 0이 되면 사망
	// ex) 체력이 30&% 이하면 궁극기 발동 ( 100 * hp / maxHp)
	// ex) 경험치가 100 이상이면 레벨업

	// a == b
	// 같으면 1, 다르면 0
	isSame = (a == b);

	// a != b : a와 b의 값이 다른가?
	// 다르면 1, 같으면 0
	isDifferent = (a != b);

	// a > b : a가 b보다 큰가?
	// a >= b : a가 b보다 크거나 같은가?
	// 맞으면 1 아니면 0
	isGreater = (a > b);

	// a < b : a가 b보다 작은가?
	// a <= b : a가 b보다 작거나 같은가?
	// 맞으면 1 아니면 0
	isSmaller = (a < b);


#pragma endregion

#pragma region 논리연산
	// 언제 필요한가? 조건에 대한 논리적 사고가 필요할 때
	// ex) 로그인할 때 아이디도 같고 AND 비밀번호도 같아야 한다.
	// ex) 길드 마스터이거나 OR 운영자 계쩡이면 길드 해산 가능

	// ! not
	// 0이면 1, 그 외 0
	test = !isSame; // 사실상 isDifferent의 의미

	// && and
	// a && b -> 둘다 1이면 1, 그 외 0
	test = (hp <= 0 && isInvincible == false); // 죽음

	// || or
	// a || b -> 둘 중 하나라도 1이면 1 (둘다 0이면 0)
	test = (hp > 0 || isInvincible == true); // 살았음



#pragma endregion

}
