#include <iostream>

using namespace std;

int* Test()
{
	int a = 3;
	return &a;
}

void TestPointer(int* Pointer)
{
	int a[100] = {};
	a[99] = 0xAAAAAAAA;
	*Pointer = 3;
}
int main()
{

	//int First[5] = { 4, 2, 3, 1, 4 };
	//int Secnd[5] = { 2, 5, 1, 2, 4 };

	//int Apartment[2][5] = { { 4, 2, 3, 1, 4 }, { 2, 5, 1, 2, 4 } };

	//for (int Floor = 0; Floor < 2; ++Floor)
	//{
	//	for (int Room = 0; Room < 5; ++Room)
	//	{
	//		int Num = Apartment[Floor][Room];

	//		cout << Num << " ";
	//	}
	//	cout << endl;
	//}

	//int Appartment1D[10] = { 4, 2, 3, 1, 4, 2, 5, 1, 2, 4 };

	//for (int Floor = 0; Floor < 2; ++Floor)
	//{
	//	for (int Room = 0; Room < 5; ++Room)
	//	{
	//		int Num = Appartment1D[(Floor * 5) + Room];

	//		cout << Num << " ";
	//	}
	//	cout << endl;
	//}

	int Appartment2D[2][2] = { { 1, 2 }, { 3, 4 } };
	int(*P2)[2] = Appartment2D;
	cout << (*P2)[0] << endl;
	cout << (*P2)[1] << endl;
	cout << (*P2 + 1)[1] << endl;
	cout << (*P2 + 2)[1] << endl;

	int* Pointer = Test();
	TestPointer(Pointer);


	

}