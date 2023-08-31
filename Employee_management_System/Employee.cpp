#include "Employee.h"

Employee::Employee(int id, string name, int postNum)
{
	this->id = id;
	this->name = name;
	this->postNum = postNum;
	this->isDepart = false;
}

Employee::~Employee()
{
}

void Employee::ShowInfo()
{
	cout << *this;
}

string Employee::GetPostName()
{
	return string("Ô±¹¤");
}
