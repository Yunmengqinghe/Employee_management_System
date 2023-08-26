#include "Employee.h"

Employee::Employee(string number, string name, string postnumber)
{
	this->number = new string(number);
	this->name = new string(name);
	this->postnumber = new string(postnumber);
}

Employee::~Employee()
{
	if (number != NULL)
	{
		delete number;
		number = NULL;
	}
	if (name != NULL)
	{
		delete name;
		name = NULL;
	}
	if (postnumber != NULL)
	{
		delete postnumber;
		postnumber = NULL;
	}
}

void Employee::Duty()
{
	cout << "听经理的话" << endl;
}