// Cody MacDonald
// cmacdonald33@myseneca.ca
// 159702232
// March 13th, 2024
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
#include "DepositUtility.h"
#include "BankAccount.h"

namespace seneca
{
	BankAccount::BankAccount(const char* name, const seneca::Date openDate, const seneca::DepositInfo depInfo, double balance)
	{
		std::strcpy(this->m_name, name);
		this->m_openDate = openDate;
		this->m_depInfo = depInfo;
		m_balance = balance;
	}

	double BankAccount::getBalance() const
	{
		return this->m_balance;
	}

	void BankAccount::setBalance(double newBalance)
	{
		this->m_balance = newBalance;
	}

	void BankAccount::writeCurrency(std::ostream& out, double amount) const
	{
		out << std::fixed << std::setprecision(2) << "$" << amount;
		out << std::setprecision(6);
	}

	std::ostream& BankAccount::write(std::ostream& out) const // const / reference is causing issues
	{
		out <<  ">> " << this->m_name << " | ";
		this->writeCurrency(out, this->m_balance);
		out << " | " << this->m_openDate << " | " << this->m_depInfo;
		return out;
	}

	std::istream& BankAccount::read(std::istream& in)
	{
		std::cout << "Name: ";
		in.getline(this->m_name, 101, '\n');
		std::cout << "Opening Balance: ";
		in >> this->m_balance;
		std::cout << "Date Opened ";
		in >> this->m_openDate;
		in >> this->m_depInfo;
		return in;
	}

	std::ostream& operator<< (std::ostream& out, const BankAccount& account)
	{
		return account.BankAccount::write(out);
	}

	std::istream& operator>> (std::istream& in, BankAccount& account)
	{
		return account.BankAccount::read(in);
	}
}