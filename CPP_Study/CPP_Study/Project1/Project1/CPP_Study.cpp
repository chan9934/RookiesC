#include <iostream>

using namespace std;

class Item
{
public:
	Item()
	{
		cout << "Item()" << endl;
	}
	Item(int IT) : ItemType(IT)
	{

	}

	Item(const Item& Item)
	{
		cout << "Item(const Item& Item" << endl;
	}

	virtual ~Item()
	{
		cout << "~Item()" << endl;
	}

	int ItemType = 0;
	int ItemObid = 0;
	char Dummy[4096] = {};

};

enum ItemType
{
	IT_Weapon = 1,
	IT_Armor = 2
};

class Weapon : public Item
{
public:
	Weapon() : Item(IT_Weapon)
	{
		cout << "Weapon()" << endl;
		damage = rand() % 100;
	}
	virtual ~Weapon()
	{
		cout << "~Weapon()" << endl;
	}

	int damage = 0;
};
class Armor : public Item
{
public:
	Armor() : Item(IT_Armor)
	{
		cout << "Armor()" << endl;
	}
	virtual 	~Armor()
	{
		cout << "~Armor()" << endl;
	}
};

void Function(Item m_Item)
{

}

void FunctionPtr(Item* Ptr_Item)
{

}


int main()
{
	//{
	//	Item I1[100];
	//	cout << "------------------------------" << endl;

	//	Item* I2[100];
	//	for (int i = 0; i < 100; ++i)
	//	{
	//		I2[i] = new Item();
	//	}
	//	for (int i = 0; i < 100; ++i)
	//	{
	//		delete I2[i];
	//	}
	//	
	//	
	//}

	srand((unsigned int)(time(nullptr)));

	Item* _item[20] = {};

	for (int i = 0; i < 20; ++i)
	{
		int ItemType = (rand() % 2) + 1;

		switch (ItemType)
		{
		case IT_Weapon:
			_item[i] = new Weapon();
			break;
		case IT_Armor:
			_item[i] = new Armor();
			break;
		}
	}

	for (int i = 0; i < 20; ++i)
	{
		if (_item[i] == nullptr)
		{
			continue;
		}
		if ((_item[i]->ItemType )== IT_Weapon)
		{
			Weapon* weapon = (Weapon*)_item[i];
			cout << "Weapon Damage : " << weapon->damage << endl;
		}
	}


	for (int i = 0; i < 20; ++i)
	{
		if (_item[i] == nullptr)
		{
			continue;
		}
		delete _item[i];
	}

}