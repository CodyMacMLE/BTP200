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
		if (amount > 0) // might need to include 0, unknown at the moment
		{
			m_balance += amount;
			exitFlag = true;
		}
		return exitFlag;
	}
}
