#pragma once
#ifndef Buyer_h
#define Buyer_h

#include <iostream>
#include "stdafx.h"
#include <string>

using namespace std;

class Buyer //������
{
public:
	Buyer(string name, int id);

	string m_strName;  //����������
	int m_iId;       //���������֤��
};

#endif