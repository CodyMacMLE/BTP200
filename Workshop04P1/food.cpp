#define _CRT_SECURE_NO_WARNINGS
#include <cstring> // for std::strcpy()
#include "food.h"

namespace seneca
{
	Food::Food()
	{
		m_weight = 0;
		m_name[0] = '\0';
	}

	Food::Food(const char* name, int weight)
	{
		std::strcpy(m_name, name);
		m_weight = weight;
	}
}
