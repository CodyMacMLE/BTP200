#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "person.h"

using namespace std;
namespace lectures
{
	void Person::setEmpty()
	{
		m_height = -1;
		m_name[0] = '\0';
	}

	bool Person::isEmpty() const
	{
		return m_height == -1 && m_name[0] == '\0';
	}

	void Person::display(const Person& thePerson) const
	{
		//Checking if in empty state
		if (isEmpty()) 
		{
			// Is in empty state
			cout << "Empty Object: Nothing to print" << endl;
		}
		else
		{
			// Object is good
			cout << "Name   [" << m_name << "]\n";
			cout << "Height [" << m_height << "]\n";
		}
	}

	void Person::set()
	{
		bool done = false;
		
		cout << "Enter a Name:";
		cin >> m_name;

		while (!done)
		{
			cout << "Enter a Height (cm): ";
			cin >> m_height;
			if (m_height > 0 && m_height <= 300)
			{
				done = true;
			}
			else
			{
				cout << "Error: Invalid Height (Out of Bounds)" << endl;
			}
		}
	}

	void Person::set(const char* name, int height)
	{
		if (height > 0 && height <= 300)
		{
			strcpy(m_name, name);
			m_height = height;
		}
		else
		{
			setEmpty();
		}
	}
}