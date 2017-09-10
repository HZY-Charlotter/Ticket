#pragma once
//  车站站点数据结构
#ifndef Station_h
#define Station_h

#include <iostream>
#include <string>

using namespace std;

class Station//车站
{
public:
	Station(int stationID, string stationName, float distanceToNextStation, Station* nextStation);

	int m_iStationID;  //站点ID
	string m_strStationName; //站点名字
	float m_fDistanceToNextStation; //到下 一站距离
	float m_fPriceToNextStation; //到下个站点价钱
	Station* m_pNextStation;  //下一个站点
};

#endif