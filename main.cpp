#include "stdafx.h"
#include <iostream>
#include <string>
#include "SalesSystem.h"

using namespace std;

void showHomeWelcome();
static SalesSystem* salesSystem = NULL;

void pressEnterToMainPage()//������ҳ��
{
	cout << "���س����ص���ҳ\n";
	char a;
	cin >> a;
	showHomeWelcome();
}

void inputAndValid(int* startStationIndex, int* endStationIndex) //����ʼĩվ
{
	cin >> *startStationIndex;

	while (*startStationIndex < 1 || *startStationIndex > 10) 
	{
		cout << "�����վ�����֡����ٴ�����\n";
		cin >> *startStationIndex;
	}

	cout << "�������յ�վ������ (1 ~ 10):\n";

	cin >> *endStationIndex;
	while (*endStationIndex < 1 || *endStationIndex > 10)
	{
		cout << "�����վ�����֡����ٴ�����\n";
		cin >> *endStationIndex;
	}

	if (*startStationIndex == *endStationIndex)
	{
		cout << "������ʼվ���յ�վ��ͬ��\n";
		pressEnterToMainPage();
	}

	if (*startStationIndex > *endStationIndex) 
	{
		int tempStation = *startStationIndex;
		*startStationIndex = *endStationIndex;
		*endStationIndex = tempStation;
	}
}

void showSearchRemainTicket() //��ѯ��Ʊ��չʾ��Ϣ
{
	cout << "��ӭ���ٳ�Ʊ��ѯϵͳ!\n";
	cout << "��������ʼվ���� (1 ~ 10):\n";

	int startStationIndex;
	int endStationIndex;

	inputAndValid(&startStationIndex, &endStationIndex);
	Station* startStation = salesSystem->stationWithIndex(startStationIndex);
	Station* endStation = salesSystem->stationWithIndex(endStationIndex);
	RemainedTicketsInfo* remainedTicketsinfo = salesSystem->searchRemainedTickesInfo(startStation, endStation);

	cout << "��ʼվ�� " + startStation->m_strStationName + "���յ�վ�� " + endStation->m_strStationName + " ��\n";
	cout << "ʣ�� " + to_string(remainedTicketsinfo->m_uRemainedTickets) + " ��Ʊ��";
	pressEnterToMainPage();
}



void showBuyTicket() //����Ʊ
{
	cout << "��ӭ���ٹ�Ʊϵͳ!\n";
	cout << "�������������:\n";
	string name;
	cin >> name;
	cout << "������������֤��:\n";
	int id;
	cin >> id;

	int startStationIndex;
	int endStationIndex;

	inputAndValid(&startStationIndex, &endStationIndex);//����ʼĩվ

	Station* startStation = salesSystem->stationWithIndex(startStationIndex);
	Station* endStation = salesSystem->stationWithIndex(endStationIndex);
	RemainedTicketsInfo* remainedTicketsinfo = salesSystem->searchRemainedTickesInfo(startStation, endStation);
	Ticket* ticket = NULL;
	//����Ƿ�����Ʊ
	if (remainedTicketsinfo->m_uRemainedTickets > 0)
	{
		ticket = salesSystem->buyTicket(new Buyer(name, id), salesSystem->stationWithIndex(startStationIndex), salesSystem->stationWithIndex(endStationIndex));
	}
	if (ticket)
	{
		cout << "����ɹ� !!!";
	}
	pressEnterToMainPage();
}

void showSearchPurchaseHistory()//��Ѱ��Ʊ��¼
{
	cout << "��Ʊ��ʷ��ѯ \n";
	cout << "1.������ѯ" << endl << "2.���֤��ѯ" << "3.�˳�" << endl;
	int temp = 0;
	string tempName;
	int tempId;
	Buyer * tempBuyer=NULL;
	cin >> temp;
	switch (temp)
	{
	case 1:
		cout << "������������֣�" << endl;
		cin >> tempName;
		tempBuyer->m_strName = tempName;
		break;
	case 2:
		cout << "������������֤�ţ�" << endl;
		cin >> tempId;
		tempBuyer->m_iId = tempId;
		break;
	case 3:
		exit(0);
		break;
	default:
		cout << "��������ȷ������" << endl;
		showSearchPurchaseHistory();
	}
	//vector <Ticket*> searchTickesInfo(tempBuyer);
}

	void showRefoundTicket()//��Ʊ
{
		cout << "��ӭ������Ʊϵͳ" << endl;
		cout << "1.������Ʊ" << endl << "2.���֤��Ʊ" << "3.�˳�" <<endl;
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
			cout << "��������ȷ������" << endl;
			showRefoundTicket();
		}
		bool refoundTickets(tempBuyer);
}


void showHomeWelcome()//��ҳ��
{
	cout << "��ӭ������Ʊ����ϵͳ!\n";
	cout << "ѡ������Ҫ�Ĺ���:\n";
	cout << "1. ��ѯ��Ʊ:\n";
	cout << "2. ��Ʊ:\n";
	cout << "3. ��ѯ��Ʊ��¼:\n";
	cout << "4. ��Ʊ:\n";
	cout << "�������������˳�:\n";

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