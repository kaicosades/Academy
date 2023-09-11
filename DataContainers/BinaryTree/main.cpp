#include<iostream>
//#include "include\List2.h"
#include <functional>
#include<ctime>>
//#include<winnt.h>

using namespace std;
//#define tab "\t";
//#define DZ;
//#define DEBUG;

class Tree
{
protected: // для чего???
	class Element
	{
		int Data;
		Element* pLeft;
		Element* pRight;
	public:
		Element(int Data, Element* pLeft = nullptr, Element* pRight = nullptr)
			:Data(Data), pLeft(pLeft), pRight(pRight)
		{
#ifdef DEBUG
			cout << "EConstructor:\t" << this << endl;
#endif 


		}

		~Element()
		{
#ifdef DEBUG
			cout << "EDestructor:\t" << this << endl;
#endif 


		}
		friend class Tree;
		friend class UniqueTree;
	}*Root;

public:
	Element* getRoot()
	{
		return Root;
	}

	Tree() :Root(nullptr)
	{
#ifdef DEBUG
		cout << "TConstructor:\t" << this << endl;
#endif 


	}

	Tree(const std::initializer_list<int>& il) : Tree()
	{
		for (int i : il)insert(i, Root);
	}

	~Tree()
	{
		Clear(Root);
#ifdef DEBUG
		cout << "TDestructor:\t" << this << endl;
#endif 


	}
	void print()const
	{
		print(Root);
		cout << endl;
	}

	void depth_print(int depth)const
	{
		depth_print(Root, depth, 28);

	}

	void insert(int Data)
	{
		insert(Data, Root);
		cout << endl;
	}
	
	void balace()
	{
		balance(Root);
	}

	void tree_print()const
	{
		tree_print(Root, 32);
	}

	void erase(int Data)
	{
		erase(Data, Root);
	}

	int Sum()const
	{
		return Sum(Root);
	}

	int Count()const
	{
		return Count(Root);
	}
	int Depth()const
	{
		return Depth(Root);
	}

	int minValue()const
	{
		return minValue(Root);
	}

	int maxValue()const
	{
		return maxValue(Root);
	}

	double Avg()const
	{
		return (double)Sum(Root) / Count(Root);
	}

#ifdef DZ
	using Callback = std::function<int(void)>;
	void measure(Callback function)//сделать перегрузку
	{
		clock_t start = clock();
		clock_t end = clock();
		start = clock();
		int depth = function();
	end = clock();
		cout << depth << ", вычислино за " << double(end - start) / CLOCKS_PER_SEC << " секунд\n";
	}
#endif
private:
	void insert(int Data, Element* Root)//Element* Root - адресс элемента, на котором останавливается функция
	{
		if (this->Root == nullptr)this->Root = new Element(Data);
		if (Root == nullptr)return;
		if (Data < Root->Data)
		{
			if (Root->pLeft == nullptr)Root->pLeft = new Element(Data);
			else insert(Data, Root->pLeft);
		}
		else
		{
			if (Root->pRight == nullptr)Root->pRight = new Element(Data);
			else insert(Data, Root->pRight);
		}
	}

	void erase(int Data, Element*& Root)
	{
		if (Root == nullptr)return;
		erase(Data, Root->pLeft);
		erase(Data, Root->pRight);
		if (Data == Root->Data)
		{
			if (Root->pLeft == Root->pRight)//условие может быть только в одном случае
			{
				delete Root;
				Root = nullptr;//зануление указателя
			}
			else
			{
				if (Count(Root->pLeft) > Count(Root->pRight))
				{
					Root->Data = maxValue(Root->pLeft);
					erase(maxValue(Root->pLeft), Root->pLeft);
				}
				else
				{
					Root->Data = minValue(Root->pRight);
					erase(minValue(Root->pRight), Root->pRight);
				}
			}
		}
	}

#ifdef DZ
	void balance(Element*& Root)
	{
		if (Root == nullptr)return;
		const int n = Count();
		int arr[n];// = 0;
		balance(Root->pLeft);
		for (int i; i < n; i++)
		{
			arr[i] = Root->Data;
		}
		balance(Root->pRight);
		double half = 2;
		int i = 0;
		int m = 4;
			//int half = 2;
			for (i = 0; n/half>i; i++)
			{
					int save = arr[i];
					arr[0] = arr[n / half + 1];
					arr[n / half + 1] = save;
					half *= 2;
			}
			half = 1.5;
			for(int j=i; j<n/2; j++)
			{
				int save = arr[j];
				arr[j] = arr[n/2 * half + 1];
				arr[n /2* half + 1] = save;
				half = half + 1/m;
				m * 2;
			}
	}
#endif

	

