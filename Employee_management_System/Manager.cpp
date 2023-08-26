#include "Manager.h"

Manager::Manager(int id, string name, int postNum)
{
	this->id = id;
	this->name = name;
	this->postNum = postNum;
}

Manager::~Manager()
{
}

void Manager::ShowInfo()
{
	cout << "  " << id;
	cout << "    " << name;
	cout << "    " << postNum << endl;
}

string Manager::GetPostName()
{
	return string("¾­Àí");
}
