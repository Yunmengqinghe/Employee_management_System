#include "EmployeeBase.h"

void EmployeeBase::ShowMessage()
{
	cout << *number << "    " << *name << "    " << *postnumber << endl;
}

string EmployeeBase::GetName()
{
	return *name;
}

string EmployeeBase::GetNumber()
{
	return *number;
}

string EmployeeBase::GetPostNumber()
{
	return *postnumber;
}
