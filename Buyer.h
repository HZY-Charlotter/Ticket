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
	Buyer(string name, int id);

	string m_strName;  //购买者名字
	int m_iId;       //购买者身份证号
};

#endif