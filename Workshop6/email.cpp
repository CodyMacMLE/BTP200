#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
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
		in.istream::getline(this->m_fromAddress,100, ',');
		in.istream::getline(this->m_fromName,100, ',');
		in.istream::getline(buffer,20, ',');
		in.istream::getline(this->m_dateReceived,1000);
		if (in.istream::good())
		{
			int bufferSize = 0;
			delete[] this->m_subject;
			for (auto i = 0; buffer[i] != '\0'; ++i)
			{
				++bufferSize;
			}
			this->m_subject = new char[bufferSize + 1];
			strcpy(this->m_subject, buffer);
		}
		else
		{
			this->m_fromAddress[0] = '\0';
			this->m_fromName[0] = '\0';
			this->m_dateReceived[0] = '\0';
			delete[] this->m_subject;
			this->m_subject = nullptr;
		}
	}

	char* Email::getTime() const
	{
		char time[9];
		int timePosition = 0;
		for (auto i = 11; i < strlen(m_dateReceived); ++i)
		{
			time[timePosition] = m_dateReceived[i];
			++timePosition;
		}
		return time;
	}

	std::ostream& operator <<(std::ostream& out, const Email email)
	{
		if (email.m_subject != nullptr)
		{
			ios init(NULL);
			init.copyfmt(out); // Copies defaut cout formatting 

			out.width(20);
			out << right << email.m_fromName << "  ";
			out.width(40);
			out << left << email.m_fromAddress << "  ";
			out.width(15);
			out << left << email.getTime() << "  ";
			out.copyfmt(init); // restoring default format
			out << email.m_subject << endl;
		}
		return out;
	}

}