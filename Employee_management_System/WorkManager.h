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
	 * 0.退出管理程序
	 * 1.增加职工信息
	 * 2.显示职工信息;
	 * 3.删除离职职工
	 * 4.修改职工信息
	 * 5.查找职工信息
	 * 6.按照编号排序
	 * 7.清空所有文档
	 */
	void ShowMeun();
	void AddWorker();
	void ExitSystem();
	void FlushMeun();

	int hasNum;
	Worker** worker;
};

