#include <iostream>
#include <cstring>
#include "bankAccount.h"

using namespace std;
namespace seneca {

	BankAccount::BankAccount(const char* name = "", bool checking)
	{
		if (name != nullptr || name[0] != '\0')
			strcpy(m_userName, name);
		m_userName[0] = '\0';
		m_balance = 0.0;
		m_checking = checking;
	}

	void BankAccount::display()
	{

	}
}