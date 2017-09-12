#include "stdafx.h"
#include <iostream>
#include <string>
#include <windows.h>
#include "SalesSystem.h"

using namespace std;

void showHomeWelcome();
static SalesSystem* salesSystem = NULL;

void pressEnterToMainPage()//������ҳ��
{
	cout << "���س����ص���ҳ\n";
	getchar(); 
	getchar();
	showHomeWelcome();
}

void inputAndValid(int* startStationIndex, int* endStationIndex) //����ʼĩվ
{
	cout << "��������ʼվ������ (1 ~ 10):\n";
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
	long long id;
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
	else
	{
		cout << "����ʧ�� !!!";
	}
	pressEnterToMainPage();
}

HANDLE hMutex = NULL;//������
					 //DWORD WINAPI ������ (LPVOID lpParam) ����ʽ����ȷ���޷����óɹ���
DWORD WINAPI buyTicket(LPVOID lpParamter)//lpParameter�����̺߳������ݵĲ�������һ��ָ��ṹ��ָ�룬���贫�ݲ���ʱ��ΪNULL��
{

	//����һ����������
	WaitForSingleObject(hMutex, INFINITE);
	showBuyTicket();
	Sleep(100);
	//�ͷŻ�������
	ReleaseMutex(hMutex);
	return 0;
}

void multithreadingShowBuyTicket()//���̹߳���Ʊ
{
	HANDLE hThread = CreateThread(NULL, 0, buyTicket, NULL, 0, NULL);//����һ�����߳�
	hMutex = CreateMutexA(NULL, FALSE, "buyTicket");
	//��Ϊ��VS2005�Ժ󣬱��뷽ʽĬ��ΪUnicode�����ֺ�����ʹ��ʱĬ�ϵ���Unicode��ʽ��������+W��exp:MessageBox+W=MessageBoxW��������ANSI��ʽ��������+A��exp:MessageBox+A=MessageBoxA����
	CloseHandle(hThread);//�ر��߳�
	WaitForSingleObject(hMutex, INFINITE);//������һ����������
	showBuyTicket();
	Sleep(100);
	ReleaseMutex(hMutex);
}


void showSearchPurchaseHistory()//��Ѱ��Ʊ��¼
{
	cout << "��ӭ����Ʊ���ѯ��ʷϵͳ!\n";

	string name;
	long long id = 0;

	cout << "��ѡ���ѯ��ʽ" << endl << "1.������ѯ" << endl << "2.���֤�����ѯ" << endl << "3.������ҳ��" << endl;
	int index = 0;
	cin >> index;
	switch (index)
	{
	case 1:
		cout << "�������������\n";
		cin >> name;
		break;
	case 2:
		cout << "������������֤��\n";
		cin >> id;
		break;
	case 3:
		pressEnterToMainPage();
		break;
	default:
		cout << "��������ȷ������!!!" << endl << endl;
		getchar();
		showSearchPurchaseHistory();
		break;
	}

	vector<Ticket*> tickets = salesSystem->searchTickesInfo(new Buyer(name, id));
	cout << "�㹺��� " + to_string(tickets.size()) + "��Ʊ\n";
	pressEnterToMainPage();
}

	void showRefoundTicket()//��Ʊ
{
		cout << "��ӭ������Ʊϵͳ!\n";

		string name;
		long long id=0;


		cout << "��ѡ����Ʊ��ʽ" << endl << "1.������Ʊ" << endl << "2.���֤������Ʊ" <<endl<<"3.������ҳ��"<< endl;
		int index = 0;
		cin >> index;
		switch (index)
		{
		case 1:
			cout << "�������������\n";
			cin >> name;
			break;
		case 2:
			cout << "������������֤��\n";
			cin >> id;
			break;
		case 3:
			pressEnterToMainPage();
			break;
		default:
			cout << "��������ȷ������!!!" << endl<<endl;
			getchar();
			showRefoundTicket();
			break;
		}

		vector<Ticket*> tickets = salesSystem->refoundTickets(new Buyer(name, id));
		cout << "���Ѿ����� " + to_string(tickets.size()) + "��Ʊ\n";
}

void showHomeWelcome()//��ҳ��
{
	cout << "��ӭ������Ʊ����ϵͳ!\n";
	cout << "ѡ������Ҫ�Ĺ���\n";
	cout << "1. ��ѯ��Ʊ\n";
	cout << "2. ��Ʊ\n";
	cout << "3. ��ѯ��Ʊ��¼\n";
	cout << "4. ��Ʊ\n\n";
	cout << "�������������˳�\n";

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
