#pragma once
#include <iostream>
using namespace std;
#include <string>

class Worker
{
	friend ostream& operator<<(ostream& out,const Worker& Worker);
public:
	virtual void ShowInfo() = 0;
	virtual string GetPostName() = 0;
	
	int id;
	string name;
	int postNum;
	bool isDepart;
};

ostream& operator<<(ostream& out,const Worker& worker);