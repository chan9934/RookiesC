#include <iostream>
#include<vector>

using namespace std;

enum class ItemType
{
	None,
	Armor,
	Weapon,
	Jewelry,
	Consumable
};

enum class Rarity
{
	Common,
	Rare,
	Unique
};

class Item
{
public:
	Item()
	{

	}

	Item(int _ItemId, ItemType _Type, Rarity _Rarity)
		: m_ItemId(_ItemId)
		, m_Type(_Type)
		, m_Rarity(_Rarity)
	{

	}
	
public:
	int m_ItemId = 0;
	ItemType m_Type = ItemType::None;
	Rarity m_Rarity = Rarity::Common;
};

int main()
{
	vector<Item> v;
	v.push_back(Item(1, ItemType::Weapon, Rarity::Common));
	v.push_back(Item(2, ItemType::Armor, Rarity::Common));
	v.push_back(Item(3, ItemType::Jewelry, Rarity::Rare));
	v.push_back(Item(4, ItemType::Weapon, Rarity::Unique));

	{
		//struct IsUniqueItem
		//{
		//	bool operator()(const Item& _Item)
		//	{
		//		return _Item.m_Rarity == Rarity::Unique;
		//	}
		//};

		//// 클로져(Closure)
		//auto lambda = [](const Item& _Item) -> bool
		//{
		//	return _Item.m_Rarity == Rarity::Unique;
		//};

		struct FindItemByItemId
		{
			FindItemByItemId(int _ItemID)
				: m_ItemID(_ItemID)
			{
			}

			bool operator()(const Item& _Item)
			{
				return _Item.m_ItemId == m_ItemID;
			}

		public:
			int m_ItemID;
		};

		// [ ] 캡쳐 (Capture) : 함수 객체 내부에 변수를 저장하는 개념과 유사
		// 사진을 찰칵 [캡쳐] 하듯 일종의 스냅샷을 찍는다고 이해
		// 기본 캡쳐 모드 : 값(복사) 방식(=) 참조 방식 (&)
	/*	int _ItemId = 4;
		auto Lambda = [&](const Item& _Item) -> bool {return _Item.m_ItemId == _ItemId; };
		_ItemId = 10;*/

		struct FindItem
		{
		public:
			FindItem(int _ItemId, Rarity _Rarity, ItemType _ItemType)
				: m_ItemId(_ItemId)
				, m_Rarity(_Rarity)
				, m_ItemType(_ItemType)
			{

			}

			bool operator()(const Item& _Item)
			{
				return m_ItemId == _Item.m_ItemId && m_Rarity == _Item.m_Rarity && m_ItemType == _Item.m_Type;
			}
		public:
			int m_ItemId;
			Rarity m_Rarity;
			ItemType m_ItemType;
		};

		int T_ItemId = 4;
		Rarity T_Rarity = Rarity::Unique;
		ItemType T_Type = ItemType::Weapon;
		auto Labmda = [&](const Item& _Item)->bool {return T_ItemId == _Item.m_ItemId && T_Rarity == _Item.m_Rarity && T_Type == _Item.m_Type; };
		auto Findit = std::find_if(v.begin(), v.end(),Labmda);
		if (Findit != v.end())
		{
			cout << "아이템 ID : " << Findit->m_ItemId << endl;
		}
	}
	{
		class Knight
		{
		public:
			auto ResetHpJob()
			{
				return [=]()
				{
					m_Hp = 100;
				};
			}
		public:
			int m_Hp = 100;
		};


		Knight* k = new Knight();
		auto job = k->ResetHpJob();
		job();
	}
	
}