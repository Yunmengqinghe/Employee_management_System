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
	cout << "********** ��ӭʹ��ְ������ϵͳ! **********" << endl;
	cout << "************* 0.�˳�������� *************" << endl;
	cout << "************* 1.����ְ����Ϣ *************" << endl;
	cout << "************* 2.��ʾְ����Ϣ *************" << endl;
	cout << "************* 3.ɾ����ְְ�� *************" << endl;
	cout << "************* 4.�޸�ְ����Ϣ *************" << endl;
	cout << "************* 5.����ְ����Ϣ *************" << endl;
	cout << "************* 6.���ձ������ *************" << endl;
	cout << "************* 7.��������ĵ� *************" << endl;
	cout <<"********************************************" <<endl;
	cout << endl;
}

void WorkManager::AddWorker()
{
	cout << "������Ҫ��ӵ�Ա������:";
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
				cout << "�������" << i + 1 << "λԱ����ְ����:";
				cin >> tempNum;
				cout << "�������" << i + 1 << "λԱ��������:";
				cin >> tempName;

				cout << "****** Ա��ְλ�� ******" << endl;
				cout << "******* 1.Ա�� *******" << endl;
				cout << "******* 2.���� *******" << endl;
				cout << "******* 3.�ϰ� *******" << endl;
				cout << "��ѡ��Ա��ְλ:";
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

				cout << "�������" << i + 1 << "λԱ����ְ����:";
				cin >> tempNum;
				cout << endl;
				cout << "�������" << i + 1 << "λԱ��������:";
				cin >> tempName;
				cout << endl;

				cout << "****** Ա��ְλ�� ******" << endl;
				cout << "******* 1.Ա�� *******" << endl;
				cout << "******* 2.���� *******" << endl;
				cout << "******* 3.�ϰ� *******" << endl;
				cout << "��ѡ��Ա��ְλ:";
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
	cout << "ְ����" << "  ����" << "  ְλ���" << endl;
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
	cout << "�ɹ��˳�!" << endl;
	system("pause");
	exit(0);
}

void WorkManager::FlushMeun()
{
	system("cls");
}
