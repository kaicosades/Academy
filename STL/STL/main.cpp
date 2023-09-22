#include<iostream>
#include<array>
#include<vector>
//using namespace std;

using std::cin;
using std::cout;
using std::endl;

#define tab "\t"
#define delimeter "\n---------------------------------------------------------------\n"

//#define STL_ARRAY
#define STL_VECTOR

template<typename T>void vector_properties(const std::vector<T>& vec);

void main()
{
	setlocale(LC_ALL, "");

#ifdef STL_ARRAY
	const int N = 5;
	std::array<int, N> arr = { 3 ,5 ,8 ,13, 21 };
	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << tab;
	}
#endif

#ifdef STL_VECTOR
	std::vector<int> vec = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34 };
	try
	{
		for (int i = 0; i < vec.size()*2; i++)
		{
			cout << vec.at(i) << tab;//<< vec[i] << tab;//оператор это функция. При превышении значеня не бросает исключения []
		}
	}
	
	catch (const std::exception& e)
	{
		std::cerr << e.what()<< endl;
	}

	cout <<endl;
	vector_properties(vec);
	vec.push_back(55);
	vector_properties(vec);
	vec.resize(8);
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec.at(i) << tab;

	}

	cout << endl;
	int index;
	int value;

	cout << "Введите индекс добавляемого элемента: "; cin >> index;
	cout << "Введите значение добавляемого элемента: "; cin >> value;

	vec.insert(vec.begin() + index, value);
	for (std::vector<int>::iterator it = vec.begin(); it < vec.end(); ++it)
	{
		cout << *it << tab;
	}
	cout << endl;

	for (std::vector<int>::reverse_iterator it = vec.rbegin(); it != vec.rend(); ++it)
	{
		cout << *it << tab;
	}
	cout << endl;

	for (int i : vec)cout << i << tab; cout << endl;
	//iterator insert(index, const int& value)
	//std::vector<int> ::iterator it;
	//it = vector.begin();
	//it = vector.insert(it, value)

	//std::vector<int> vec2(100);
	//vector_properties(vec2);
	//vec2.push_back(1024);
	//vector_properties(vec2);
	//cout << delimeter;
	//std::vector<double> d_vec;
	//vector_properties(d_vec);
#endif 





}



template<typename T>void vector_properties(const std::vector<T>& vec)
{
	cout << "Size:\t" << vec.size() << endl;
	cout << "MaxSize:\t" << vec.max_size() << endl;
	cout << "Capacity:\t" << vec.capacity() << endl;
	cout << endl;
}