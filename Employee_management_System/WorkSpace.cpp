#include <iostream>
#include <list>
#include "Employee.h"
#include "Manager.h"
#include "WorkManager.h"

int main()
{
	WorkManager method;
	char select;
	while (true)
	{
		method.ShowMeun();
		cout << "请输入你的选择:";
		cin.get(select);

		/**
		 * .
		 * \param select The function you choose.
		 *
		 * \brief
		 * 0.退出管理程序
		 * 1.增加职工信息
		 * 2.显示职工信息;
		 * 3.删除离职职工
		 * 4.修改职工信息
		 * 5.查找职工信息
		 * 6.按照编号排序
		 * 7.清空所有文档
		 * 
		 */

		switch (select)
		{
		case '0':
			method.ExitSystem();
			break;
		case '1':
			method.AddWorker();
			method.WriteIntoFile();
			break;
		case '2':
			method.ShowWorker();
			break;
		case '3':
			method.DeleteWorker();
			method.WriteIntoFile();
			break;
		case '4':
			method.ChangeWorker();
			method.WriteIntoFile();
			break;
		case '5':
			method.FindWorker(0);
			break;
		case '6':
			method.SortWorkerArray();
			method.WriteIntoFile();
			break;
		case '7':
			method.EmptyAllFile();
			break;
		default:
			cout << "调用default" << endl;
			method.FlushMeun();
			break;
		}
	}
	system("pause");
	return 0;
}
