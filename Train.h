#pragma once
#ifndef Train_h
#define Train_h

#include <iostream>
#include <string>

using namespace std;

class Train //火车
{
public:
	Train(string trainName, int trainID, unsigned totalSeat);

	string m_strTrainName;  //火车名字
	int m_iTrainID;       //火车ID
	unsigned m_uTotalSeat; //总坐席
};

#endif