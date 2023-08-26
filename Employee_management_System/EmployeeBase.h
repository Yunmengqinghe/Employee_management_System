#pragma once
#include <iostream>
#include <string>
using namespace std;

class EmployeeBase
{
public:

	void ShowMessage();
	string GetNumber();
	string GetName();
	string GetPostNumber();
	virtual void Duty() = 0;

public:
	string* number;
	string* name;
	string* postnumber;
};

