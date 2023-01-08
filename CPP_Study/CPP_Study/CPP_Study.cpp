#include <iostream>

using namespace std;

int a = 1;
int b = 2;

int main()
{

#pragma region 산술연산
	// 산술 연산자에는
	// 대입연산
	// 사칙연산

	// a에 b를 대입하고 b를 반환하라
	// -> b라는 바구니 안에 있는 값을, a라는 바구니 안에다 복사한다.

	// b를 반환한다는것은

	a = b = 3;

	// b에다 3을 대입하고 3을반환 한 후 다시 a에 3을 대입하는것 결국엔 또 3을 반환한다.

	// 사칙연산
	
	a = b + 3; //이런것 + - * / %
	a = b * 3;
	a = b / 3;
	a = b % 3;

	// 속도비교
	a += 3; // a = a + 3;
	a = a + 3;

	// 증감 연산자
	a = a + 1; // add eax, 1 -> inc eax
	a++;
	++a;

	// 순서차이
	b = a++; // b = a -> a = a + 1
	b = ++a; // a = a + 1 - > b = a

#pragma endregion

}
