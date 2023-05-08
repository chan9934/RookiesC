#include<iostream>

#include <list>

using namespace std;

template<typename T>
class Node
{
public:
	Node()
		: m_Prev (nullptr)
		, m_Next (nullptr)
		, m_Data (T())
	{

	}
	Node(const T& _Value)
		: m_Prev(nullptr)
		, m_Next(nullptr)
		, m_Data(_Value)
	{

	}

	bool operator==(const Node& _Right)
	{
		return ((m_Prev == _Right.m_Prev) && (m_Next == _Right.m_Next) && (m_Data == _Right.m_Data));
	}
		
public:
	Node<T>* m_Prev;
	Node<T>* m_Next;
	T m_Data;
};


template<typename T>
class Iterator
{
public:
	Iterator()
		: m_Node(nullptr)
	{

	}
	Iterator(Node<T>* _Node)
		: m_Node(_Node)
	{

	}

	Iterator& operator++()
	{
		m_Node = m_Node->m_Next;
		return *this;
	}
	Iterator& operator++(int)
	{
		Iterator<T>* _TempNode = *this;
		m_Node = m_Node->m_Next;
		return _TempNode;
	}

	Iterator& operator--()
	{
		m_Node = m_Node->m_Prev;
		return *this;
	}
	Iterator& operator--(int)
	{
		Iterator<T>* _TempNode = *this;
		m_Node = m_Node->m_Prev;
		return _TempNode;
	}

	T& operator*()
	{
		return m_Node->m_Data;
	}

	bool operator ==  (const Iterator& _Right)
	{
		return m_Node == _Right.m_Node;
	}
	bool operator !=  (const Iterator& _Right)
	{
		return m_Node != _Right.m_Node;
	}
public:
	Node<T>* m_Node;
};
template<typename T>
class List
{
public:
	List()
		: m_Size(0)
	{
		m_Header = new Node<T>();
		m_Header->m_Next = m_Header;
		m_Header->m_Prev = m_Header;
	}
	~List()
	{
		while (m_Size != 0)
		{
			pop_back();
		}
		delete m_Header;
	}
	void push_back(const T& _Value)
	{
		Add_Node(m_Header, _Value);
	}
	void pop_back()
	{
		RemoveNode(m_Header->m_Prev);
	}

	Node<T>* Add_Node(Node<T>* _Node, const T& _Value)
	{
		Node<T>* _Prev_Node = _Node->m_Prev;
		Node<T>* _New_Node = new Node<T>();
		_Prev_Node->m_Next = _New_Node;
		_New_Node->m_Prev = _Prev_Node;

		_New_Node->m_Next = _Node;
		_Node->m_Prev = _New_Node;
		_Node->m_Data = _Value;
		++m_Size;

		return _Node;
	}

	Node<T>* RemoveNode(Node<T>* _Node)
	{
		Node<T>* _Before = _Node->m_Prev;
		Node<T>* _After = _Node->m_Next;
		_Before->m_Next = _After;
		_After->m_Prev = _Before;
		delete _Node;
		--m_Size;
		return _After;
	}

	int size()
	{
		return m_Size;
	}

	typedef Iterator<T> iterator;

	iterator begin()
	{
		return iterator(m_Header->m_Next);
	}
	iterator end()
	{
		return iterator(m_Header);
	}
	iterator erase(iterator it)
	{

		return iterator(RemoveNode(it.m_Node));
	}
	iterator insert(iterator it, const T& _Value)
	{
		return iterator(Add_Node(it.m_Node, _Value));
	}

public:
	Node<T>* m_Header;
	int m_Size;
};

int main()
{
	List<int> li;
	List<int>::iterator eraseit;
	for (int i = 0; i < 10; ++i)
	{
		if (i == 5)
		{
			eraseit = li.insert(li.end(), i);
		}
		else
		{
			li.push_back(i);
		}
	}
	li.pop_back();

	li.erase(eraseit);

	for (List<int>::iterator i = li.begin(); i != li.end(); ++i)
	{
		cout << *i << endl;
	}
}