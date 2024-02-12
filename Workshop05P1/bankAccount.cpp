#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cmath>
#include "bankAccount.h"

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
		char tmp[30];
		if (*this)
		{
			strcpy(tmp, m_userName);
		}
		else
		{
			strcpy(tmp, "Not Open");
		}
		return tmp;
	}
}