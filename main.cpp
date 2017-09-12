#include "stdafx.h"
#include <iostream>
#include <string>
#include <windows.h>
#include "SalesSystem.h"

using namespace std;

void showHomeWelcome();
static SalesSystem* salesSystem = NULL;

void pressEnterToMainPage()//返回主页面
{
	cout << "按回车键回到主页\n";
	getchar(); 
	getchar();
	showHomeWelcome();
}

void inputAndValid(int* startStationIndex, int* endStationIndex) //输入始末站
{
	cout << "请输入起始站的名字 (1 ~ 10):\n";
	cin >> *startStationIndex;

	while (*startStationIndex < 1 || *startStationIndex > 10) 
	{
		cout << "错误的站点名字。请再次输入\n";
		cin >> *startStationIndex;
	}

	cout << "请输入终点站的名字 (1 ~ 10):\n";

	cin >> *endStationIndex;
	while (*endStationIndex < 1 || *endStationIndex > 10)
	{
		cout << "错误的站点名字。请再次输入\n";
		cin >> *endStationIndex;
	}

	if (*startStationIndex == *endStationIndex)
	{
		cout << "错误，起始站和终点站相同！\n";
		pressEnterToMainPage();
	}

	if (*startStationIndex > *endStationIndex) 
	{
		int tempStation = *startStationIndex;
		*startStationIndex = *endStationIndex;
		*endStationIndex = tempStation;
	}
}

void showSearchRemainTicket() //查询余票并展示信息
{
	cout << "欢迎光临车票查询系统!\n";

	int startStationIndex;
	int endStationIndex;

	inputAndValid(&startStationIndex, &endStationIndex);
	Station* startStation = salesSystem->stationWithIndex(startStationIndex);
	Station* endStation = salesSystem->stationWithIndex(endStationIndex);
	RemainedTicketsInfo* remainedTicketsinfo = salesSystem->searchRemainedTickesInfo(startStation, endStation);

	cout << "起始站是 " + startStation->m_strStationName + "。终点站是 " + endStation->m_strStationName + " 。\n";
	cout << "剩余 " + to_string(remainedTicketsinfo->m_uRemainedTickets) + " 张票。";
	pressEnterToMainPage();
}

void showBuyTicket() //购买车票
{
	cout << "欢迎光临购票系统!\n";
	cout << "请输入你的名字:\n";
	string name;
	cin >> name;
	cout << "请输入你的身份证号:\n";
	long long id;
	cin >> id;

	int startStationIndex;
	int endStationIndex;

	inputAndValid(&startStationIndex, &endStationIndex);//输入始末站
	Station* startStation = salesSystem->stationWithIndex(startStationIndex);
	Station* endStation = salesSystem->stationWithIndex(endStationIndex);

	RemainedTicketsInfo* remainedTicketsinfo = salesSystem->searchRemainedTickesInfo(startStation, endStation);
	Ticket* ticket = NULL;
	//检查是否有余票
	if (remainedTicketsinfo->m_uRemainedTickets > 0)
	{
		ticket = salesSystem->buyTicket(new Buyer(name, id), salesSystem->stationWithIndex(startStationIndex), salesSystem->stationWithIndex(endStationIndex));
	}
	if (ticket)
	{
		cout << "购买成功 !!!";
	}
	else
	{
		cout << "购买失败 !!!";
	}
	pressEnterToMainPage();
}

HANDLE hMutex = NULL;//互斥量
					 //DWORD WINAPI 函数名 (LPVOID lpParam) ，格式不正确将无法调用成功。
DWORD WINAPI buyTicket(LPVOID lpParamter)//lpParameter：向线程函数传递的参数，是一个指向结构的指针，不需传递参数时，为NULL。
{

	//请求一个互斥量锁
	WaitForSingleObject(hMutex, INFINITE);
	showBuyTicket();
	Sleep(100);
	//释放互斥量锁
	ReleaseMutex(hMutex);
	return 0;
}

void multithreadingShowBuyTicket()//多线程购买车票
{
	HANDLE hThread = CreateThread(NULL, 0, buyTicket, NULL, 0, NULL);//创建一个子线程
	hMutex = CreateMutexA(NULL, FALSE, "buyTicket");
	//因为在VS2005以后，编码方式默认为Unicode，部分函数在使用时默认调用Unicode方式（函数名+W，exp:MessageBox+W=MessageBoxW），而非ANSI方式（函数名+A，exp:MessageBox+A=MessageBoxA）。
	CloseHandle(hThread);//关闭线程
	WaitForSingleObject(hMutex, INFINITE);//请求获得一个互斥量锁
	showBuyTicket();
	Sleep(100);
	ReleaseMutex(hMutex);
}


void showSearchPurchaseHistory()//搜寻购票记录
{
	cout << "欢迎光临票务查询历史系统!\n";

	string name;
	long long id = 0;

	cout << "请选择查询方式" << endl << "1.姓名查询" << endl << "2.身份证号码查询" << endl << "3.返回主页面" << endl;
	int index = 0;
	cin >> index;
	switch (index)
	{
	case 1:
		cout << "请输入你的名字\n";
		cin >> name;
		break;
	case 2:
		cout << "请输入你的身份证号\n";
		cin >> id;
		break;
	case 3:
		pressEnterToMainPage();
		break;
	default:
		cout << "请输入正确的数字!!!" << endl << endl;
		getchar();
		showSearchPurchaseHistory();
		break;
	}

	vector<Ticket*> tickets = salesSystem->searchTickesInfo(new Buyer(name, id));
	cout << "你购买过 " + to_string(tickets.size()) + "张票\n";
	pressEnterToMainPage();
}

	void showRefoundTicket()//退票
{
		cout << "欢迎光临退票系统!\n";

		string name;
		long long id=0;


		cout << "请选择退票方式" << endl << "1.姓名退票" << endl << "2.身份证号码退票" <<endl<<"3.返回主页面"<< endl;
		int index = 0;
		cin >> index;
		switch (index)
		{
		case 1:
			cout << "请输入你的名字\n";
			cin >> name;
			break;
		case 2:
			cout << "请输入你的身份证号\n";
			cin >> id;
			break;
		case 3:
			pressEnterToMainPage();
			break;
		default:
			cout << "请输入正确的数字!!!" << endl<<endl;
			getchar();
			showRefoundTicket();
			break;
		}

		vector<Ticket*> tickets = salesSystem->refoundTickets(new Buyer(name, id));
		cout << "您已经退了 " + to_string(tickets.size()) + "张票\n";
}

void showHomeWelcome()//主页面
{
	cout << "欢迎来到火车票销售系统!\n";
	cout << "选择你想要的功能\n";
	cout << "1. 查询余票\n";
	cout << "2. 购票\n";
	cout << "3. 查询购票记录\n";
	cout << "4. 退票\n\n";
	cout << "输入其他按键退出\n";

	int index = 0;
	cin >> index;

	switch (index)
	{
	case 1:
		showSearchRemainTicket();
		break;
	case 2:
		multithreadingShowBuyTicket();
		break;
	case 3:
		showSearchPurchaseHistory();
		break;
	case 4:
		showRefoundTicket();
		break;
	default:
		exit(0);
		break;
	}
}

int main(int argc, const char * argv[])
{
	salesSystem = new SalesSystem();

	while (1)
	{
		showHomeWelcome();
	}

	return 0;
}
