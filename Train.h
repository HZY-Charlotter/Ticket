#pragma once
#ifndef Train_h
#define Train_h

#include <iostream>
#include <string>

using namespace std;

class Train //��
{
public:
	Train(string trainName, int trainID, unsigned totalSeat);

	string m_strTrainName;  //������
	int m_iTrainID;       //��ID
	unsigned m_uTotalSeat; //����ϯ
};

#endif