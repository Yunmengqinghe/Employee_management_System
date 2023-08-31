#include "Manager.h"

Manager::Manager(int id, string name, int postNum)
{
	this->id = id;
	this->name = name;
	this->postNum = postNum;
	this->isDepart = false;
}

Manager::~Manager()
{
}

void Manager::ShowInfo()
{
	cout << *this;
}

string Manager::GetPostName()
{
	return string("¾­Àí");
}
