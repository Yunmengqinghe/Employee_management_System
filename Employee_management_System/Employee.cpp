#include "Employee.h"

Employee::Employee(int id, string name, int postNum)
{
	this->id = id;
	this->name = name;
	this->postNum = postNum;
}

Employee::~Employee()
{
}

void Employee::ShowInfo()
{
	cout << "  " << id;
	cout << "    " << name;
	cout << "    " << postNum << endl;
}

string Employee::GetPostName()
{
	return string("Ա��");
}
