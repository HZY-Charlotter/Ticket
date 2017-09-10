#include "stdafx.h"
#include "Train.h"
#include <string>

Train::Train(string trainName, int trainID, unsigned totalSeat)
{
	m_strTrainName = trainName;
	m_iTrainID = trainID;
	m_uTotalSeat = totalSeat;
}
