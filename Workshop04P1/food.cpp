#define _CRT_SECURE_NO_WARNINGS
#include <cstring> // for std::strcpy()
#include "food.h"

// Cody MacDonald
// cmacdonald33@myseneca.ca
// 159702232
// February 4th, 2024

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

	bool operator==(Food& lFood, Food& rFood)
	{
		return (strcmp(lFood.m_name, rFood.m_name) && (lFood.m_weight == rFood.m_weight)) ? true : false;
	}
}
