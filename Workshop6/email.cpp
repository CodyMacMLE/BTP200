#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "email.h"

// Cody MacDonald
// cmacdonald33@myseneca.ca
// 159702232
// February 14th, 2024

using namespace std;
namespace seneca {

	Email::Email()
	{
		m_fromName[0] = '\0';
		m_fromAddress[0] = '\0';
		strcpy(m_dateReceived, "0000-00-00 00:00:00");
		m_subject = nullptr;
	}

	Email::Email(Email& source)
	{
		m_subject = nullptr;
		*this = source;
	}

	Email& Email::operator =(const Email& source)
	{
		if (this != &source)
		{
			delete[] this->m_subject;
			strcpy(this->m_fromName, source.m_fromName);
			strcpy(this->m_fromAddress, source.m_fromAddress);
			strcpy(this->m_dateReceived, source.m_dateReceived);

			if (source.m_subject != nullptr)
			{
				this->m_subject = new char[m_subjectSize + 1];
				for (auto i = 0; i < m_subjectSize; ++i)
				{
					this->m_subject[i] = source.m_subject[i];
				}
			}
			else
			{
				this->m_subject = nullptr;
			}
		}
		return *this;
	}

	Email::~Email()
	{
		delete[] m_subject;
	}

	bool Email::load(std::istream& in)
	{
		char buffer[1000 + 1];
		istream::getline(in, buffer); // Unknown issue
	}

	std::ostream& operator <<(std::ostream& out, const Email email)
	{

	}

}