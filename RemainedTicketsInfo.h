#pragma once
#ifndef RemainedTicketsInfo_h
#define RemainedTicketsInfo_h

#include "Station.h"
#include "stdafx.h"


class RemainedTicketsInfo //��Ʊ��Ϣ
{
public:
	RemainedTicketsInfo(Station* startStation, Station* endStation, unsigned remainedTickets);

	Station* m_pStartStation;//��ʼվ��
	Station* m_pEndStation;//�յ�վ
	unsigned m_uRemainedTickets;//ʣ��Ʊ��
	float m_fPrice;//�۸�
	float m_fDistance;//�����
};

#endif