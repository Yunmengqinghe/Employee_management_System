#pragma once
#include "EmployeeBase.h"
class Employer :public EmployeeBase
{
public:
	Employer(string number, string name, string postnumber);
	~Employer();
	virtual void Duty();
};

