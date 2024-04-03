#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Book.h"

namespace seneca {

	Book::Book(const char* title, int year, const char* author) : LibraryItem(title, year)
	{
		if (author != nullptr || author[0] != '\0')
		{
			m_author = new char[strlen(author) + 1];
			strcpy(m_author, author);
		}
		else
			m_author = nullptr;
	}

	Book::Book(const Book& that)
	{
		m_author = nullptr;
		*this = that;
	}

	Book::~Book()
	{
		delete[] m_author;
	}

	Book& Book::operator= (const Book& that)
	{
		// 1. Check for self-assignment
		if (this != &that)
		{
			// 2. Copy base class
			(LibraryItem&)*this = that; // not calling constructor properly
			
			// 3. Clean up
			delete[] m_author;

			// 4. Shallow copy (none)

			// 5. Deep copy
			if (that.m_author != nullptr)
			{
				m_author = new char[strlen(that.m_author) + 1];
				strcpy(m_author, that.m_author);
			}
			else
				m_author = nullptr;
		}
		return *this;
	}

	std::ostream& Book::display(std::ostream& ostr) const
	{
		this->LibraryItem::display(ostr);
		std::cout << "\nAuthor: " << m_author;
		return ostr;
	}

	bool Book::operator>(const Book& that) const
	{
		bool exitFlag = false;
		if (m_author != nullptr)
		{
			if (strcmp(m_author, that.m_author) > 0)
				exitFlag = true;
		}
		return exitFlag;
	}
	/*
	bool operator>(const Book& other)const 
	- This method checks for non-null author names and checks to see if the object's author 
	  name is lexicographically greater than the other object's author name (use std::strcmp())
	- It returns true; otherwise, it returns false.
	*/
}