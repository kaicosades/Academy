#include<iostream>
#include<map>
#include<list>
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"

const std::map<int, std::string> CRIMES =
{
	{0, "N/A"},
	{1, "Проезд на красный"},
	{2, "Превышение скорости"},
	{3, "Парковка в неположенном месте"},
	{4, "Пересечение сплошной"},
	{5, "Езда в нетрезвом состоянии"},
	{6, "Оскорбление офицера"},
	{7, "Ремень безопасности"},
};

class Crime
{
	int id; //статья
	std::string place; //местро правонарушения

public:
	int get_id()const
	{
		return id;
	}
	const std::string& get_place()const
	{
		return place;
	}
	void set_id(int id)
	{
		if (id > CRIMES.size())id = 0;
		this->id = id;
	}
	void set_place(const std::string& place)
	{
		this->place = place;
	}
	Crime(int id, const std::string& place)
	{
		set_id(id);
		set_place(place);
	}
	~Crime() {}
	//friend class ostream;
};

std::ostream& operator<<(std::ostream& os, const Crime& obj)
{
	return os << obj.get_id() << "\t" << obj.get_place();
}

void main()
{
	setlocale(LC_ALL, "");

	std::map<std::string, std::list<Crime> > base =
	{
		{"m777ab", {Crime(1, "ул. Ленина"), Crime(2, "ул. Ленина"), Crime(4, "ул. Парижской коммуны")}},
		{"k231cc", {Crime(5, "ул. Карла Маркса"), Crime(6, "ул. Карла Маркса") }},
		{"p441oc", {Crime(3, "ул. Пролетарская"), Crime(7, "ул. Пролетарская") }}
	};

	for (std::map<std::string, std::list<Crime> >::iterator it = base.begin(); it != base.end(); ++it)
	{
		cout << it->first  << endl;
		for (std::list<Crime>::iterator l_it = it->second.begin(); l_it != it->second.end(); l_it++)
			cout << *l_it << endl;
	}

	
}
