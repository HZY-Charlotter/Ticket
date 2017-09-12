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

	RemainedTicketsInfo* searchRemainedTickesInfo(Station* startStation, Station* endStation);
	//��ѯ��Ʊ����
	//param startStation ��ʼվ
	//param endStation �յ�վ
	//return ��Ʊ��Ϣ

	Ticket* buyTicket(Buyer* buyer, Station* startStation, Station* endStation);
	//��Ʊ����
	//param buyer ������
	//param startStation ��ʼվ��
	//param endStation �ص�
	//return �����Ʊ

	vector<Ticket*> searchTickesInfo(Buyer* buyer);
	//������Ʊ��ʷ
	//param buyer ��Ʊ����Ϣ������ֻ�������ֻ���ֻ����ID
	//return ��Ʊ�߹�������е�Ʊ
	
	vector<Ticket*> refoundTickets(Buyer* buyer);
	//��Ʊ�����빺Ʊ����Ϣ������Ʊ����������Ʊ����Ʊ

	//param buyer ��Ʊ����Ϣ������ֻ�������ֻ���ֻ����ID
	//return �����˵�Ʊ
	
	Station* stationWithIndex(int index);
	//���Ҷ�Ӧindex��station
	//param index station ��index
	//return station

	SalesSystem();
	~SalesSystem();

private:
	Train* setupTrain();
	Station* setupStation();
	vector<Ticket*> ticketHistory; //��Ʊ��ʷ

	bool startStationWithIn(Station*searchStartStation, Station*searchEndStation, Station* startStation, Station* endStation);
	// ����ĳ�վ�Ƿ������յ㷶Χ��
	//param searchStartStation Ҫ��������㳵վ
	//param searchEndStation Ҫ�������յ㳵վ
	//param startStation ��㳵վ
	//param endStation �յ㳵վ
	//return �Ƿ������յ㳵վ��Χ��

	vector<Ticket*> loadTicketFromFile();
	//���ļ��ж�ȡ��Ʊ��ʷ
	//return ��Ʊ��ʷ

	bool saveTicketToFile();
	//���ļ����湺Ʊ��ʷ
	//return �Ƿ񱣴�ɹ�
};
#endif