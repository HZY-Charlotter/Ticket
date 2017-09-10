#pragma once
#ifndef RemainedTicketsInfo_h
#define RemainedTicketsInfo_h

#include "Station.h"
#include "stdafx.h"


class RemainedTicketsInfo //余票信息
{
public:
	RemainedTicketsInfo(Station* startStation, Station* endStation, unsigned remainedTickets);

	Station* m_pStartStation;//起始站点
	Station* m_pEndStation;//终点站
	unsigned m_uRemainedTickets;//剩余票数
	float m_fPrice;//价格
	float m_fDistance;//总里程
};

#endif