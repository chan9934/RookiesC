#include <iostream>

using namespace std;

int Input;
//
//const int Rock = 1;
//const int Scissors = 2;
//const int Paper = 3;

enum ENUM_SRP
{
	Rock,
	Scissors,
	Paper,
};

//#이 붙은것 -> 전처리 지시문
#define DEFINE_SCISSORS cout << "Hello" << endl;


int Computer;

int Win = 0;
int Lose = 0;


int main()
{
	DEFINE_SCISSORS
	srand(time(0));

	int Color = Rock;


	while (true)
	{
		cout << "바위(1) 가위(2) 보(3) 골라주세요!" << endl;

		cout << "현재 승률 : ";

		if ((Win + Lose) == 0)
		{
			cout << "없음" << endl;
		}
		else
		{

			cout << (int)(((float)Win / (Win + Lose)) * 100) << endl;
		}

		cout << "> ";

		cin >> Input;


		Computer = 1 + (rand() % 3);

		switch (Input)
		{
		case Rock:
			cout << "바위(님) vs ";
			switch (Computer)
			{
			case Rock:
				cout << "바위(컴퓨터) 비겼습니다." << endl;
				break;
			case Scissors:
				cout << "가위(컴퓨터) 이겼습니다." << endl;
				++Win;
				break;
			case Paper:
				cout << "보(컴퓨터) 졌습니다." << endl;
				++Lose;
				break;
			default:
				break;
			}
			break;
		case Scissors:
			cout << "가위(님) vs ";
			switch (Computer)
			{
			case Rock:
				cout << "바위(컴퓨터) 졌습니다." << endl;
				++Lose;
				break;
			case Scissors:
				cout << "가위(컴퓨터) 비겼습니다." << endl;
				break;
			case Paper:
				cout << "보(컴퓨터) 이겼습니다." << endl;
				++Win;
				break;
			default:
				break;
			}
			break;
		case Paper:
			cout << "보(님) vs ";
			switch (Computer)
			{
			case Rock:
				cout << "바위(컴퓨터) 이겼습니다." << endl;
				++Win;
				break;
			case Scissors:
				cout << "가위(컴퓨터) 졌습니다." << endl;
				++Lose;
				break;
			case Paper:
				cout << "보(컴퓨터) 비겼습니다." << endl;
				break;
			default:
				break;
			}
			break;
		default:
			return 0;
			break;

		}


	}


}