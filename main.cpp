#include "stdafx.h"
#include <iostream>
#include <string>
#include "SalesSystem.h"

using namespace std;

void showHomeWelcome();
static SalesSystem* salesSystem = NULL;

void pressEnterToMainPage()//返回主页面
{
	cout << "按回车键回到主页\n";
	char a;
	cin >> a;
	showHomeWelcome();
}

void inputAndValid(int* startStationIndex, int* endStationIndex) //输入始末站
{
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
	cout << "请输入起始站名字 (1 ~ 10):\n";

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
	int id;
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
	pressEnterToMainPage();
}

void showSearchPurchaseHistory()//搜寻购票记录
{
	cout << "购票历史查询 \n";
	cout << "1.姓名查询" << endl << "2.身份证查询" << "3.退出" << endl;
	int temp = 0;
	string tempName;
	int tempId;
	Buyer * tempBuyer=NULL;
	cin >> temp;
	switch (temp)
	{
	case 1:
		cout << "请输入你的名字：" << endl;
		cin >> tempName;
		tempBuyer->m_strName = tempName;
		break;
	case 2:
		cout << "请输入你的身份证号：" << endl;
		cin >> tempId;
		tempBuyer->m_iId = tempId;
		break;
	case 3:
		exit(0);
		break;
	default:
		cout << "请输入正确的数字" << endl;
		showSearchPurchaseHistory();
	}
	//vector <Ticket*> searchTickesInfo(tempBuyer);
}

	void showRefoundTicket()//退票
{
		cout << "欢迎来到退票系统" << endl;
		cout << "1.姓名退票" << endl << "2.身份证退票" << "3.退出" <<endl;
		int temp = 0;
		string tempName;
		int tempId;
		Buyer * tempBuyer=NULL;
		cin >> temp;
		switch (temp)
		{
		case 1:
			cin >> tempName;
			tempBuyer->m_strName = tempName;
			break;
		case 2:
			cin >> tempId;
			tempBuyer->m_iId = tempId;
			break;
		case 3:
			exit(0);
			break;
		default:
			cout << "请输入正确的数字" << endl;
			showRefoundTicket();
		}
		bool refoundTickets(tempBuyer);
}


void showHomeWelcome()//主页面
{
	cout << "欢迎来到火车票销售系统!\n";
	cout << "选择你想要的功能:\n";
	cout << "1. 查询余票:\n";
	cout << "2. 购票:\n";
	cout << "3. 查询购票记录:\n";
	cout << "4. 退票:\n";
	cout << "输入其他按键退出:\n";

	int index = 0;
	cin >> index;

	switch (index)
	{
	case 1:
		showSearchRemainTicket();
		break;
	case 2:
		showBuyTicket();
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