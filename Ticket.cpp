#include "stdafx.h"
#include "Ticket.h"
#include "Buyer.h"

Ticket:: Ticket(Buyer * buyer, Station * startStation, Station * endStation)
{
	m_pBuyer = buyer;
	m_pStartStation = startStation;
	m_pEndStation = endStation;
	m_iTicketID = currentTicketID++;
}

void Ticket::print()
{
	cout << "���ǳ�Ʊ��Ϣ:" << endl << endl;
	cout << "������" << m_pBuyer->m_strName << endl;
	cout << "���֤�ţ�" << m_pBuyer->m_iId << endl;
	cout << "��ʼվ�㣺" << m_pStartStation->m_strStationName << endl;
	cout << "�յ�վ��" << m_pEndStation->m_strStationName << endl;
	cout << "Ʊ��ID" << m_iTicketID << endl;
	cout << "�۸�" << m_fPrice << endl;
}
