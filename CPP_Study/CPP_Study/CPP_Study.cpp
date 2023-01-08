#include <iostream>

using namespace std;

// 1) 변수의 유효범위

// 전역 변수

// 스택
// { } 중괄호의 범위가 생존 범위
// 같은 이름 두번 사용할 때 문제 될 수 있다.

// 2) 연산 우선순위

// 3) 타입 변환

// 4) 사칙 연산 관련

int main()
{

	int hp = 20;
	cout << hp << endl;

	// 바구니 교체

	short hp2 = (short)hp;
	float hp3 = (float)hp;
	unsigned int hp4 = (unsigned int)hp;

	// 곱셈
	// - 오버플로우
	// 나눗셈
	// -0 나누기 조심
	// - 실수 관련
	int maxhp = 1000;
	float ratio = hp / maxhp;
	// hp, maxhp둘다 int형이므로 소수점이 0이 된채로 저장된다.
	// 이를 고치려면 둘중 하나를 float으로 변경해줘야 한다( 실수가 우선순위가 더 높기 때문에)
	float ratio = hp / (float)maxhp;

}
