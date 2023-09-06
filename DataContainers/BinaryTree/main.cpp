#include<iostream>
//#include "include\List2.h"
#include <functional>
#include<ctime>>
//#include<winnt.h>

using namespace std;
//#define tab "\t";
//#define PRINT_2;
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

	void insert(int Data)
	{
		insert(Data, Root);
		cout << endl;
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


	void print(Element* Root)const
	{
		if (Root == nullptr)return;
		print(Root->pLeft);
		cout << Root->Data << "\t";
		print(Root->pRight);
	}

#ifdef PRINT_2
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

//#define Tree_1
//#define UTree
//#define BASE_CHECK
//#define DEPTH_CHECK
#define CHECK

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
	Tree tree = { 50, 25, 75, 16,32,64,90, 28 , 100, 1001 };
	tree.print();
	cout << "Глубина дерева: " << tree.Depth() << endl;
#endif

#ifdef CHECK
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
}