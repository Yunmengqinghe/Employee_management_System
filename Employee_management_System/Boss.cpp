#include "Boss.h"

Boss::Boss(int id, string name, int postNum)
{
	this->id = id;
	this->name = name;
	this->postNum = postNum;
}

Boss::~Boss()
{
}

void Boss::ShowInfo()
{
	cout << "  " << id;
	cout << "    " << name;
	cout << "    " << postNum << endl;
}

string Boss::GetPostName()
{
	return string("ÀÏ°å");
}
