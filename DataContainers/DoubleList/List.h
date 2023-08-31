#pragma once
#include <iostream>
using namespace std;

#define tab "\t"
#define delimiter "\n------------------------------------------------\n"



template<typename T>class List
{
	class Element
	{
		T Data;
		Element* pNext;
		Element* pPrev;

	public:
		Element(T Data, Element* pNext = nullptr, Element* pPrev = nullptr);
		~Element();
		friend class List; //Печень и человек
	}*Head, * Tail;//Вписываем создаваемые объекты
	unsigned int size;
	class ConstBaseIterator
	{
	protected: //для наследования
		Element* Temp;
	public:
		ConstBaseIterator(Element* Temp);
		~ConstBaseIterator();

		bool operator==(const ConstBaseIterator& other)const;
		bool operator!=(const ConstBaseIterator& other)const;
		const T& operator*() const;

	};
public:
	class ConstIterator :public ConstBaseIterator
	{
	public:
		ConstIterator(Element* Temp = nullptr);
		~ConstIterator();

		ConstIterator& operator++();
		ConstIterator operator++(int);
		ConstIterator& operator--();
		ConstIterator operator--(int);
	};

	class ConstReverseIterator :public ConstBaseIterator//паблик в данном случае это наследование
	{
	public:
		ConstReverseIterator(Element* Temp = nullptr);
		~ConstReverseIterator();

		ConstReverseIterator& operator++();
		ConstReverseIterator operator++(int);
		ConstReverseIterator& operator--();
		ConstReverseIterator& operator--(int);

	};
	class Iterator :public ConstIterator
	{
	public:
		Iterator(Element* Temp = nullptr) :ConstIterator(Temp) {}
		T& operator*();

	};
	class ReverseIterator :public ConstReverseIterator
	{
	public:
		ReverseIterator(Element* Temp = nullptr) : ConstReverseIterator(Temp) {}
		T& operator*();
	};
	ConstIterator cbegin()const;// если справа написано const, то слева дописывается тоже
	ConstIterator cend()const;
	ConstReverseIterator crbegin()const;
	ConstReverseIterator crend()const;
	Iterator begin();
	Iterator end();
	ReverseIterator rbegin();
	ReverseIterator rend();
	List();
	List(const std::initializer_list<T>& il); //Исправление ошибки с {}
	List(const List<T>& other);//конструктор копирования
	List<T>& operator =(const List<T>& other);
	~List();
	void push_front(T Data);
	void push_back(T Data);
	void insert(T Data, int Index);
	void pop_front();
	void pop_back();
	void erace(int Index);
	void print()const;
	void reverse_print()const;
};

template<typename T>List<T> operator+(const List<T>& left, const List<T>& right);