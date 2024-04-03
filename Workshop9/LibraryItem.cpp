#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "LibraryItem.h"

namespace seneca {

	LibraryItem::LibraryItem()
	{
		m_title = nullptr;
		m_year = 0;
	}

	LibraryItem::LibraryItem(const char* title, int year)
	{
		LibraryItem();
		if (title != nullptr || title[0] != '\0')
		{
			m_title = new char[strlen(title) + 1];
			strcpy(m_title, title);
		}
		if (year >= 1400 && year < 2030)
			m_year = year;
	}

	LibraryItem::LibraryItem(const LibraryItem& that)
	{
		delete[] m_title;
		*this = that;
	}

	LibraryItem::~LibraryItem()
	{
		delete[] m_title;
	}

	LibraryItem& LibraryItem::operator= (const LibraryItem& that)
	{
		// 1. Check for self-assignment
		if (this != &that)
		{
			// 2. Clean-up
			delete[] m_title;

			// 3. Shallow copy
			m_year = that.m_year;

			// 4. Deep copy
			if (that.m_title != nullptr)
			{
				this->m_title = new char[strlen(that.m_title) + 1];
				strcpy(this->m_title, that.m_title);
			}
			else
				m_title = nullptr;
		}
		return *this;
	}

	std::ostream& LibraryItem::display(std::ostream& ostr) const
	{
		std::cout << "Title: " << m_title << " (" << m_year << ")";
		return ostr;
	}
}