	void depth_print(Element* Root, int depth, int width)const// int adjusted_depth, int current_depth=0)const
	{
		//adjusted_depth заданная глубина
		if (Root == nullptr)
		{
			if (depth == 1)cout.width(width * 4);
			if (depth == 0)cout.width(width * 2);
			cout << "";
			return;
		}//||current_depth>adjusted_depth)return;//ctrl r r изменить название во всем коде
		if (depth == 0)
		{
			cout.width(width);
			cout << Root->Data;
			cout.width(width);
			cout << "";
		}
		depth_print(Root->pLeft, depth-1, width);
		
		depth_print(Root->pRight, depth - 1, width );
		
	}

	void tree_print(Element* Root,  int width, int depth = 0)const
	{
	
		if (depth > this->Depth()||Root==nullptr)return;
		depth_print(Root, depth, width);
		cout << endl;
		cout << endl;
		cout << endl;
		tree_print(Root, width / 2, depth+1);

	}

	void balance(Element* Root)
	{
		if (Root == nullptr)return;
		if (abs(Count(Root->pLeft) - Count(Root->pRight))<2)return;
		if (Count(Root->pLeft) < Count(Root->pRight))
		{
			if (Root->pLeft)insert(Root->Data, Root->pLeft);
			else Root->pLeft = new Element(Root->Data);
			Root->Data = minValue(Root->pRight);
			erase(minValue(Root->pRight), Root->pRight);
		}
		else
		{
			if (Root->pRight)insert(Root->Data, Root->pRight);
			else Root->pRight = new Element(Root->Data);
			Root->Data = maxValue(Root->pLeft);
			erase(maxValue(Root->pLeft), Root->pLeft);
		}
		balance(Root->pLeft);
		balance(Root->pRight);
		balance(Root);
	}


	void Clear()
	{
		Clear(Root);
		Root = nullptr;
	}

	int Depth(Element* Root)const
	{
		if (Root == nullptr)return 0;
		int l_depth = Depth(Root->pLeft) + 1;
		int r_depth = Depth(Root->pRight) + 1;
		return l_depth > r_depth ? l_depth : r_depth;

	}



	void print(Element* Root)const
	{
		if (Root == nullptr)return;
		print(Root->pLeft);
		cout << Root->Data << "\t";
		print(Root->pRight);
	}

#ifdef DZ

	void insert_2(int Data)
	{
		if (Root == nullptr)
		{
			this->Root = new Element(Data);
			return;
		}
		Element* Temp = Root;
		while (Temp)
		{
			if (Data < Temp->Data)
			{
				if (Temp->pLeft == nullptr)
				{
					Temp->pLeft = new Element(Data);
					return;
				}
				Temp = Temp->pLeft;

			}
			else
			{
				if (Temp->pRight == nullptr)
				{
					Temp->pRight = new Element(Data);
					return;
				}
				Temp = Temp->pRight;
			}
		}
	}


	void print_2()
	{
		if (Root == nullptr)return;
		Element* Temp = Root;
		Element* Max = Root;
		Element* New = Root;
		int i = 0;
		int j = 0;
		int fff;
		while (Max->pRight)
		{
			Max = Max->pRight;
			j++;
		}


		while (Temp->pLeft)
		{
			//	if (Temp->pLeft == nullptr)cout << Temp->Data;
			Temp = Temp->pLeft;
			i++;

		}
		//i--;
		Temp = Root;

		while (Temp->Data != Max->Data)
		{

			for (i; i; i--)
			{
				int m = i;
				while (m)
				{
					Temp = Temp->pLeft;
					if (m == 1)
					{
						cout << Temp->Data << "\t";

						if (Temp->pRight != nullptr)
						{
							Temp->pRight;
							m++;
						}
						else
							Temp = Root;
					}
					m--;
				}
			}
			int n = 0; ?
				cout << Root->Data << "\t";
			for (? ; ? ; ? )j j j-- n n n
			{
				while (Temp->pLeft != nullptr)
				{
					if (Temp = Root || Temp->pLeft == nullptr)
					{
						if (Temp->pRight != nullptr)
							Temp = Temp->pRight;
						else
						{
							n--;
							? = n;
							//while (n)//условная переменная
							//	Temp = Temp->pRight;
							Temp = Root;

						}
					}
					else
						Temp = Temp->pLeft;
					if (Temp->pLeft == nullptr)
					{
						cout << Temp->Data "\t";
						/*if (Temp->pRight != nullptr)
							Temp = Temp->pRight;*/
					}

					/*else
					{
						n++;
						Temp->pLeft;
					}*/
					n++;
				}
			}
		}
	}
#endif




