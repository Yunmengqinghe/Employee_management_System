#include "Manager.h"

Manager::Manager(string number, string name, string postnumber)
{
	this->number = new string(number);
	this->name = new string(name);
	this->postnumber = new string(postnumber);
}

Manager::~Manager()
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

void Manager::Duty()
{
	cout << "ÌýÀÏ°åµÄ" << endl;
}
