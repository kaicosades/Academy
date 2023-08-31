#include<iostream>
//#include "include\List2.h"

using namespace std;

//void main()
//{
//	setlocale(LC_ALL, "");
//	//int n;
//	List<int> list = { 3, 5, 8, 13, 21};
//	for (int i : list)cout << i << "\t"; cout << endl;
//
//	List<double> d_list = { 3,5,8,13,21 };
//	for (double i : list)cout << i << "\t"; cout << endl;
//
//
//}


class Tree
{
	class Element
	{
		int Data;
		Element* pLeft;
		Element* pRight;
	public:
		Element(int Data, Element* pLeft = nullptr, Element* pRight = nullptr)
			:Data(Data), pLeft(pLeft), pRight(pRight)
		{
			cout << "EConstructor:\t" << this << endl;
		}

		~Element()
		{
			cout << "EDestructor:\t" << this << endl;
		}
	}*Root;
};

void main()
{
	setlocale(LC_ALL, "");
}