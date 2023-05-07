#include <iostream>
#include <vector>

using namespace std;

template<typename T>
class Iterator
{
public:
	Iterator()
		: m_ptr(nullptr)
	{
	}
	Iterator(T* _ptr)
		: m_ptr(_ptr)
	{
	}

	Iterator& operator++()
	{
		++m_ptr;
		return *this;
	}
	Iterator operator++(int)
	{
		Iterator Temp = *this;
		++m_ptr;
		return Temp;
	}
	Iterator& operator--()
	{
		--m_ptr;
		return *this;
	}
	Iterator operator--(int)
	{
		Iterator Temp = *this;
		--m_ptr;
		return Temp;
	}
	Iterator operator+(int _Val)
	{
		Iterator Temp = *this;
		Temp.m_ptr += _Val;
		return Temp;
	}
	Iterator operator-(int _Val)
	{
		Iterator Temp = *this;
		Temp.m_ptr -= _Val;
		return Temp;
	}

	bool operator==(const Iterator& It)
	{
		return m_ptr == It.m_ptr;
	}
	bool operator!=(const Iterator& It)
	{
		return !(*this == It);
	}
	T& operator*()
	{
		return *m_ptr;
	}


public:
	T* m_ptr;
};

template<typename T>
class Vector
{
public:
	Vector()
		: m_Data(nullptr)
		, m_Size(0)
		, m_Capacity(0)
	{

	}

	~Vector()
	{
		if (m_Data != nullptr)
		{
			delete[] m_Data;
		}
	}

	void push_back(const T& _Val)
	{
		if (m_Size == m_Capacity)
		{
			int NewCapacity = static_cast<int>(m_Capacity * 1.5f);

			if (NewCapacity == m_Capacity)
			{
				++NewCapacity;
			}
			reserve(NewCapacity);
		}
		m_Data[m_Size] = _Val;
		++m_Size;
	}
	void reserve(const int _Capacity)
	{
		m_Capacity = _Capacity;
		T* NewData = new T[_Capacity];
		for (int i = 0; i < m_Size; ++i)
		{
			NewData[i] = m_Data[i];
		}
		if (m_Data)
		{
			delete[] m_Data;
		}
		m_Data = NewData;
	}
	int size()
	{
		return m_Size;
	}
	int capacity()
	{
		return m_Capacity;
	}

	T& operator[](const int _Index)
	{
		return m_Data[_Index];
	}

	typedef class Iterator<T> iterator;

	iterator begin() { return iterator(&m_Data[0]); }
	iterator end() { return begin() + m_Size; }


	void clear()
	{
		m_Size = 0;
	}
public:
	T* m_Data;
	int m_Size;
	int m_Capacity;
};


int main()
{
	Vector<int> v;

	v.reserve(100);

	for (int i = 0; i < 100; ++i)
	{
		v.push_back(i);
		cout << v.size() << " " << v.capacity() << endl;
	}

	for (int i = 0; i < v.size(); ++i)
	{
		cout << v[i] << endl;
	}

	cout << "---------------------------------------" << endl;

	for (Vector<int>::iterator i = v.begin(); i != v.end(); ++i)
	{
		cout << *i << endl;
	}

}