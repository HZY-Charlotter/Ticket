#include "stdafx.h"
#include "Ticket.h"
#include "Buyer.h"

Ticket:: Ticket(Buyer * buyer, Station * startStation, Station * endStation)
{
	m_pBuyer = buyer;
	m_pStartStation = startStation;
	m_pEndStation = endStation;
	m_iTicketID = currentTicketID++;

	float tempPrice = 0;
	float tempDistance = 0;
	Station* tempStaion = startStation;
	while (tempStaion->m_pNextStation && tempStaion->m_iStationID != endStation->m_iStationID) {
		tempPrice += tempStaion->m_fPriceToNextStation;
		tempDistance += tempStaion->m_fDistanceToNextStation;
		tempStaion = tempStaion->m_pNextStation;
	}
	m_fPrice= tempPrice;
	m_fDistance= tempDistance;
}

void Ticket::print()
{
	cout << "这是车票信息:" << endl ;
	cout << "姓名：" << m_pBuyer->m_strName << endl;
	cout << "身份证号：" << m_pBuyer->m_iId << endl;
	cout << "起始站点：" << m_pStartStation->m_strStationName << endl;
	cout << "终点站：" << m_pEndStation->m_strStationName << endl;
	cout << "票务ID : " << m_iTicketID << endl;
	cout << "价格 : " << m_fPrice <<"元"<< endl<<endl;
}
