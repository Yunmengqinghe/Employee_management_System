#include "WorkManager.h"


WorkManager::WorkManager()
{
	hasNum = 0;
	workerArray = NULL;
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
				cout << "请输入第" << i + 1 << "位员工的姓名:";
				cin >> tempName;

				cout << "****** 员工职位表 ******" << endl;
				cout << "******* 1.员工 *******" << endl;
				cout << "******* 2.经理 *******" << endl;
				cout << "******* 3.老板 *******" << endl;
				cout << "请选择员工职位:";
				cin >> tempPostNum;
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
	}
}

void WorkManager::ShowWorker()
{
	cout << "职工号" << "  姓名" << "  职位编号" << endl;
	for (int i = 0; i < this->hasNum; i++)
	{
		cout << *this->workerArray[i];
	}
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

void WorkManager::ReadFormFile()
{
	ifstream ifs(FILENAME, ios::in);

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
