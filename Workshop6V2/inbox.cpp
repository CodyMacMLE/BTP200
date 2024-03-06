#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include "inbox.h"

// Cody MacDonald
// cmacdonald33@myseneca.ca
// 159702232
// March 6th, 2024

using namespace std;
namespace seneca
{
	Inbox::Inbox()
	{
		this->m_emails = nullptr;
		this->m_cntEmails = 0;
	}

	Inbox::Inbox(const Inbox& that)
	{
		this->m_emails = nullptr;
		*this = that;
	}

	Inbox& Inbox::operator= (const Inbox& that)
	{
		if (this != &that)
		{
			delete[] this->m_emails;
			this->m_cntEmails = that.m_cntEmails;

			if (that.m_emails != nullptr)
			{
				this->m_emails = new Email[this->m_cntEmails];
				for (auto i = 0; i < this->m_cntEmails; ++i)
					this->m_emails[i] = that.m_emails[i];
			}
			else
			{
				this->m_emails = nullptr;
			}
		}
		return *this;
	}

	Inbox::~Inbox()
	{
		delete[] this->m_emails;
	}


	Inbox& Inbox::operator+= (const Email& email)
	{
		Email* tmp = new Email[m_cntEmails + 1];
		for (auto i = 0; i < m_cntEmails; ++i)
			tmp[i] = this->m_emails[i];
		tmp[m_cntEmails] = email;
		++(this->m_cntEmails);

		delete[] this->m_emails;
		this->m_emails = tmp;
		return *this;
	}

	Inbox Inbox::operator+ (const Email& email) const
	{
		Inbox tmp = *this;
		tmp += email;
		return tmp;
	}

	void Inbox::load(const char* filename)
	{
		if (filename != nullptr)
		{
			ifstream file(filename);
			if (file.is_open())
			{
				while (file)
				{
					Email tmp;
					tmp.load(file);
					*this += tmp;
				}
				file.close();
			}
		}
	}

	void Inbox::save(const char* filename) const
	{
		if (filename != nullptr)
		{
			ofstream file(filename);
			if (file.is_open())
			{
				for (auto i = 0; i < this->m_cntEmails; ++i)
					file << m_emails[i];
			}
			file.close();
		}
	}

	std::ostream& operator<< (std::ostream& out, const Inbox inbox)
	{
		for (auto i = 0; i < inbox.m_cntEmails; ++i)
			out << inbox.m_emails[i];
		return out;
	}
}