#include "stdafx.h"
#include "Line.h"

Line::Line(string lineName, int lineID, Station * startStation, Train * train)
{
	m_strLineName = lineName;
	m_iLineID = lineID;
	m_pStartStation = startStation;
	m_pTrain = train;
}