	int minValue(Element* Root)const
	{
		if (Root == nullptr)return 0;
		return Root->pLeft == nullptr ? Root->Data : minValue(Root->pLeft);
		/*if (Root->pLeft == nullptr)return Root->Data;
		else return minValue(Root->pLeft);*/

	}

	int maxValue(Element* Root)const
	{
		if (Root == nullptr)return 0;
		return Root->pRight == nullptr ? Root->Data : maxValue(Root->pRight);
		/*	if (Root->pRight == nullptr)return Root->Data;
			else return maxValue(Root->pRight);*/
	}

	void Clear(Element* Root)
	{
		if (Root == nullptr)return;
		Clear(Root->pLeft);
		Clear(Root->pRight);
		delete Root;
	}

	int Sum(Element* Root)const
	{
		/*if (Root == nullptr)return 0;
		else return Sum(Root->pLeft) + Sum(Root->pRight) + Root->Data;*/
		return Root == nullptr ? 0 : Sum(Root->pLeft) + Sum(Root->pRight) + Root->Data;
	}
	int Count(Element* Root)const
	{
		return Root == nullptr ? 0 : Count(Root->pLeft) + Count(Root->pRight) + 1;
	}

};

class UniqueTree :public Tree
{
	void insert(int Data, Element* Root)
	{
		if (this->Root == nullptr)this->Root = new Element(Data);
		if (Root == nullptr)return;
		if (Data < Root->Data)
		{
			if (Root->pLeft == nullptr)Root->pLeft = new Element(Data);
			else insert(Data, Root->pLeft);
		}
		else if (Data > Root->Data)
		{
			if (Root->pRight == nullptr)Root->pRight = new Element(Data);
			else insert(Data, Root->pRight);
		}
	}

public:


	void insert(int Data)
	{
		insert(Data, Root);

	}


};

template<typename T>void measure(const char* message, const Tree& tree, T(Tree::* member_function)()const)
{
	cout << message;
	clock_t start = clock();
	T value =(tree.*member_function)();
	clock_t end = clock();
	cout << value << " выполнено зa: " << double(end - start) / CLOCKS_PER_SEC << " секунд.\n";
}

//#define Tree_1
//#define UTree
//#define BASE_CHECK
//#define DEPTH_CHECK
//#define TEME_CHECK
//#define MEASURE_CHECK

