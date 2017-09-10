#pragma once
#ifndef Line_h
#define Line_h

#include <iostream>
#include <string>
#include "stdafx.h"
#include "Station.h"
#include "Train.h"

using namespace std;

class Line //线路
{
public:
	Line(string lineName, int lineID, Station* startStation, Train* train);

	string m_strLineName; //线路名字
	int m_iLineID;   //线路ID
	Station* m_pStartStation;  //起始站点
	Train* m_pTrain; //车辆信息
};

#endif