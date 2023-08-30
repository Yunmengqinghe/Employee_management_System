#pragma once
#include <iostream>
#include <fstream>
using namespace std;
#include <iterator>
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
	void ShowWorker();

	void WriteIntoFile();
	int GetWorkerNum(); 
	void ReadFormFile();


	int FindWorker();
	void FindWorker(int);

	void DeleteWorker();
	void ChangeWorker();
	void SortWorkerArray();

	void EmptyAllFile();
	void ExitSystem();
	void FlushMeun();

	int hasNum;
	Worker** workerArray;
	bool isFileEmpty;
	const string FILENAME = "storeFile.txt";
};

