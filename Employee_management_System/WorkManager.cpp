#include "WorkManager.h"

WorkManager::WorkManager()
{
	ifstream ifs(FILENAME, ios::in);
	if (!ifs.is_open())
	{
		this->hasNum = 0;
		this->workerArray = NULL;
		this->isFileEmpty = true;
		ifs.close();
		return;
	}

	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		this->hasNum = 0;
		this->workerArray = NULL;
		this->isFileEmpty = true;
		ifs.close();
		return;
	}
	
	this->isFileEmpty = false;
	this->hasNum = this->GetWorkerNum();
	this->ReadFormFile();

}

WorkManager::~WorkManager()
{
	if (this->workerArray != NULL)
	{
		delete[] workerArray;
	}
}

void WorkManager::ShowMeun()
{
	cout <<"********************************************" <<endl;
	cout << "********** 欢迎使用职工管理系统! **********" << endl;
	cout << "************* 0.退出管理程序 *************" << endl;
	cout << "************* 1.增加职工信息 *************" << endl;
	cout << "************* 2.显示职工信息 *************" << endl;
	cout << "************* 3.删除离职职工 *************" << endl;
	cout << "************* 4.修改职工信息 *************" << endl;
	cout << "************* 5.查找职工信息 *************" << endl;
	cout << "************* 6.按照编号排序 *************" << endl;
	cout << "************* 7.清空所有文档 *************" << endl;
	cout <<"********************************************" <<endl;
	cout << endl;
}

void WorkManager::AddWorker()
{
	cout << "请输入要添加的员工个数:";
	int addNum;
	cin >> addNum;
	if (addNum > 0)
	{
		int newSize = this->hasNum + addNum;
		Worker** newArray = new Worker * [newSize];
		if (this->workerArray != NULL)
		{
			for (int i = 0; i < this->hasNum; i++)
			{
				newArray[i] = workerArray[i];
			}

			for (int i = 0; i < addNum; i++)
			{
				int tempNum;
				string tempName;
				int tempPostNum;
				cout << "请输入第" << i + 1 << "位员工的职工号:";
				cin >> tempNum;
				cout << endl;
				cout << "请输入第" << i + 1 << "位员工的姓名:";
				cin >> tempName;
				cout << endl;

				cout << "****** 员工职位表 ******" << endl;
				cout << "******* 1.员工 *******" << endl;
				cout << "******* 2.经理 *******" << endl;
				cout << "******* 3.老板 *******" << endl;
				cout << "请选择员工职位:";
				cin >> tempPostNum;
				cout << endl;

				Worker* worker;
				switch (tempPostNum)
				{
				case 1:
					worker = new Employee(tempNum, tempName, tempPostNum);
					break;
				case 2:
					worker = new Manager(tempNum, tempName, tempPostNum);
					break;
				case 3:
					worker = new Boss(tempNum, tempName, tempPostNum);
					break;
				default:
					worker = NULL;
					break;
				}
				newArray[this->hasNum + i] = worker;
			}
			this->hasNum = newSize;
			delete[] this->workerArray;
			this->workerArray = newArray;
		}
		else
		{
			this->workerArray = new Worker * [addNum];
			for (int i = 0; i < addNum; i++)
			{
				int tempNum;
				string tempName;
				int tempPostNum;

				cout << "请输入第" << i + 1 << "位员工的职工号:";
				cin >> tempNum;
				cout << endl;
				cout << "请输入第" << i + 1 << "位员工的姓名:";
				cin >> tempName;
				cout << endl;

				cout << "****** 员工职位表 ******" << endl;
				cout << "******* 1.员工 *******" << endl;
				cout << "******* 2.经理 *******" << endl;
				cout << "******* 3.老板 *******" << endl;
				cout << "请选择员工职位:";
				cin >> tempPostNum;
				cout << endl;

				Worker* worker;
				switch (tempPostNum)
				{
				case 1:
					worker = new Employee(tempNum, tempName, tempPostNum);
					break;
				case 2:
					worker = new Manager(tempNum, tempName, tempPostNum);
					break;
				case 3:
					worker = new Boss(tempNum, tempName, tempPostNum);
					break;
				default:
					worker = NULL;
					break;
				}
				this->workerArray[i] = worker;
			}
			this->hasNum = addNum;
		}
		this->isFileEmpty = false;
	}
}

void WorkManager::ShowWorker()
{
	if (this->workerArray == NULL)
	{
		cout << "没有员工!" << endl;
		system("pause");
		return;
	}
	cout << "职工号" << "  姓名" << "  职位编号" << endl;
	for (int i = 0; i < this->hasNum; i++)
	{
		cout << *this->workerArray[i];
	}
	system("pause");
}

