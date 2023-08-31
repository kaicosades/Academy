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
		friend class List; //ѕечень и человек
	}*Head, *Tail;//¬писываем создаваемые объекты
	unsigned int size;
	class ConstBaseIterator
	{
	protected: //дл€ наследовани€
		Element* Temp;
	public:
		ConstBaseIterator(Element* Temp);
		~ConstBaseIterator();

		bool operator==(const ConstBaseIterator& other)const;
		bool operator!=(const ConstBaseIterator& other)const;
		const T& operator*() const;

	};
public:
	class ConstIterator:public ConstBaseIterator
	{
	public:
		ConstIterator(Element* Temp = nullptr);
		~ConstIterator();

		ConstIterator& operator++();
		ConstIterator operator++(int);
		ConstIterator& operator--();
		ConstIterator operator--(int);
	};

	class ConstReverseIterator:public ConstBaseIterator//паблик в данном случае это наследование
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
	ConstIterator cbegin()const;// если справа написано const, то слева дописываетс€ тоже
	ConstIterator cend()const;
	ConstReverseIterator crbegin()const;
	ConstReverseIterator crend()const;
	Iterator begin();
	Iterator end();
	ReverseIterator rbegin();
	ReverseIterator rend();
	List();
	List(const std::initializer_list<T>& il); //»справление ошибки с {}
	List(const List<T>& other);//конструктор копировани€
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


/////////////////////////////////////////////////////////////////////////////////////////////
///                     Element   methods   

template<typename T>List<T>::Element::Element(T Data, Element* pNext , Element* pPrev ) : Data(Data), pNext(pNext), pPrev(pPrev)
{
	cout << "EConstructor:\t" << this << endl;
}

template<typename T>List<T>::Element::~Element()
{
	cout << "EDestructor:\t" << this << endl;
}




/////////////////////////////////////////////////////////////////////////////////////////////
///                      ConstBaseIterator   methods   

template<typename T>List<T>::ConstBaseIterator::ConstBaseIterator(Element* Temp) :Temp(Temp)
{
	cout << "BItConstructor:\t" << this << endl;
}
template<typename T>List<T>::ConstBaseIterator::~ConstBaseIterator()
{
	cout << "BItDestructor:\t" << this << endl;
}

template<typename T>bool List<T>::ConstBaseIterator::operator==(const ConstBaseIterator& other)const
{
	return this->Temp == other.Temp;
}
template<typename T>bool List<T>::ConstBaseIterator::operator!=(const ConstBaseIterator& other)const
{
	return this->Temp != other.Temp;
}
template<typename T>const T& List<T>::ConstBaseIterator::operator*() const
{
	return Temp->Data;
}





/////////////////////////////////////////////////////////////////////////////////////////////
///                          iterator   methods   


template<typename T>List<T>::ConstIterator::ConstIterator(Element* Temp) : ConstBaseIterator(Temp)
{
	cout << "ItConstructor:\t" << this << endl;
}
template<typename T>List<T>::ConstIterator::~ConstIterator()
{
	cout << "ItDestrictor:\t" << this << endl;
}

template<typename T>typename List<T>::ConstIterator& List<T>::ConstIterator::operator++()
{
	ConstBaseIterator::Temp = ConstBaseIterator::Temp->pNext;
	return *this;
}
template<typename T>typename List<T>::ConstIterator List<T>::ConstIterator::operator++(int)
{
	ConstIterator old = *this;
	ConstBaseIterator::Temp = ConstBaseIterator::Temp->pNext;
	return old;
}
template<typename T>typename List<T>::ConstIterator& List<T>::ConstIterator::operator--()
{
	ConstBaseIterator::Temp = ConstBaseIterator::Temp->pPrev;
	return *this;
}
template<typename T>typename List<T>::ConstIterator List<T>::ConstIterator::operator--(int)
{
	ConstIterator old = *this;
	ConstBaseIterator::Temp = ConstBaseIterator::Temp->pPrev;
	return old;
}



template<typename T>T& List<T>::Iterator::operator*()
{
	return ConstBaseIterator::Temp->Data;
}







/////////////////////////////////////////////////////////////////////////////////////////////
///                          ReverseIterator   methods   


