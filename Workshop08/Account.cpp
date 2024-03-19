#include "Account.h"

namespace seneca
{
	Account::Account(double balance)
	{
		if (balance > 0.0)
		{
			m_balance = balance;
		}
		else
		{
			m_balance = 0.0;
		}
	}

	bool Account::credit(double amount)
	{
		bool exitFlag = false;
		if (amount > 0)
		{
			m_balance += amount;
			exitFlag = true;
		}
		return exitFlag;
	}

	bool Account::debit(double amount)
	{
		bool exitFlag = false;
		if (amount > 0)
		{
			m_balance -= amount;
			exitFlag = true;
		}
		return exitFlag;
	}

	double Account::balance() const
	{
		return this->m_balance;
	}
}
