﻿#include <iostream>
//using namespace std;
using std::cout;
using std::cin;
using std::endl;
#define tab "\t"
//#define DZ
#define delimeter "\n---------------------------------------------------------\n"

template<typename T>class ForwardList;
template<typename T>class Iterator;
template<typename T>ForwardList<T> operator+(const ForwardList<T>& left, const ForwardList<T>& right);
//template<typename T>class Iterator<T>;

template<typename T>class Element
{
	T Data; //значение элемента
	Element<T>* pNext; //адресс следующего элемента // В данном случае, как и вдругих функциях Т в элементе и в дате это один и тот же тип
public:
	//конструктор это метод, а метод это функция
	Element(T Data, Element<T>* pNext = nullptr) :Data(Data), pNext(pNext)
	{
		cout << "EConstructor:\t" << this << endl;
	}



	~Element()
	{
		cout << "EDestructor:\t" << this << endl;
	}
	 friend class ForwardList<T>;
	template<typename T> friend ForwardList<T> operator+(const ForwardList<T>& left, const ForwardList<T>& right);
	 friend class Iterator<T>;
};

template<typename T>class Iterator // класс создан на основе ошибок из дз от 16.08.2023
{
	Element<T>* Temp;
public:
	Iterator(Element<T>* Temp = nullptr) :Temp(Temp)
	{
		cout << "ItConstructor:\t" << this << endl;
	}
	~Iterator()
	{
		cout << "ItDestructor:\t" << this << endl;
	}

	Iterator<T>& operator++()
	{
		Temp = Temp->pNext;
		return *this; //this это Iterator
	}

	bool operator==(const Iterator<T>& other)const
	{
		return this->Temp == other.Temp;
	}
	bool operator!=(const Iterator<T>& other)const
	{
		return this->Temp != other.Temp;
	}

	T operator*() // чтобы получить данные по адресу, его нужно разыменовать с помощью *. Процесс происходит неявно
	{
		return Temp->Data;
	}

	//оператор * и итератор Т...
};

