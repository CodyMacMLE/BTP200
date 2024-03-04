#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "pet.h"

using namespace std;

namespace lectures {

	Pet::Pet()
	{
		cout << "The Pet object at [" << this << "] == open" << endl;
		m_location = 0;
		m_speed = 0;
		strcpy(m_name, "EMPTY STATE");
	}
	Pet::Pet(const char* name)
	{
		*this = Pet();
		if (name != nullptr || name[0] != '\0')
			strcpy(m_name, name);
	}
	Pet::Pet(const char* name, int location, int speed)
	{
		*this = Pet(name);
		m_location = location;
		if (speed > 0)
			m_speed = speed;
	}
	Pet::~Pet()
	{
		cout << "The Pet object at [" << this << "] == closed" << endl;
	}
	void Pet::display() const
	{
		cout << "[" << m_name << "] is at [" << m_location << "] from where it started!" << endl;
		cout << "\tIt\'s speed is [" << m_speed << "] cm/s." << endl;
	}
	void Pet::move(int distance)
	{
		m_location += distance;
	}
	void Pet::setSpeed(int speed)
	{
		if (speed > 0)
			this->m_speed = speed;
	}

	void Pet::setName(const char* name)
	{
		strcpy(m_name, name);
	}
}
