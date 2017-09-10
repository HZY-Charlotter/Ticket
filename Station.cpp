#include "stdafx.h"
#include "Station.h"

Station::Station(int stationID, string stationName, float distanceToNextStation, Station * nextStation)
{
	m_iStationID = stationID;
	m_strStationName = stationName;
	m_fDistanceToNextStation = distanceToNextStation;
	m_fPriceToNextStation = distanceToNextStation;
	m_pNextStation = nextStation;
}
