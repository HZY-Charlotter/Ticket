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
	Buyer(string name, long long id);
	bool sameBuyer(Buyer* buyer);
	//���ص�ǰbuyer����ε�buyer�Ƿ�ͬһ����
	//Ҳ�������� == �����ʵ��
	string m_strName;  //����������
	long long  m_iId;       //���������֤��
};

#endif