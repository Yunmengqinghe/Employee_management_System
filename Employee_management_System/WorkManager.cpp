#include "WorkManager.h"

WorkManager::WorkManager()
{

}

WorkManager::~WorkManager()
{

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
