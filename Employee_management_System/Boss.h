#pragma once
#include "Worker.h"

class Boss :public Worker
{
public:
	Boss(int id, string name, int postNum);
	~Boss();
	void ShowInfo();
	string GetPostName();
};

