#pragma once
#include "EmployeeBase.h"

class Employee: public EmployeeBase
{
public:
	Employee(string number, string name, string postnumber);
	~Employee();
	virtual void Duty();
};

