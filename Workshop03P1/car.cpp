#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include "car.h"

using namespace std;
namespace seneca {

	bool Car::isEmpty() const
	{
		bool exitFlag = false;
		if (m_makeModel == nullptr)
		{
			exitFlag = true;
		}
		return exitFlag;
	}

	void Car::setEmpty()
	{
		m_licencePlate[0] = '\0';
		m_makeModel = nullptr;
		m_problemDesc = nullptr;
		m_cost = 0;
		m_objectStatus = INVALID_REASON__EMPTY;
	}

	void Car::set(const char* plateNo, const char* model, const char* desc, double serviceCost)
	{
		deallocateMemory();
		if (plateNo == nullptr || plateNo[0] == '\0')
			m_objectStatus = INVALID_REASON__PLATE;
		else if (model == nullptr || model[0] == '\0')
			m_objectStatus = INVALID_REASON__MODEL;
		else if (desc == nullptr || desc[0] == '\0')
			m_objectStatus = INVALID_REASON__DESC;
		else
		{
			strncpy(m_licencePlate, plateNo, sizeof(char) * 9);

			m_makeModel = new char[strlen(model) + 1];
			strcpy(m_makeModel, model);

			m_problemDesc = new char[strlen(desc) + 1];
			strcpy(m_problemDesc, desc);

			m_cost = serviceCost;

			m_objectStatus = VALID_OBJECT;
		}
	}

	void Car::display() const
	{ 
		if (m_objectStatus == VALID_OBJECT)
		{
			cout << "| ";
			cout.fill(' ');
			cout.width(8);
			cout << m_licencePlate << " | ";
			cout.fill('.');
			cout.width(20);
			cout << left << m_makeModel << " | ";
			cout.width(40);
			cout << right << m_problemDesc << " | ";
			cout.width(8);
			cout.setf(ios::fixed);
			cout.precision(2);
			cout << m_cost << " |";
		}
		else
		{
			cout << "| ";
			cout.fill(' ');
			cout.width(85);
			cout << left << m_objectStatus << " |" << right;
		}
		cout.fill('*');
		cout.unsetf(ios::fixed);
		cout.precision(6);
	}

	void Car::deallocateMemory()
	{
		delete[] m_makeModel;
		delete[] m_problemDesc;
		setEmpty();
	}
}