void main()
{
	setlocale(LC_ALL, "");
#ifdef BASE_CHECK



#ifdef Tree_1
	Tree tree;
	int n;
	cout << "Введите размер дерева: "; cin >> n;
	for (int i = 0; i < n; i++)
	{
		//tree.insert(rand() % 100, tree.getRoot());
		tree.insert_2(rand() % 100);
	}
	//tree.print(tree.getRoot());
	tree.print_2();
	cout << "Минимальное значение в дереве: " << tree.minValue(tree.getRoot()) << endl;
	cout << "Максимальне значение в дереве: " << tree.maxValue(tree.getRoot()) << endl;
	cout << "Сумма элементов дерева:\t\t " << tree.Sum(tree.getRoot()) << endl;
	cout << "Количество элементов дерева: " << tree.Count(tree.getRoot()) << endl;
	cout << "Среднее арифмитическое элементов дерева: " << tree.Avg() << endl;
#endif
#ifdef UTree
	UniqueTree tree_2;
	int n;
	cout << "Введите размер дерева: "; cin >> n;
	for (int i = 0; i < n; i++)
	{
		tree_2.insert(rand() % 100, tree_2.getRoot());
	}
	tree_2.print(tree_2.getRoot());
	cout << "Минимальное значение в дереве: " << tree_2.minValue(tree_2.getRoot()) << endl;
	cout << "Максимальне значение в дереве: " << tree_2.maxValue(tree_2.getRoot()) << endl;
	cout << "Сумма элементов дерева:\t\t " << tree_2.Sum(tree_2.getRoot()) << endl;
	cout << "Количество элементов дерева: " << tree_2.Count(tree_2.getRoot()) << endl;
	cout << "Среднее арифмитическое элементов дерева: " << tree_2.Avg() << endl;
#endif
	Tree tree;
	int n;
	cout << "Введите размер дерева: "; cin >> n;
	for (int i = 0; i < n; i++)
	{
		tree.insert(rand() % 100);

	}
	tree.print();
	cout << "Минимальное значение в дереве: " << tree.minValue() << endl;
	cout << "Максимальне значение в дереве: " << tree.maxValue() << endl;
	cout << "Сумма элементов дерева:\t\t " << tree.Sum() << endl;
	cout << "Количество элементов дерева: " << tree.Count() << endl;
	cout << "Среднее арифмитическое элементов дерева: " << tree.Avg() << endl;

#endif // BASE_CHECK

#ifdef DEPTH_CHECK
	Tree tree = { 50, 25, 75, 16,32,64,90, 28 , 29 };
	tree.print();
	cout << "Глубина дерева: " << tree.Depth() << endl;
	//int value;
	//cout << "Введите удаляемое значение: "; cin >> value;
	//tree.erase(value);
	tree.print();

	int depth;
//	cout << "Введите глубину дерева: "; cin >> depth;
	//tree.depth_print(depth);
	tree.tree_print();
#endif

#ifdef TIME_CHECK
	Tree tree;
	clock_t start = clock();
	int n;
	cout << "Введите размер дерева: "; cin >> n;
	for (int i = 0; i < n; i++)
	{
		tree.insert(rand() % 100);
	}
	clock_t end = clock();
	cout << "Дерево заполнено за " << double(end - start) / CLOCKS_PER_SEC << " секунд\n";
	//tree.print();
	cout << "Минимальное значение в дереве: ";
	start = clock();
	int min = tree.minValue();
	end = clock();
	cout << min << ", вычислино за " << double(end - start) / CLOCKS_PER_SEC << " секунд\n";//<< tree.minValue() << endl;


	cout << "Максимальне значение в дереве: ";
	start = clock();
	int max = tree.maxValue();
	end = clock();
	cout << max << ", вычислино за " << double(end - start) / CLOCKS_PER_SEC << " секунд\n";// << tree.maxValue() << endl;


	cout << "Сумма элементов дерева:\t\t ";
	start = clock();
	int sum = tree.Sum();
	end = clock();
	cout << sum << ", вычислино за " << double(end - start) / CLOCKS_PER_SEC << " секунд\n";// << tree.Sum() << endl;


	cout << "Количество элементов дерева: ";
	start = clock();
	int count = tree.Count();
	end = clock();
	cout << count << ", вычислино за " << double(end - start) / CLOCKS_PER_SEC << " секунд\n";//<< tree.Count() << endl;


	cout << "Среднее арифмитическое элементов дерева: ";
	start = clock();
	int avg = tree.Avg();
	end = clock();
	cout << avg << ", вычислино за " << double(end - start) / CLOCKS_PER_SEC << " секунд\n";//<< tree.Avg() << endl;


	cout << "Глубина дерева: ";
	start = clock();
	int depth = tree.Depth();
	end = clock();
	cout << depth << ", вычислино за " << double(end - start) / CLOCKS_PER_SEC << " секунд\n";//<< tree.Depth() << endl;

	//int (*Lala)() = &Depth;
	cout << "Глубина дерева: "; //<< tree.measure(Depth);
	tree.measure([&tree]() -> int {return tree.Depth(); }); //f12 не указывает на функци.
#endif
	
#ifdef MEASURE_CHECK
	UniqueTree tree;
	clock_t start = clock();
	int n;
	cout << "Введите размер дерева: "; cin >> n;
	for (int i = 0; i < n; i++)
	{
		tree.insert(rand() % 1000000);
	}
	measure("Минимальное значение в дереве: ", tree, &Tree::minValue);
	measure("Максимальное значение в дереве: ", tree, &Tree::maxValue);
	measure("Сумма элементов дерева: ", tree, &Tree::Sum);
	measure("Количество элементов дерева: ", tree, &Tree::Count);
	measure("Среднее-арифмитическое элементов дерева: ", tree, &Tree::Avg);
	measure("Глубина дерева: ", tree, &Tree::Depth);
#endif

	Tree tree = { 3,5,8,13,21,34,55,89 };
	tree.tree_print();
	tree.balace();
	tree.tree_print();
}