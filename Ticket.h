#pragma once
#ifndef Ticket_h
#define Ticket_h

#include <iostream>
#include "Buyer.h"
#include "Station.h"

static int currentTicketID = 0;

class Ticket//车票
{
public:
	Ticket(Buyer* buyer, Station* startStation, Station* endStation);
	void print();

	Buyer* m_pBuyer; //购买者
	Station* m_pStartStation;//起始站点
	Station* m_pEndStation;//终点站
	int m_iTicketID; //票务ID
	float m_fPrice;//价格
	float m_fDistance;//总里程
};

#endif