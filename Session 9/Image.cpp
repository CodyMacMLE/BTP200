#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Image.h"
using namespace std;
Image::Image() 
{
	cout << this << ": Image()\n";
	m_year = 0;
	m_author = nullptr;
}

Image::Image(const char* author, int year) 
{
	cout << this << ": Image(const char* author, int year)\n";
	m_year = year;
	m_author = new char[strlen(author) + 1];
	strcpy(m_author, author);
}

Image::Image(const Image& that)
{
	cout << this << ": Image(const Image& that)\n";
	m_author = nullptr;
	*this = that;
}

Image& Image::operator= (const Image& that)
{
	cout << this << ": Image& operator= (const Image& that)\n";
	// 1. Check self-assignment
	if (this != &that)
	{
		// 2. Deallocate dynamic memory
		delete[] this->m_author;

		// 3. Shallow copy
		this->m_year = that.m_year;

		// 4. Add dynamic memory (Deep copy)
		if (that.m_author != nullptr)
		{
			this->m_author = new char[strlen(that.m_author) + 1];
			strcpy(this->m_author, that.m_author);
		}
		else
		{
			m_author = nullptr;
		}
	}
	return *this;
}

Image::~Image() {
	cout << this << ": ~Image()\n";
	delete[] m_author;
}
