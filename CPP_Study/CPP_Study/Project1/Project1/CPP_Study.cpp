#include <iostream>

using namespace std;


class Knight
{
public:
	int Hp = 3;
};

template<typename T1, typename T2>
void Print(T1 a, T2 b)
{
	cout << a << endl;
	cout << b << endl;
}

template<typename T>
void Print(T a)
{
	cout << a << endl;
}

template<>
void Print(Knight k1)
{
	cout << k1.Hp << endl;
}
//
//ostream& operator<<(ostream& os, const Knight& k2)
//{
//	os << k2.Hp << endl;
//
//	return os;
//}
int main()
{
	/*
	Print(1, 2);
	Print("안녕하세요", 2);
	Print(1.0f, 2);
	Print(3);*/
	Knight k1;
	Print(k1);
}