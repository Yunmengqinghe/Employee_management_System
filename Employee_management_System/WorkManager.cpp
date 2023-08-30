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
		this->isFileEmpty = false;
	}
}

void WorkManager::ShowWorker()
{
	if (this->workerArray == NULL)
	{
		cout << "û��Ա��!" << endl;
		system("pause");
		return;
	}
	cout << "ְ����" << "  ����" << "  ְλ���" << endl;
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
	cout << "******* ���ҷ�ʽ *******" << endl;
	cout << "******* 1.ְ���� *******" << endl;
	cout << "******* 2.����   *******" << endl;
	cout << "��ѡ����ҷ�ʽ:";
	cin >> select;
	cout << endl;

	if (select == 1)
	{
		int tempNum;
		cout << "������ְ����:";
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
		cout << "������ְ������:";
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
	cout << "������ְ����:";
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
	cout << "**** �޸���Ŀ ****" << endl;
	cout << "**** 1.ְ���� ****" << endl;
	cout << "**** 2.���� ****" << endl;
	cout << "��ѡ�������Ŀ:" << endl;
	cin >> select;
	cout << endl;

	if (select == 1)
	{
		int tempNum;
		cout << "������ְ����:";
		cin >> tempNum;
		this->workerArray[subscript]->id = tempNum;
	}
	else if (select == 2)
	{
		string tempName;
		cout << "����������:";
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
	cout << "�ɹ��˳�!" << endl;
	system("pause");
	exit(0);
}

void WorkManager::FlushMeun()
{
	system("cls");
}