void WorkManager::WriteIntoFile()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);
	if (!ofs)
	{
		cout << "no" << endl;
		return;
	}
	for (int i = 0; i < this->hasNum; i++)
	{
		ofs << this->workerArray[i]->id << " " << this->workerArray[i]->name << " ";
		ofs << this->workerArray[i]->postNum << endl;
	}
	ofs.close();
}

int WorkManager::GetWorkerNum()
{
	ifstream ifs(FILENAME, ios::in);
	int tempNum, tempPostNum;
	string tempName;
	int num = 0;
	while (ifs >> tempNum && ifs >> tempName && ifs >> tempPostNum)
	{
		num++;
	}
	return num;
}

void WorkManager::ReadFormFile()
{
	this->workerArray = new Worker * [this->hasNum];
	ifstream ifs(FILENAME, ios::in);
	int tempNum, tempPostNum;
	string tempName;
	for (int i = 0; i < this->hasNum; i++)
	{
		ifs >> tempNum; 
		ifs >> tempName; 
		ifs >> tempPostNum;
		Worker* worker;
		switch (tempPostNum)
		{
		case 1:
			worker = new Employee(tempNum, tempName, tempPostNum);
			break;
		case 2:
			worker = new Manager(tempNum, tempName, tempPostNum);
			break;
		case 3:
			worker = new Boss(tempNum, tempName, tempPostNum);
			break;
		default:
			worker = NULL;
			break;
		}
		this->workerArray[i] = worker;
	}
}

int WorkManager::FindWorker()
{
	int select;

	cout << endl;
	cout << "******* 查找方式 *******" << endl;
	cout << "******* 1.职工号 *******" << endl;
	cout << "******* 2.姓名   *******" << endl;
	cout << "请选择查找方式:";
	cin >> select;
	cout << endl;

	if (select == 1)
	{
		int tempNum;
		cout << "请输入职工号:";
		cin >> tempNum;
		for (int i = 0; i < this->hasNum; i++)
		{
			if (this->workerArray[i]->id == tempNum)
			{
				return i;
			}
		}
	}
	else if (select == 2)
	{
		string tempName;
		cout << "请输入职工姓名:";
		cin >> tempName;
		for (int i = 0; i < this->hasNum; i++)
		{
			if (this->workerArray[i]->name == tempName)
			{
				return i;
			}
		}
	}
	return -1;
}

void WorkManager::FindWorker(int)
{
	int tempNum;
	cout << "请输入职工号:";
	cin >> tempNum;
	for (int i = 0; i < this->hasNum; i++)
	{
		if (this->workerArray[i]->id == tempNum)
		{
			cout << *this->workerArray[i];
		}
	}
	system("pause");
}

void WorkManager::DeleteWorker()
{
	int subscript = FindWorker();
	Worker** newArray = new Worker * [this->hasNum - 1];
	int rec_subscript = 0;
	for (int i = 0; i < this->hasNum; i++)
	{
		if (i != subscript)
		{
			newArray[rec_subscript] = this->workerArray[i];
			rec_subscript++;
		}
	}
	this->hasNum -= 1;
	delete[] this->workerArray;
	this->workerArray = newArray;
}

void WorkManager::ChangeWorker()
{
	int select;
	int subscript = FindWorker();
	cout << endl;
	cout << "**** 修改项目 ****" << endl;
	cout << "**** 1.职工号 ****" << endl;
	cout << "**** 2.姓名 ****" << endl;
	cout << "请选择你的项目:" << endl;
	cin >> select;
	cout << endl;

	if (select == 1)
	{
		int tempNum;
		cout << "请输入职工号:";
		cin >> tempNum;
		this->workerArray[subscript]->id = tempNum;
	}
	else if (select == 2)
	{
		string tempName;
		cout << "请输入姓名:";
		cin >> tempName;
		this->workerArray[subscript]->name = tempName;
	}
}

void WorkManager::SortWorkerArray()
{
	for (int i = 0; i < this->hasNum - 1; i++)
	{
		for (int j = i; j < this->hasNum - i - 1; j++)
		{
			if (workerArray[j] < workerArray[j + 1])
			{
				Worker* worker = workerArray[j];
				workerArray[j] = workerArray[j + 1];
				workerArray[j + 1] = worker;
			}
		}
	}
}

void WorkManager::EmptyAllFile()
{
	ofstream ofs(FILENAME, ios::out);
	delete[] this->workerArray;
	this->workerArray = NULL;
	ofs.close();
}

void WorkManager::ExitSystem()
{
	cout << "成功退出!" << endl;
	system("pause");
	exit(0);
}

void WorkManager::FlushMeun()
{
	system("cls");
}
