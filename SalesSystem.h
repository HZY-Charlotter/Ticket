#pragma once
#ifndef SalesSystem_h
#define SalesSystem_h

#include <iostream>
#include <vector>
#include "Line.h"
#include "Ticket.h"
#include "Station.h"
#include "Train.h"
#include "Buyer.h"
#include "RemainedTicketsInfo.h"

class SalesSystem //��Ʊϵͳ
{
public:
	Line* m_pLine;
	vector<Ticket*> tickets;

	/*
	��ѯ��Ʊ����

	param startStation ��ʼվ
	param endStation �յ�վ
	return ��Ʊ��Ϣ
	*/
	RemainedTicketsInfo* searchRemainedTickesInfo(Station* startStation, Station* endStation);

	/*
	��Ʊ����

	param buyer ������
	param startStation ��ʼվ��
	param endStation �ص�
	return �����Ʊ
	*/
	Ticket* buyTicket(Buyer* buyer, Station* startStation, Station* endStation);

	/*
	������Ʊ��ʷ

	param buyer ��Ʊ����Ϣ������ֻ�������ֻ���ֻ����ID
	return ��Ʊ�߹�������е�Ʊ
	*/
	vector<Ticket*> searchTickesInfo(Buyer* buyer);

	/*
	��Ʊ�����빺Ʊ����Ϣ������Ʊ����������Ʊ����Ʊ

	param buyer ��Ʊ����Ϣ������ֻ�������ֻ���ֻ����ID
	return ��Ʊ�Ƿ�ɹ�
	*/
	bool refoundTickets(Buyer* buyer);

	/*
	���Ҷ�Ӧindex��station
	param index station ��index
	return station
	*/
	Station* stationWithIndex(int index);

	SalesSystem();
private:
	Train* setupTrain();
	Station* setupStation();};
#endif