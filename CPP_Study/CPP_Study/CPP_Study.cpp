#include <iostream>

using namespace std;

class Player
{
public :
	int id;
};

int id()
{
	static int s_id = 1;
	return s_id++;
}

int main()
{

}