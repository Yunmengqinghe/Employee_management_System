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
	cout << *this;
}

string Boss::GetPostName()
{
	return string("�ϰ�");
}
