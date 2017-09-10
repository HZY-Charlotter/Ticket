#include "stdafx.h"
#include "SalesSystem.h"
#include <iostream>
#include <vector>
#include "Line.h"
#include "Ticket.h"
#include "Station.h"
#include "Train.h"
#include "Buyer.h"
#include "RemainedTicketsInfo.h"
using namespace std;

RemainedTicketsInfo * SalesSystem::searchRemainedTickesInfo(Station * startStation, Station * endStation)
{
	int num = 10;//10¸ö×ùÎ»
	for (int i = 0; i < currentTicketID; i++)
	{
		int m = startStation->m_iStationID;
		if (m >= tickets.at(i)->m_pStartStation->m_iStationID&&m <= tickets.at(i)->m_pEndStation->m_iStationID)
			num -= 1;
	}
	 searchRemainedTickesInfo(startStation, endStation)->m_uRemainedTickets=num ;
	return nullptr;
}

Ticket * SalesSystem::buyTicket(Buyer * buyer, Station * startStation, Station * endStation)
{
	Ticket* tempTicket=NULL;
	tempTicket->m_pBuyer = buyer;
	tempTicket->m_pStartStation = startStation;
	tempTicket->m_pEndStation = endStation;
	tickets.push_back(tempTicket);
	return nullptr;
}

vector<Ticket*> SalesSystem::searchTickesInfo(Buyer * buyer)
{
	for (int i=0 ; i < currentTicketID; i++)
	{
		if (tickets.at(i)->m_pBuyer->m_strName == buyer->m_strName || tickets.at(i)->m_pBuyer->m_iId == buyer->m_iId) 
		{
			tickets.at(i)->print();
		}
	}
	return vector<Ticket*>();
}

bool SalesSystem::refoundTickets(Buyer * buyer)
{
	for (int i = 0; i < currentTicketID ; i++)
	{
		if (tickets.at(i)->m_pBuyer->m_strName == buyer->m_strName || tickets.at(i)->m_pBuyer->m_iId == buyer->m_iId)
		{
			tickets.erase(tickets.begin() +i);
		}
	}
	return false;
}

Station * SalesSystem:: stationWithIndex(int index)
{
	Station* currentStation = m_pLine->m_pStartStation;
	while (currentStation && currentStation->m_iStationID != index)
	{
		currentStation = currentStation->m_pNextStation;
	}
	return currentStation;
}

SalesSystem::SalesSystem()
{
	Station* firstStation = setupStation();
	Train* train = setupTrain();
	m_pLine = new Line("K27", 1234, firstStation, train);
}

Train * SalesSystem::setupTrain()
{
	return new Train("Old train", 1234, 10);
}

Station * SalesSystem::setupStation()
{
	int stationID = 1;
	float distanceToNext = 99;

	Station* firstStation = NULL;
	Station* preStation = NULL;
	for (int i = 0; i < 10; i++) {
		string stationName = "A" + to_string(stationID);
		Station* station = new Station(stationID, stationName, distanceToNext, NULL);
		if (i == 0) {
			firstStation = station;
		}
		if (preStation) {
			preStation->m_pNextStation = station;
		}
		preStation = station;
		stationID++;
		distanceToNext++;
	}
	return firstStation;
}
