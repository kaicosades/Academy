#include <iostream>
using namespace std;
#define tab "\t"


class Element
{
	int Data; //значение элемента
	Element* pNext; //адресс следующего элемента
public:
	Element(int Data, Element* pNext = nullptr) :Data(Data), pNext(pNext)
	{
		cout << "EConstructor:\t" << this << endl;
	}

	~Element()
	{
		cout << "EDestructor:\t" << this << endl;
	}
	friend class ForwardList;
};

class ForwardList
{
	Element* Head; // Голова списка - содержит адрес начального элемента списка
public:
	ForwardList()
	{
		Head = nullptr; //Если список пуст, то его голова указывает на 0
		cout << "LConstructor:\t" << this << endl;
	}

	~ForwardList()
	{
		cout << "LDestructor:\t" << this << endl;
	}

	//                             Adding elements:
	void push_front(int Data)
	{
		Head = new Element(Data, Head); //new?

	}
	void push_back(int Data)
	{
		Element* Temp = Head;
		while (Temp->pNext)Temp = Temp->pNext;
		Temp->pNext = new Element(Data); // указатель на новый элемент, "сами файлы где-то болтаются"
	}

	// Methods:

	void print()const
	{
		Element* Temp = Head; //Temp - это итератор
		// итератор - указатель, при помощи которого можно получить доступ к элементам структуры данных
		while (Temp)
		{
			cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
			Temp = Temp->pNext;
		}
	}

	// DZ

	void pop_front()
	{
		Element* Temp = Head;
		Head = Temp->pNext;
		Temp->pNext;
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


};

//#define CHECK_POP_FRONT_AND_BACK


void main()
{
	setlocale(LC_ALL, "");
	int n;
	cout << "Введите размер списка: "; cin >> n;
	ForwardList list;
	for (int i = 0; i < n; i++)
	{
		list.push_front(rand() % 100);
	}

	list.push_back(123);
	list.print();

	//dz
#ifdef CHECK_POP_FRONT_AND_BACK
	list.pop_front();
	list.print();

	list.pop_back();
	list.print();
#endif

	list.erase(5);
	list.print();

	list.insert(7, 99);
	list.print();


}