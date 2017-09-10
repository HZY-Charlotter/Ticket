#pragma once
#ifndef Line_h
#define Line_h

#include <iostream>
#include <string>
#include "stdafx.h"
#include "Station.h"
#include "Train.h"

using namespace std;

class Line //��·
{
public:
	Line(string lineName, int lineID, Station* startStation, Train* train);

	string m_strLineName; //��·����
	int m_iLineID;   //��·ID
	Station* m_pStartStation;  //��ʼվ��
	Train* m_pTrain; //������Ϣ
};

#endif