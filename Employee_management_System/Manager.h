#pragma once
#include "Worker.h"

class Manager:public Worker
{
	Manager(int id, string name, int postNum);
	~Manager();
	void ShowInfo();
	string GetPostName();
};

