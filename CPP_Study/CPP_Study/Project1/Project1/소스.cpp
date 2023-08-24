#include <iostream>

using namespace std;

class FileSystem
{
public:
	static FileSystem& Instance()
	{
		static FileSystem* _instance = new FileSystem();
		return *_instance;
	}
	int a = 32;

private:
	FileSystem(){ }

};

int main()
{
	FileSystem& fs1 = FileSystem::Instance();
	FileSystem& fs2 = FileSystem::Instance();
	cout << fs1.a << endl;
	fs1.a = 5;
	cout << fs1.a << endl;
	cout << fs2.a << endl;

}