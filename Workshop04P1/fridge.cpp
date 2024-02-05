#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "fridge.h"

// Cody MacDonald
// cmacdonald33@myseneca.ca
// 159702232
// February 4th, 2024

namespace seneca {
	Fridge::Fridge() 
	{
		m_capacity = 10;
		m_model = nullptr;
		m_foods = nullptr;
		m_cntFoods = 0;
	}

	Fridge::Fridge(const char* model, int capacity) // Not Initializing, check strcpy in setFridge (no dynamic allocation in this one)
	{
		*this = Fridge();
		if (model[0] != '\0' && model != nullptr && capacity > 9)
		{
			m_capacity = capacity;
			strcpy(m_model, model);
			m_foods = nullptr;
			m_cntFoods = 0;
		}
	}
	
	Fridge::Fridge(Food* foods, int cntFoods, const char* model, int capacity) // Not Initializing
	{
		*this = Fridge();
		if (model[0] != '\0' && model != nullptr && capacity > 9 && foods != nullptr && cntFoods !=0)
		{
			m_capacity = capacity;
			strcpy(m_model, model);
			m_foods = foods;
			m_cntFoods = cntFoods;
		}
	}

	Fridge::~Fridge()
	{
		delete[] this->m_foods;
		delete[] this->m_model;
	}

	int Fridge::getContentWeight() const
	{
		int weightSum = 0;
		for (int i = 0; i < m_cntFoods; i++)
		{
			weightSum += m_foods[i].m_weight;
		}
		return weightSum;
	}

	bool Fridge::addFood(Food aFood)
	{
		bool exitFlag = false;
		if ((getContentWeight() + aFood.m_weight) < m_capacity)
		{
			Food* tmp = new Food[m_cntFoods + 1];

			for (int i = 0; i < m_cntFoods; i++)
				tmp[i] = m_foods[i];

			tmp[m_cntFoods] = aFood;

			delete[] m_foods;
			m_foods = tmp;

			m_cntFoods++;
			exitFlag = true;
		}
		return exitFlag;
	}

	void Fridge::setModel(const char* model, int capacity)
	{
		if (model != nullptr && model[0] != '\0' && capacity > 9)
		{
			delete[] m_model;
			m_model = new char[strlen(model) + 1];
			strcpy(m_model, model);
			m_capacity = capacity;
		}
	}

	bool Fridge::isFull() const
	{
		bool exitFlag = false;
		if (getContentWeight() >= (m_capacity * 0.9))
		{
			exitFlag = true;
		}
		return exitFlag;
	}

	bool Fridge::hasFood(const char* theFood) const       // All = true
	{
		bool exitFlag = false;
		if (m_cntFoods > 0)
		{
			exitFlag = true;
		}
		else
		{
			for (int i = 0; i < m_cntFoods; i++)
			{
				if (strcmp(m_foods[i].m_name, theFood))
					exitFlag = true;
			}
		}
		return exitFlag;
	}

	std::ostream& Fridge::display(std::ostream& out) const
	{
		if (m_model == nullptr)
			out << "The fridge object is in an empty state.\n";
		else
		{
			out << "     Fridge model: " << m_model << std::endl;
			out << "  Fridge capacity: " << m_capacity << "kg" << std::endl;
			out << "  Fill percentage: " << 100 * (double(getContentWeight()) / m_capacity) << "% full" << std::endl;
			out << "The list of foods:" << std::endl;
			for (int i = 0; i < m_cntFoods; i++)
				out << "  - " << m_foods[i].m_name << " (" << m_foods[i].m_weight << "kg)" << std::endl;
		}
		return out;
	}
}