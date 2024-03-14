// Cody MacDonald
// cmacdonald33@myseneca.ca
// 159702232
// March 13th, 2024
#include <iostream>
#include <iomanip>
#include "SavingsAccount.h"

namespace seneca
{
	SavingsAccount::SavingsAccount(const char* name, seneca::Date openDate, seneca::DepositInfo depInfo, double balance, double interest, seneca::Date interestDate) : BankAccount(name, openDate, depInfo, balance)
	{
		this->m_interest = interest;
		this->m_interestDate = interestDate;
	}
	
	void SavingsAccount::writeInterest(std::ostream& out) const
	{
		out << std::setprecision(3) << std::fixed;
		out << this->m_interest << "%";
		out << std::setprecision(6);
	}

	void SavingsAccount::applyInterest(seneca::Date today)
	{
		// Keeping old variables to print to std::cout
		double principleAmt = this->BankAccount::getBalance();
		Date principleDate = this->m_interestDate;
		double interestAmt = principleAmt * this->m_interest;
		// Updating object variables
		this->BankAccount::setBalance((principleAmt + interestAmt));
		this->m_interestDate = today;
		// Printing Updates
		std::cout << "   ";
		BankAccount::writeCurrency(std::cout, principleAmt);
		std::cout << " + ";
		BankAccount::writeCurrency(std::cout, interestAmt);
		std::cout << " (";
		this->writeInterest(std::cout);
		std::cout << ") = ";
		BankAccount::writeCurrency(std::cout, this->BankAccount::getBalance());
		std::cout << " | " << principleDate << " => " << this->m_interestDate << std::endl;
	}

	std::ostream& SavingsAccount::write(std::ostream& out) const // const / reference is causing issues
	{
		this->BankAccount::write(out);
		out << " | ";
		this->writeInterest(out);
		out << " | " << this->m_interestDate;
		return out;
	}

	std::ostream& operator<< (std::ostream& out, const SavingsAccount& account)
	{
		return account.write(out);
	}

	std::istream& SavingsAccount::read(std::istream& in)
	{
		BankAccount::read(in);
		std::cout << "Interest Date ";
		in >> this->m_interestDate;
		std::cout << "Interest Rate: ";
		in >> this->m_interest;
		return in;
	}

	std::istream& operator>> (std::istream& in, SavingsAccount& account)
	{
		return account.read(in);
	}
}