template<typename T>List<T>::ConstReverseIterator::ConstReverseIterator(Element* Temp) :ConstBaseIterator(Temp)
{
	cout << "RItConstructor:\t" << this << endl;
}
template<typename T>List<T>::ConstReverseIterator::~ConstReverseIterator()
{
	cout << "RItDestructor:\t" << this << endl;
}
template<typename T>typename List<T>::ConstReverseIterator& List<T>::ConstReverseIterator::operator++()
{
	ConstBaseIterator::Temp = ConstBaseIterator::Temp->pPrev;
	return *this;
}
template<typename T>typename List<T>::ConstReverseIterator List<T>::ConstReverseIterator::operator++(int)
{
	ConstReverseIterator old = *this;
	ConstBaseIterator::Temp = ConstBaseIterator::Temp->pPrev;
	return old;
}
template<typename T>typename List<T>::ConstReverseIterator& List<T>::ConstReverseIterator::operator--()
{
	ConstBaseIterator::Temp = ConstBaseIterator::Temp->pNext;
	return *this;
}
template<typename T>typename List<T>::ConstReverseIterator& List<T>::ConstReverseIterator::operator--(int)
{
	ConstReverseIterator old = *this;
	ConstBaseIterator::Temp = ConstBaseIterator::Temp->pNext;
	return old;
}



template<typename T>T& List<T>::ReverseIterator::operator*()
{
	return ConstBaseIterator::Temp->Data;
}



/////////////////////////////////////////////////////////////////////////////////////////////
///                          List   methods   



template<typename T>typename List<T>::ConstIterator List<T>::cbegin()const//дописываетс€ typename т к это им€ типа// если справа написано const, то слева дописываетс€ тоже
{
	return Head;
}

template<typename T>typename List<T>::ConstIterator List<T>::cend()const
{
	return nullptr;
}

template<typename T>typename List<T>::ConstReverseIterator List<T>::crbegin()const
{
	return Tail;
}
template<typename T>typename List<T>::ConstReverseIterator List<T>::crend()const
{
	return nullptr;
}
template<typename T>typename List<T>::Iterator List<T>::begin()
{
	return Head;
}
template<typename T>typename List<T>::Iterator List<T> ::end()
{
	return nullptr;
}

template<typename T>typename List<T>::ReverseIterator List<T>::rbegin()
{
	return Tail;
}

template<typename T>typename List<T>::ReverseIterator List<T>::rend()
{
	return nullptr;
}

template<typename T> List<T>::List()// это конструктор, а не им€ функции
{
	Head = Tail = nullptr;
	cout << "LConstructor:\t" << this << endl;
}
template<typename T> List<T>::List(const std::initializer_list<T>& il) :List() //»справление ошибки с {}// это строчка - конструктор с одним параметром
{
	for (T const* it = il.begin(); it != il.end(); ++it)
	{
		push_back(*it);
	}
}

template<typename T> List<T>::List(const List<T>& other) :List() //конструктор копировани€
{
	*this = other;
}

//	Operators:

template<typename T> List<T>& List<T>::operator =(const List<T>& other) // объ€влен в глобальном пространстве? оператор - ключевое слово
{
	if (this == &other)return *this;
	while (Head)pop_front();
	for (Element* Temp = other.Head; Temp; Temp = Temp->pNext)push_back(Temp->Data);
	cout << "LCopyAssignment:\t" << this << endl;
	return *this;

}


template<typename T> List<T>::~List()
{
	//while (Head)pop_front();//дл€ того, чтобы проверить функцию
	while (Tail)pop_back();//дл€ того, чтобы проверить функцию
	cout << "LDestructor:\t" << this << endl;
}






template<typename T>void List<T>::push_front(T Data)
{
	if (Head == nullptr && Tail == nullptr)Head = Tail = new Element(Data);
	else Head = Head->pPrev = new Element(Data, Head); // Head как то св€зано с самим Head. pNext 
	size++;
}

template<typename T>void List<T>::push_back(T Data)
{
	if (Head == nullptr && Tail == nullptr)Head = Tail = new Element(Data);
	else Tail = Tail->pNext = new Element(Data, nullptr, Tail); // Tail как то св€зано с самим Tail. pNext 
	size++;
}

