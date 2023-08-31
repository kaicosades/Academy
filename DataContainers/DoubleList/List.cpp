#include"List.h"


/////////////////////////////////////////////////////////////////////////////////////////////
///                     Element   methods   

template<typename T>List<T>::Element::Element(T Data, Element* pNext, Element* pPrev) : Data(Data), pNext(pNext), pPrev(pPrev)
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