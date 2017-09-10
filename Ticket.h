#pragma once
#ifndef Ticket_h
#define Ticket_h

#include <iostream>
#include "Buyer.h"
#include "Station.h"

static int currentTicketID = 0;

class Ticket//��Ʊ
{
public:
	Ticket(Buyer* buyer, Station* startStation, Station* endStation);
	void print();

	Buyer* m_pBuyer; //������
	Station* m_pStartStation;//��ʼվ��
	Station* m_pEndStation;//�յ�վ
	int m_iTicketID; //Ʊ��ID
	float m_fPrice;//�۸�
	float m_fDistance;//�����
};

#endif