template<typename T>void List<T>::insert(T Data, int Index)
{
	if (Index >= size)return push_back(Data);
	if (Index <= 0)return push_front(Data);
	Element* Temp;
	if (Index < size / 2)
	{
		Temp = Head;
		for (int i = 0; i < Index; i++)Temp = Temp->pNext;

	}
	else
	{
		Temp = Tail;
		for (int i = 0; i < size - Index - 1; i++)Temp = Temp->pPrev;
	}
	Temp->pPrev = Temp->pPrev->pNext = new Element(Data, Temp, Temp->pPrev);
	size++;
}

//	Removing elements:
template<typename T>void List<T>::pop_front()
{
	if (Head == nullptr && Tail == nullptr)return;
	if (Head == Tail)
	{
		delete Head;
		Head = Tail = nullptr;
		return;
	}
	Head = Head->pNext;
	delete Head->pPrev;
	Head->pPrev = nullptr; // это признак конца списка, иначе он будет указывать на 0
	size--;
}

template<typename T>void List<T>::pop_back()
{
	if (Head == Tail)return pop_front();
	Tail = Tail->pPrev;
	delete Tail->pNext;
	Tail->pNext = nullptr;
	size--;
}

template<typename T>void List<T>::erace(int Index)
{
	if (Index >= size)return;
	if (Index <= 0)return pop_front();
	Element* Temp;
	if (Index < size / 2)
	{
		Temp = Head;
		for (int i = 0; i < Index; i++)Temp = Temp->pNext;

	}
	else
	{
		Temp = Tail;
		for (int i = 0; i < size - Index - 1; i++)Temp = Temp->pPrev;
	}

	Temp->pPrev->pNext = Temp->pNext;
	Temp->pNext->pPrev = Temp->pPrev;
	delete Temp;
	size--;
}

//	Methods:

template<typename T>void List<T>::print()const
{
	for (Element* Temp = Head; Temp; Temp = Temp->pNext)
		cout << Temp->pPrev << tab << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
}

template<typename T>void List<T>::reverse_print()const
{
	for (Element* Temp = Tail; Temp; Temp = Temp->pPrev)
		cout << Temp->pNext << tab << Temp << tab << Temp->Data << tab << Temp->pPrev << endl;
}



template<typename T>List<T> operator+(const List<T>& left, const List<T>& right)
{
	List<T> cat = left;
	for (typename List<T>::ConstIterator it = right.cbegin(); it != right.cend(); ++it)
		cat.push_back(*it);
	return cat;
}

///				List methods
//////////////////////////////////////////////////////////////

//#define BASE_CHECK

void main()
{
	setlocale(LC_ALL, "");
#ifdef BASE_CHECK
	int n;
	cout << "¬ведите размер списка: "; cin >> n;
	List list;
	for (int i = 0; i < n; i++)
	{
		//list.push_front(rand() % 100);
		list.push_back(rand() % 100);
	}
	list.print();
	cout << delimiter << endl;
	list.reverse_print();
	int index;
	int value;
	cout << "¬ведите индекс добавл€емого элемента: "; cin >> index;
	cout << "¬ведите значение добавл€емого элемента: "; cin >> value;
	list.insert(value, index);
	list.print();
	cout << delimiter << endl;
	list.reverse_print();
#endif

	List<int> list1 = { 3,5,8,13,21 };
	//list.print();
	for(int i : list1)cout <<i<< tab; cout<< endl;// не работает список, потому что нет итератора
	/*for (List::ReverseIterator it = list.rbegin(); it != list.rend(); it++)
	{
		cout << *it << tab;
	}
	cout << endl;*/

	for (List<int>::Iterator it = list1.begin(); it != list1.end(); ++it)
	{
		(*it) *= 10;
	}

	List<int> list2 = { 34, 55, 89 };
	for (int i : list2)cout << i << tab; cout << endl;
	List<int> list3 = list1 + list2;
	for (int i : list3)cout << i << tab; cout << endl;

	List<double> d_list_1 = { 2.7, 3.14, 5.1 };
	List<double> d_list_2 = { 7.5, 8.2, 4.4, 9.5 };
	List<double> d_list_3 = d_list_1 + d_list_2;
	for (double i : d_list_1)cout << i << tab; cout << endl;
	for (double i : d_list_2)cout << i << tab; cout << endl;
	for (double i : d_list_3)cout << i << tab; cout << endl;




}