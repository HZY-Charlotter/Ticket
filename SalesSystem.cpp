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
	unsigned int currentSeat = m_pLine->m_pTrain->m_uTotalSeat;
	for (int i = 0; i < this->ticketHistory.size(); i++) {
		Ticket* tmpTicket = this->ticketHistory[i];
		if (startStationWithIn(startStation, endStation, tmpTicket->m_pStartStation, tmpTicket->m_pEndStation)) 
		{
			currentSeat--;
		}
	}
	if (currentSeat > 0) 
	{
		return new RemainedTicketsInfo(startStation, endStation, currentSeat);
	}
	return NULL;
}

Ticket * SalesSystem::buyTicket(Buyer * buyer, Station * startStation, Station * endStation)
{
	//首先查询余票
	RemainedTicketsInfo* remainedTicketInfo = this->searchRemainedTickesInfo(startStation, endStation);
	Ticket* newTicket = NULL;
	if (remainedTicketInfo) {
		//查询余票成功，开始订票
		newTicket = new Ticket(buyer, startStation, endStation);
		this->ticketHistory.push_back(newTicket);
	}
	return newTicket;
}

vector<Ticket*> SalesSystem::searchTickesInfo(Buyer * buyer)
{
	vector<Ticket*> resultTickets = vector<Ticket*>();
	for (int i = 0; i < this->ticketHistory.size(); i++) 
	{
		//从购票历史中，搜索满足条件的票
		Ticket* tmpticket = ticketHistory[i];
		if (tmpticket->m_pBuyer->sameBuyer(buyer))
		{
			ticketHistory[i]->print();
			resultTickets.push_back(tmpticket);
		}
	}
	return resultTickets;
}

vector<Ticket*> SalesSystem::refoundTickets(Buyer* buyer)
{
	vector<Ticket*> resultTickets = vector<Ticket*>();
	vector<Ticket*>::iterator it = this->ticketHistory.begin();

	//从购票历史中，查询和入参buyer一致的ticket，并且从购票历史中删除
	while (it != this->ticketHistory.end())
	{
		Ticket* tmpticket = *it;
		if (tmpticket->m_pBuyer->sameBuyer(buyer)) {
			it = this->ticketHistory.erase(it);
			resultTickets.push_back(tmpticket);
		}
		else {
			it++;
		}
	}
	return resultTickets;
}


SalesSystem::SalesSystem() {
	Station* firstStation = setupStation();
	Train* train = setupTrain();
	this->m_pLine = new Line("K27", 1234, firstStation, train);
	this->ticketHistory = loadTicketFromFile();
}

SalesSystem::~SalesSystem() {
	saveTicketToFile();
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

Station * SalesSystem:: stationWithIndex(int index)
{
	Station* currentStation = m_pLine->m_pStartStation;
	while (currentStation && currentStation->m_iStationID != index)
	{
		currentStation = currentStation->m_pNextStation;
	}
	return currentStation;
}

Train * SalesSystem::setupTrain()
{
	return new Train("Old train", 1234, 10);
}

bool SalesSystem::startStationWithIn(Station*searchStartStation, Station*searchEndStation, Station* startStation, Station* endStation) {
	Station* currentStation = searchStartStation;
	vector<int> stationIDs = vector<int>();
	while (currentStation) {
		if (currentStation->m_iStationID <= endStation->m_iStationID) {
			if (currentStation->m_iStationID >= startStation->m_iStationID) {
				stationIDs.push_back(currentStation->m_iStationID);
				if (stationIDs.size() == 2) {
					return true;
				}
			}
		}
		if (currentStation->m_iStationID == searchEndStation->m_iStationID) {
			break;
		}
		currentStation = currentStation->m_pNextStation;
	}
	return false;
}
