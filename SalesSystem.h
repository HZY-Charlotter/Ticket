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

class SalesSystem //售票系统
{
public:
	Line* m_pLine;

	RemainedTicketsInfo* searchRemainedTickesInfo(Station* startStation, Station* endStation);
	//查询余票功能
	//param startStation 起始站
	//param endStation 终点站
	//return 余票信息

	Ticket* buyTicket(Buyer* buyer, Station* startStation, Station* endStation);
	//购票功能
	//param buyer 购买者
	//param startStation 起始站点
	//param endStation 重点
	//return 购买的票

	vector<Ticket*> searchTickesInfo(Buyer* buyer);
	//搜索购票历史
	//param buyer 购票者信息，允许只传入名字或者只传入ID
	//return 购票者购买的所有的票
	
	vector<Ticket*> refoundTickets(Buyer* buyer);
	//退票，传入购票者信息，将购票者名下所有票都退票

	//param buyer 购票者信息，允许只传入名字或者只传入ID
	//return 所有退的票
	
	Station* stationWithIndex(int index);
	//查找对应index的station
	//param index station 的index
	//return station

	SalesSystem();
	~SalesSystem();

private:
	Train* setupTrain();
	Station* setupStation();
	vector<Ticket*> ticketHistory; //购票历史

	bool startStationWithIn(Station*searchStartStation, Station*searchEndStation, Station* startStation, Station* endStation);
	// 传入的车站是否在起终点范围内
	//param searchStartStation 要搜索的起点车站
	//param searchEndStation 要搜索的终点车站
	//param startStation 起点车站
	//param endStation 终点车站
	//return 是否在起终点车站范围内

	vector<Ticket*> loadTicketFromFile();
	//从文件中读取购票历史
	//return 购票历史

	bool saveTicketToFile();
	//向文件保存购票历史
	//return 是否保存成功
};
#endif