#pragma once
#include <iostream>
#include <ostream>
using namespace std;
#include "Worker.h"
#include "Employee.h"
#include "Manager.h"
#include "Boss.h"

class WorkManager
{
public:
	WorkManager();
	~WorkManager();
	/**
	 * .
	 * 0.�˳��������
	 * 1.����ְ����Ϣ
	 * 2.��ʾְ����Ϣ;
	 * 3.ɾ����ְְ��
	 * 4.�޸�ְ����Ϣ
	 * 5.����ְ����Ϣ
	 * 6.���ձ������
	 * 7.��������ĵ�
	 */
	void ShowMeun();
	void AddWorker();
	void ExitSystem();
	void FlushMeun();

	int hasNum;
	Worker** worker;
};

