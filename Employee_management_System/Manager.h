#pragma once
#include "Worker.h"

class Manager:public Worker
{
public:
	Manager(int id, string name, int postNum);
	~Manager();
	void ShowInfo();
	string GetPostName();
};