template<typename T>class ForwardList
{
	Element<T>* Head; // Голова списка - содержит адрес начального элемента списка
public:

	Iterator<T> begin() //возвращает итератор
	{
		return Head;
	}
	Iterator<T> end()
	{
		return nullptr;
	}

	ForwardList()
	{
		Head = nullptr; //Если список пуст, то его голова указывает на 0
		//push_front(1);
		cout << "LConstructor:\t" << this << endl;
	}

	ForwardList(const std::initializer_list<T>& il):ForwardList() // ссылка это адрес. Имея адрес, можно изменить значение объекта, поэтому ссылка делается константной.
	{
		for (T const* it = il.begin(); it != il.end(); it++)
		{
			push_back(*it);
		}
		cout << typeid(il.begin()).name() << endl;
	}



	ForwardList(const ForwardList<T>& other):ForwardList()
	{
		cout << "LCopyConstructor:\t" << this << endl;
		//Deep copy:

		/*for (Element* Temp = other.Head; Temp; Temp = Temp->pNext)
			push_back(Temp->Data);*/

		*this = other;//этот список= тот список//this - указатель на объект для которого вызывается метод
		//чтобы получить значение по адресу, ставим - *, т е разыменовываем указатель.
	}

	ForwardList(ForwardList<T>&& other):ForwardList()//делегирования конструктора по умолчанию. Если прога падает
	{
	/*	this->Head = other.Head;
		other.Head = nullptr;*/
		*this = std::move(other); // Функция move() принудительно вызывает MoveAssignment для объекта, если он есть
	}

	~ForwardList()
	{
		while (Head)pop_front();
		cout << "LDestructor:\t" << this << endl;
	}

	//							Operators:

	 ForwardList<T>& operator=(const ForwardList<T>& other)
	{
		if (this == &other)return *this;
		while (Head)pop_front();
		cout << "LCopyAssigment:\t" << this << endl;
		for (Element<T>* Temp = other.Head; Temp; Temp = Temp->pNext)
			push_back(Temp->Data);
		return *this;
	}

	 ForwardList<T>& operator=(ForwardList<T>&& other) 
	 {
		 while (Head)pop_front();
		 this->Head = other.Head;
		 other.Head = nullptr;
		 cout << "LMoveAssignment:\t" << this << endl; // assignment - присваивание
			 return *this;
	 }


	//                           Adding elements:

	void push_front(T Data)
	{
		Head = new Element<T>(Data, Head); //new?

	}
	void push_back(T Data)
	{
		if (Head == nullptr)return push_front(Data);
		Element<T>* Temp = Head;
		while (Temp->pNext)Temp = Temp->pNext;
		Temp->pNext = new Element<T>(Data); // указатель на новый элемент, "сами файлы где-то болтаются"
	}

	// Methods:

	void print()const
	{
		//Element* Temp = Head; //Temp - это итератор
		//// итератор - указатель, при помощи которого можно получить доступ к элементам структуры данных
		//while (Temp)
		//{
		//	cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
		//	Temp = Temp->pNext;
		//}

		cout << "Head: " << Head << endl;
		for (Element<T>* Temp = Head; Temp; Temp = Temp->pNext)
			cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
	}

#ifdef DZ
	void pop_front()
	{
		Element* Temp = Head;
		Head = Temp->pNext;
	//	Temp->pNext;
		delete Temp;
	}

	

	void pop_back()
	{
		Element* Temp = Head;
		while (Temp->pNext->pNext)Temp = Temp->pNext;
		
		delete Temp->pNext;
		Temp->pNext = 0;
		
	}

	void erase(int n)
	{
		
		Element* Temp = Head;
		Element* New = Head;
		if (n == 1)
		{
			Head = Temp->pNext;
			return;
		}
		if (n == 2)
		{
			//delete Temp->pNext;
			New = Temp->pNext;
			Temp->pNext = Temp->pNext->pNext;
			delete New;
			return;
		}
		for (int i = 0; i < n-2; i++)
		{
			Temp = Temp->pNext;
		}
		New = Temp->pNext;
		Temp->pNext = Temp->pNext->pNext;
		delete New;		//Не уверен, что файл удаляется
		
	}

	void insert(int n, int a)
	{
		Element* Temp = Head;
		Element* New = Head;
		if (n == 1)
		{
			push_front(a);
			return;
		}
		if (n == 2)
		{
			New = new Element(a);
			New->pNext = Temp->pNext;
			Temp->pNext = New;
			
			return;
		}
		for (int i = 0; i < n - 2; i++)
		{
			Temp = Temp->pNext;
		}
		New = new Element(a);
		New->pNext = Temp->pNext;
		Temp->pNext = New;

	}


#endif

	void pop_front()
	{
		Element<T>* erased = Head;
		Head = Head->pNext;
		delete erased;
	}

	void pop_back()
	{
		Element<T>* Temp = Head;
		while (Temp->pNext->pNext)Temp = Temp -> pNext;
		delete Temp->pNext;
		Temp->pNext = nullptr; // nullptr это указатель на ноль
	}

	void insert(int Index, T Data)
	{
		if (Index == 0)return push_front(Data);
		Element<T>* Temp = Head;
		for (int i = 0; i < Index-1; i++)
			if(Temp->pNext)
				Temp = Temp->pNext; // если индекс больше списка, до добавляет в конец списка
		Element<T>* New = new Element<T>(Data);
		New->pNext = Temp->pNext;
		Temp->pNext = New;

	}

	void erase(int Index)
	{
		if (Index == 0)return pop_front();
		Element<T>* Temp = Head;
		for (int i = 0; i < Index - 1; i++)
			if (Temp->pNext)
				Temp = Temp->pNext;
		Element<T>* erased = Temp->pNext;
		Temp->pNext = Temp->pNext->pNext;
		delete erased;

	}
	template<typename T> friend ForwardList<T> operator+(const ForwardList<T>& left, const ForwardList<T>& right);



	//char operator[](int i)

};

