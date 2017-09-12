#include "stdafx.h"
#include "Buyer.h"
#include <string>

Buyer::Buyer(string name, long long id)
{
	m_strName = name;
	m_iId = id;
}


//bool Buyer::sameBuyer(Buyer* buyer)
//{
//	if (buyer->m_strName == m_strName)
//	{
//		if (buyer->m_iId == m_iId)
//		{
//			return true;
//		}
//	}
//	return false;
//}

bool Buyer::sameBuyer(Buyer* buyer)
{
	if (buyer->m_strName == m_strName|| buyer->m_iId == m_iId)
		return true;
	else
		return false;
}
