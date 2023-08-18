#include <iostream>
//using namespace std;
using std::cout;
using std::cin;
using std::endl;
#define tab "\t"
//#define DZ

class ForwardList;
ForwardList operator+(const ForwardList& left, const ForwardList& right);

class Element
{
	int Data; //�������� ��������
	Element* pNext; //������ ���������� ��������
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
	friend ForwardList operator+(const ForwardList& left, const ForwardList& right);
	friend class Iterator;
};

class Iterator // ����� ������ �� ������ ������ �� �� �� 16.08.2023
{
	Element* Temp;
public:
	Iterator(Element* Temp = nullptr) :Temp(Temp)
	{
		cout << "ItConstructor:\t" << this << endl;
	}
	~Iterator()
	{
		cout << "ItDestructor:\t" << this << endl;
	}

	Iterator& operator++()
	{
		Temp = Temp->pNext;
		return *this; //this ��� Iterator
	}

	bool operator==(const Iterator& other)const
	{
		return this->Temp == other.Temp;
	}
	bool operator!=(const Iterator& other)const
	{
		return this->Temp != other.Temp;
	}

	int operator*() // ����� �������� ������ �� ������, ��� ����� ������������ � ������� *. ������� ���������� ������
	{
		return Temp->Data;
	}
};

class ForwardList
{
	Element* Head; // ������ ������ - �������� ����� ���������� �������� ������
public:

	Iterator begin() //���������� ��������
	{
		return Head;
	}
	Iterator end()
	{
		return nullptr;
	}

	ForwardList()
	{
		Head = nullptr; //���� ������ ����, �� ��� ������ ��������� �� 0
		//push_front(1);
		cout << "LConstructor:\t" << this << endl;
	}

	ForwardList(const std::initializer_list<int>& il):ForwardList() // ������ ��� �����. ���� �����, ����� �������� �������� �������, ������� ������ �������� �����������.
	{
		for (int const* it = il.begin(); it != il.end(); it++)
		{
			push_back(*it);
		}
		cout << typeid(il.begin()).name() << endl;
	}


	//ForwardList(int a, int aa, int aaa, int aaaa, int aaaaa)//(int arr[])
	//{
	//	int arr[4];
	//	/*arr[0] = a;
	//	arr[1] = aa;
	//	arr[2] = aaa;
	//	arr[3] = aaaa;
	//	arr[4] = aaaaa;*/

	//	int i = 0;
	//	for (int i = 0, a; a; a++, i++)
	//	{
	//		push_front(a);	
	//	}

	//	return a;//arr[];
	//}



	/*ForwardList()
	{
		Head = nullptr;
		int arr[] = 
		return arr[]
	}*/



	ForwardList(const ForwardList& other):ForwardList()
	{
		cout << "LCopyConstructor:\t" << this << endl;
		//Deep copy:

		/*for (Element* Temp = other.Head; Temp; Temp = Temp->pNext)
			push_back(Temp->Data);*/

		*this = other;//���� ������= ��� ������//this - ��������� �� ������ ��� �������� ���������� �����
		//����� �������� �������� �� ������, ������ - *, � � �������������� ���������.
	}


	~ForwardList()
	{
		while (Head)pop_front();
		cout << "LDestructor:\t" << this << endl;
	}

	//							Operators:

	 ForwardList& operator=(const ForwardList& other)
	{
		if (this == &other)return *this;
		while (Head)pop_front();
		cout << "LCopyAssigment:\t" << this << endl;
		for (Element* Temp = other.Head; Temp; Temp = Temp->pNext)
			push_back(Temp->Data);
		return *this;
	}

	//                           Adding elements:

	void push_front(int Data)
	{
		Head = new Element(Data, Head); //new?

	}
	void push_back(int Data)
	{
		if (Head == nullptr)return push_front(Data);
		Element* Temp = Head;
		while (Temp->pNext)Temp = Temp->pNext;
		Temp->pNext = new Element(Data); // ��������� �� ����� �������, "���� ����� ���-�� ���������"
	}

	// Methods:

	void print()const
	{
		//Element* Temp = Head; //Temp - ��� ��������
		//// �������� - ���������, ��� ������ �������� ����� �������� ������ � ��������� ��������� ������
		//while (Temp)
		//{
		//	cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
		//	Temp = Temp->pNext;
		//}

		cout << "Head: " << Head << endl;
		for (Element* Temp = Head; Temp; Temp = Temp->pNext)
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
		delete New;		//�� ������, ��� ���� ���������
		
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
		Element* erased = Head;
		Head = Head->pNext;
		delete erased;
	}

	void pop_back()
	{
		Element* Temp = Head;
		while (Temp->pNext->pNext)Temp = Temp -> pNext;
		delete Temp->pNext;
		Temp->pNext = nullptr; // nullptr ��� ��������� �� ����
	}

	void insert(int Index, int Data)
	{
		if (Index == 0)return push_front(Data);
		Element* Temp = Head;
		for (int i = 0; i < Index-1; i++)
			if(Temp->pNext)
				Temp = Temp->pNext; // ���� ������ ������ ������, �� ��������� � ����� ������
		Element* New = new Element(Data);
		New->pNext = Temp->pNext;
		Temp->pNext = New;

	}

	void erase(int Index)
	{
		if (Index == 0)return pop_front();
		Element* Temp = Head;
		for (int i = 0; i < Index - 1; i++)
			if (Temp->pNext)
				Temp = Temp->pNext;
		Element* erased = Temp->pNext;
		Temp->pNext = Temp->pNext->pNext;
		delete erased;

	}
	friend ForwardList operator+(const ForwardList& left, const ForwardList& right);



	//char operator[](int i)

};

//#define CHECK_POP_FRONT_AND_BACK
//#define BACE_CHECK
//#define OPERATOR_PLUS_CHECK
//#define RANGE_BASED_FOR_ARRAY

ForwardList operator+(const ForwardList& left, const ForwardList& right)
{
	ForwardList cat = left;
	for (Element* Temp = right.Head; Temp; Temp = Temp->pNext)cat.push_back(Temp->Data);
	return cat;
}

void main()
{
	setlocale(LC_ALL, "");

#ifdef BACE_CHECK
	int n;
	cout << "������� ������ ������: "; cin >> n;
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
	cout << "������� ������ ��������: "; cin >> index;
	cout << "������� �������� ��������: "; cin >> value;
	

	list.insert(index, value);
	list.print();

	cout << "������� ������ ��������: "; cin >> index;
	list.erase(index);
	list.print();*/

//	ForwardList list2 = list;	//����� ����������� deep copy ����� copy constructor(� ���� ������ ������� ������ ��������� ��� �� ��� ������ �����
	ForwardList list2;
	list2 = list;				//����� ���������� ���������
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
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) //sizeof(arr)/sizeof(arr[0]) - ���������� ������ �������
		cout << arr[i] << tab;
	cout << endl;

	for (int i : arr) // �� ����� arr ����� ���� ��� ������, ��� ������ ��������
	{
		cout << i << tab;
	}
	cout << endl;
#endif
	ForwardList list = { 3,5,8,13,21 };
	list.print();

	for (int i : list)
	{
		cout << i << tab;
	}
	cout << endl;


	//	//move semantika?
}