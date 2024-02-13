#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cmath>
#include "bankAccount.h"

// Cody MacDonald
// cmacdonald33@myseneca.ca
// 159702232
// February 13th, 2024

using namespace std;
namespace seneca {

	BankAccount::BankAccount(const char* name, bool checking)
	{
		m_balance = 0.0;
		m_transactions = 0;
		m_checking = checking;
		if (name != NULL && name[0] != '\0')
		{
			strcpy(m_userName, name);
		}
		else
		{
			m_userName[0] = '\0';
		}
	}

	void BankAccount::display() const
	{
		if (*this)
			cout << m_userName << " -> $" << m_balance << " in " << (m_checking ? "checking account." : "saving account.") << endl;
	}

	BankAccount::operator bool() const
	{
		bool exitFlag;
		m_userName[0] != '\0' ? exitFlag = true : exitFlag = false;
		return exitFlag;
	}

	BankAccount::operator double() const
	{
		double exitFlag;
		if (*this)
		{
			exitFlag = double(m_balance);
		}
		else
		{
			exitFlag = nan("");
		}
		return exitFlag;
	}

	BankAccount::operator const char* () const
	{
		return (*this) ? m_userName : "Not Open";
	}

	BankAccount::operator int() const
	{
		int exitFlag = -1;
		if (m_transactions > 0)
			exitFlag = m_transactions;
		return exitFlag;
	}

	BankAccount& BankAccount::operator+= (double amount)
	{
		if (*this)
		{
			m_balance += amount;
			++m_transactions;
		}
		return *this;
	}
	BankAccount& BankAccount::operator-= (double amount)
	{
		operator+=(amount * -1);
		return *this;
	}

	BankAccount BankAccount::operator+ (double amount) const
	{
		BankAccount result = *this;
		result += amount;
		return result;
	}

	BankAccount& BankAccount::operator++ ()
	{
		if (*this && m_balance > 0)
		{
			if (m_checking)
			{
				m_balance += (m_balance * 0.005);
			}
			else
			{
				m_balance += (m_balance * 0.025);
			}
		}
		return *this;
	}

	BankAccount BankAccount::operator++ (int)
	{
		BankAccount result = *this;
		++*this;
		return result;
	}

	bool BankAccount::operator> (double amount) const
	{
		bool exitFlag = false;
		if (*this)
		{
			exitFlag =  m_balance > amount;
		}
		return exitFlag;
	}

	bool operator> (double amount, BankAccount account)
	{
		bool exitFlag = false;
		if (account)
		{
			exitFlag = amount > double(account);
		}
		return exitFlag;
	}
}