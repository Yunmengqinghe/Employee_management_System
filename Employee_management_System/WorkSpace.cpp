#include <iostream>
#include <list>
#include "EmployeeBase.h"
#include "Employee.h"
#include "Employer.h"
#include "Manager.h"
#include "WorkManager.h"


int main()
{
	WorkManager method;
	char select;
	while (true)
	{
		method.ShowMeun();
		cout << "���������ѡ��:";
		cin.get(select);

		/**
		 * .
		 * \param select The function you choose.
		 *
		 * \brief
		 * 0.�˳��������
		 * 1.����ְ����Ϣ
		 * 2.��ʾְ����Ϣ;
		 * 3.ɾ����ְְ��
		 * 4.�޸�ְ����Ϣ
		 * 5.����ְ����Ϣ
		 * 6.���ձ������
		 * 7.��������ĵ�
		 *
		 */

		switch (select)
		{
		case '0':
			method.ExitSystem();
			break;
		case '1':
			break;

		case '2':
			break;
		case '3':
			break;
		case '4':
			break;
		case '5':
			break;
		case '6':
			break;
		case '7':
			break;
		default:
			method.FlushMeun();
			break;
		}
	}

	system("pause");
	return 0;
}
