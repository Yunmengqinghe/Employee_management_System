#pragma once
#include "EmployeeBase.h"
class Manager :public EmployeeBase
{
public:
	Manager(string number, string name, string postnumber);
	~Manager();
	virtual void Duty();
};

