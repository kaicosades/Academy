#include <iostream>
using namespace std;
using std::cout;
using std::cin;
using std::endl;
#define tab "\t"

#define delimeter "\n---------------------------------------------------------\n"


class Element
{
	int Data; 
	Element* pNext; 
	Element* pPrev; 
public:
	Element(int Data, Element* pNext = nullptr, Element* pPrev = nullptr) :Data(Data), pNext(pNext), pPrev(pPrev)
	{
		cout << "EConstructor:\t" << this << endl;
	}

	Element(int Data) 
	{
		this->Data = Data;
		this->pPrev = this->pNext = nullptr;
	}

	~Element()
	{
		cout << "EDestructor:\t" << this << endl;
	}

	friend class LinkedList;

};

class LinkedList
{
	Element* Head; 
	Element* Tail; 
public:


	LinkedList()
	{
		Head = Tail = nullptr;
		//Tail = nullptr; 
		//push_front(1);
		cout << "LConstructor:\t" << this << endl;
	}



	~LinkedList()
	{
		//while (Head)pop_front();
		cout << "LDestructor:\t" << this << endl;
	}


	void push_front(int Data)
	{
		Element* Temp = new Element(Data, Head , Tail);
		//Temp -> pNext = Head;
		if (Head != nullptr) Head->pPrev = Temp;
		if (Tail == nullptr) Tail = Temp;
		Head = Temp;
	}
	void push_back(int Data)
	{
		Element* Temp = new Element(Data, Head, Tail);
		//Temp->pPrev = Tail;
		if (Tail != nullptr) Tail->pNext = Temp;
		if (Head == nullptr) Head = Temp;
		Tail = Temp;
	}



	void pop_front()
	{
		Element* erased = Head;
		Head = Head->pNext;
		delete erased;
	}

	void pop_back()
	{
		Element* erased = Tail;
		Tail = Tail->pPrev;
		delete erased;
	}

	void insert(int Index, int Data, int n)
	{
		if (Index <= 0)return push_front(Data);
		if (Index >= n)return push_back(Data);
		if (Index < n / 2)
		{
			Element* Temp = Head;
			for (int i = 0; i < Index - 1; i++)
				Temp = Temp->pNext;
			Element* New = new Element(Data, Head, Tail);
			New->pNext = Temp->pNext;
			Temp->pNext = New;
		}
		else
		{
			Element* Temp = Tail;
			for (int i = 0; i < n - Index; i++)
				Temp = Temp->pPrev;
			Element* New = new Element(Data, Head, Tail);
			New->pNext = Temp->pNext;
			Temp->pNext = New;
		}
	}

	void erase(int Index, int n)
	{
		if (Index <= 0)return pop_front();
		if (Index >= n)return pop_back();
		if (Index < n / 2)
		{
			Element* Temp = Head;
			for (int i = 0; i < Index - 1; i++)
				Temp = Temp->pNext;
			Element* erased = Temp->pNext;
			Temp->pNext = Temp->pNext->pNext;
			delete erased;
		}
		else
		{
			Element* Temp = Tail;
			for (int i = 0; i < n - Index; i++)
				Temp = Temp->pPrev;
			Element* erased = Temp->pNext;
			Temp->pNext = Temp->pNext->pNext;
			delete erased;
		}
	}




	void print()const
	{
		cout << "Head: " << Head << endl;
		Element* Temp = Head;
		for (Temp; Temp != Tail; Temp = Temp->pNext)//Tail->pNext  почему указывает на Head???
			cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
		cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
	}




};


void main()
{
	setlocale(LC_ALL, "");

	int n;
	cout << "Введите размер списка: "; cin >> n;
	LinkedList list;
	for (int i = 0; i < n; i++)
	{
		
		list.push_front(rand() % 100);
	}
	
	//list.push_back(rand() % 100);
	//list.pop_front();
	//list.pop_back();

	list.insert(11, 99, n);
	list.erase(11, n);
	list.print();
}