#pragma once
//  ��վվ�����ݽṹ
#ifndef Station_h
#define Station_h

#include <iostream>
#include <string>

using namespace std;

class Station//��վ
{
public:
	Station(int stationID, string stationName, float distanceToNextStation, Station* nextStation);

	int m_iStationID;  //վ��ID
	string m_strStationName; //վ������
	float m_fDistanceToNextStation; //���� һվ����
	float m_fPriceToNextStation; //���¸�վ���Ǯ
	Station* m_pNextStation;  //��һ��վ��
};

#endif