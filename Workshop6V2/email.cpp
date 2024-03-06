#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include "email.h"

// Cody MacDonald
// cmacdonald33@myseneca.ca
// 159702232
// March 6th, 2024

using namespace std;
namespace seneca
{
	Email::Email()
	{
		m_fromName[0] = '\0';
		m_fromAddress[0] = '\0';
		m_dateReceived[0] = '\0';
		m_subject = nullptr;
		m_cntSubject = 0;
	}

	Email::Email(const Email& that)
	{
		this->m_subject = nullptr;
		*this = that;
	}

	Email& Email::operator=(const Email& that)
	{
		if (this != &that)
		{
			delete[] this->m_subject;
			
			strcpy(this->m_fromName, that.m_fromName);
			strcpy(this->m_fromAddress, that.m_fromAddress);
			strcpy(this->m_dateReceived, that.m_dateReceived);
			this->m_cntSubject = that.m_cntSubject;

			if (that.m_subject != nullptr)
			{
				this->m_subject = new char[this->m_cntSubject + 1];
				for (int i = 0; i < m_cntSubject; ++i)
				{
					this->m_subject[i] = that.m_subject[i];
				}
				this->m_subject[m_cntSubject] = '\0';
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
		delete[] this->m_subject;
	}

	bool Email::load(std::istream& in)
	{
		bool exitFlag = false;
		char buffer[1000 + 1];
		in.istream::getline(this->m_fromAddress, 100, ',');
		in.istream::getline(this->m_fromName, 100, ',');
		in.istream::getline(buffer, 1000, ',');
		in.istream::getline(this->m_dateReceived, 20, '\n');
		if (in.good())
		{

			for (int i = 0; buffer[i] != '\0'; ++i)
			{
				++(this->m_cntSubject);
			}

			delete[] this->m_subject;
			this->m_subject = new char[this->m_cntSubject + 1];
			strcpy(this->m_subject, buffer);

			exitFlag = true;
		}
		else
		{
			this->m_fromAddress[0] = '\0';
			this->m_fromName[0] = '\0';
			this->m_dateReceived[0] = '\0';
			delete[] this->m_subject;
			this->m_subject = nullptr;
			this->m_cntSubject = 0;
		}
		return exitFlag;
	}

	std::ostream& operator<<(std::ostream& out, const Email& email)
	{
		if (email.m_subject != nullptr)
		{
			char time[9];
			int timePos = 0;
			for (int i = 11; i < 20; ++i)
			{
				time[timePos] = email.m_dateReceived[i];
				++timePos;
			}
			time[8] = '\0';

			ios init(NULL);
			init.copyfmt(out); // Copies defaut cout formatting 

			out.width(20);
			out << right << email.m_fromName << "  ";
			out.width(40);
			out << left << email.m_fromAddress << "  ";
			out.width(15);
			out << left << time << "  ";
			out.copyfmt(init); // restoring default format
			out << email.m_subject << endl;
		}
		return out;
	}
}