#include <iostream>
#include <iomanip>
#include "SavingsAccount.h"

namespace seneca
{
	SavingsAccount::SavingsAccount(double balance, double interestRate) :
		Account(balance)
	{
		this->m_interestRate = interestRate;
	}

	void SavingsAccount::monthEnd()
	{
		this->credit(this->balance() * m_interestRate);
	}

	void SavingsAccount::display(std::ostream& out) const
	{
		out << "Account Type: Savings\nBalance: $";
		out << std::setprecision(2) << std::fixed << this->balance() << std::endl;
		out << "Interest Rate (%): " << this->m_interestRate * 100 << std::endl;
		out << std::setprecision(2);
	}
}