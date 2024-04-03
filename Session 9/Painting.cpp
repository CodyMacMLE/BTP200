#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Painting.h"
using namespace std;

Painting::Painting() // Since we call no Base constructor, the base class default constructor is called
{
	cout << this << ": Painting()\n";
	m_price = 0.0;
	m_title = nullptr;
}

Painting::Painting(const char* author, double price) :
	Image(author, 2024) // This call deals with the dynamic author array
{
	cout << this << ": Painting(const char* author, double price)\n";
	m_price = price;
	m_title = new char[18 + 1];
	strcpy(m_title, "Mona Lisa Improved");
}

Painting::~Painting()
{
	cout << this << ": ~Painting()\n";
	delete[] m_title; 
	// Note:* Base class destructor is called no need to call it here
}

// If compiler inserts a copy constructor:
//      then that constructor will call copy const from base class
// If programmer inserts a copy contructor:
//      programmer must choose which const from base class to call, otherwise default const from base is called
Painting::Painting(const Painting& that)
	// Image((Image&)that) 
	// calling copy constructor to copy dynamic memory from image { can be cast because Image(Painting) doesn't exist, but compiler converts anyways} 
	// to optimize we do not need this call as it is dealt with in operation=
{
	cout << this << ": Painting(const Painting& that)\n";
	m_title = nullptr;
	*this = that;
}

Painting& Painting::operator=(const Painting& that) 
{
	cout << this << ": Painting& operator=(const Painting& that)\n";
	// 1. Check self-assignment
	if (this != &that)
	{
		// 2. Copy base class
		(Image&)*this = that;

		// 3. Clean-up
		delete[] this->m_title;

		// 4. Shallow copy
		this->m_price = that.m_price;

		// 5. Deep copy
		if (that.m_title != nullptr) 
		{
			this->m_title = new char[strlen(that.m_title) + 1];
			strcpy(this->m_title, that.m_title);
		}
		else 
		{
			this->m_title = nullptr;
		}
	}
	return *this;
}