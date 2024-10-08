#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include "inbox.h"

// Cody MacDonald
// cmacdonald33@myseneca.ca
// 159702232
// February 14th, 2024

using namespace std;
namespace seneca {

	Inbox::Inbox()
	{
		m_emails = nullptr;
		m_cntEmails = 0;
	}

	Inbox::Inbox(Inbox& source)
	{
		m_emails = nullptr;
		*this = source;
	}

	Inbox& Inbox::operator= (Inbox& source)
	{
		if (this != &source)
		{
			delete[] this->m_emails;
			this->m_cntEmails = source.m_cntEmails;

			if (source.m_emails != nullptr)
			{
				this->m_emails = new Email[this->m_cntEmails];
				for (auto i = 0; i < this->m_cntEmails; ++i)
				{
					this->m_emails[i] = source.m_emails[i];
				}
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

	Inbox& Inbox::operator+= (const Email& source)
	{
		Inbox* tmp = new Inbox[m_cntEmails + 1];
		for (auto i = 0; i < m_cntEmails; ++i)
			tmp->m_emails[i] = m_emails[i];
		tmp->m_emails[m_cntEmails] = source;
		++m_cntEmails;

		delete[] m_emails;
		m_emails = tmp->m_emails;
		return *this;
	}

	Inbox& Inbox::operator+ (const Email& email) const
	{
		Inbox tmp = *this;
		tmp += email;
		return tmp;
	}

	void Inbox::load(const char* filename)
	{
		if (filename != null)
		{
			ifstream file;
			file.open(filename);
			if (file.is_open())
			{
				bool EOF = true;
				while (EOF)
				{
					Email tmp;
					char buffer[1220 + 1];
					file.ifstream::getline(buffer, 1220);
					EOF = tmp.load(buffer);
					this += tmp;
				}
				file.close()
			}
		}
	}

	void Inbox::save(const char* filename) const
	{
		if (filename != nullptr)
		{
			ofstream file;
			file.open(filename);
			if (file.is_open())
			{
				for (auto i = 0; i < this->m_cntEmails; ++i)
					fout << m_emails;
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