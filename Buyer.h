#pragma once
#ifndef Buyer_h
#define Buyer_h

#include <iostream>
#include "stdafx.h"
#include <string>

using namespace std;

class Buyer //购买者
{
public:
	Buyer(string name, long long id);
	bool sameBuyer(Buyer* buyer);
	//返回当前buyer和入参的buyer是否同一个人
	//也可以重载 == 运算符实现
	string m_strName;  //购买者名字
	long long  m_iId;       //购买者身份证号
};

#endif