//#define CHECK_POP_FRONT_AND_BACK
//#define BACE_CHECK
//#define OPERATOR_PLUS_CHECK
//#define RANGE_BASED_FOR_ARRAY
#define MOVE_SEMANTIC_CHECK


template<typename T>ForwardList<T> operator+(const ForwardList<T>& left, const ForwardList<T>& right)
{
	ForwardList<T> cat = left;
	for (Element<T>* Temp = right.Head; Temp; Temp = Temp->pNext)cat.push_back(Temp->Data);
	return cat;
}

void main()
{
	setlocale(LC_ALL, "");

#ifdef BACE_CHECK
	int n;
	cout << "Введите размер списка: "; cin >> n;
	ForwardList list;
	for (int i = 0; i < n; i++)
	{
		//list.push_front(rand() % 100);
		list.push_back(rand() % 100);
	}

	list.push_back(123);
	list.print();

	//dz
#ifdef CHECK_POP_FRONT_AND_BACK
//	list.pop_front();
//	list.print();

//	list.pop_back();
//	list.print();
#endif

//	list.erase(5);
//	list.print();


	/*int value;
	int index;
	cout << "Введите индекс элемента: "; cin >> index;
	cout << "Введите значение элемента: "; cin >> value;
	

	list.insert(index, value);
	list.print();

	cout << "Введите индекс элемента: "; cin >> index;
	list.erase(index);
	list.print();*/

//	ForwardList list2 = list;	//чтобы выполнилось deep copy будет copy constructor(в ином случае участок памяти останется тот же для нового листа
	ForwardList list2;
	list2 = list;				//нужна перегрузка оператора
	list2.print();
#endif

#ifdef OPERATOR_PLUS_CHECK
	ForwardList list1;
	list1.push_back(3);
	list1.push_back(5);
	list1.push_back(8);
	list1.push_back(13);
	list1.push_back(21);
	list1.print();

	ForwardList list2;
	list2.push_back(34);
	list2.push_back(55);
	list2.push_back(89);
	list2.print();

	ForwardList list3 = list1 + list2;
	list3.print();
#endif

#ifdef RANGE_BASED_FOR_ARRAY
	int arr[] = { 3,5,8,13,21 };
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) //sizeof(arr)/sizeof(arr[0]) - вычисление объема массива
		cout << arr[i] << tab;
	cout << endl;

	for (int i : arr) // на месте arr может быть что угодно, что хранит элементы
	{
		cout << i << tab;
	}
	cout << endl;



	ForwardList list = { 3,5,8,13,21 };
	list.print();

	for (int i : list)
	{
		cout << i << tab;
	}
	cout << endl;
#endif

#ifdef MOVE_SEMANTIC_CHECK
	ForwardList<int> list1 = { 3,5,8,13,21 };
	for (int i : list1)cout << i << tab; cout << endl;
	cout << delimeter << endl;

	ForwardList<int> list2 = { 34, 55, 89 };
	for (int i : list2)cout << i << tab; cout << endl;
	cout << delimeter << endl;

	//ForwardList list3 = list1 + list2;//move constructor 21 02
	ForwardList<int> list3;
	list3 = list1 + list2;
	for (int i : list3)cout << i << tab; cout << endl; //move constructor 21 02
	
	
	cout << delimeter << endl;

	ForwardList<double> d_list_1 = { 2.7, 3.14, 5.1 };
	ForwardList<double> d_list_2 = { 7.5, 8.2, 4.4, 9.5 };
	ForwardList<double> d_list_3 = d_list_1 + d_list_2;
	for (double i : d_list_1)cout << i << tab; cout << endl;
	for (double i : d_list_2)cout << i << tab; cout << endl;
	for (double i : d_list_3)cout << i << tab; cout << endl;

#endif
	//	//move semantika?
}