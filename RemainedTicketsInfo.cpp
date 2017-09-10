#include "stdafx.h"
#include "RemainedTicketsInfo.h"

RemainedTicketsInfo::RemainedTicketsInfo(Station * startStation, Station * endStation, unsigned remainedTickets)
{
	m_pStartStation = startStation;
	m_pEndStation = endStation;
	m_uRemainedTickets = remainedTickets;

	float tempPrice = 0;
	float tempDistance = 0;
	Station* tempStaion = startStation;
	while (tempStaion->m_pNextStation && tempStaion != endStation) {
		tempPrice += tempStaion->m_fPriceToNextStation;
		tempDistance += tempStaion->m_fDistanceToNextStation;
	}
	m_fPrice = tempPrice;
	m_fDistance = tempDistance;
}
