// Cody MacDonald
// cmacdonald33@myseneca.ca
// 159702232
// March 13th, 2024
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include "DepositUtility.h"

namespace seneca
{
	Date::Date(int day, int month, int year)
	{
		m_day = day;
		m_month = month;
		m_year = year;
	}

	int Date::getDay() const
	{
		return m_day;
	}

	int Date::getMonth() const
	{
		return m_month;
	}

	int Date::getYear() const
	{
		return m_year;
	}

	void Date::write(std::ostream& out) const
	{
		char oldFill = out.fill('0');

		out << m_year << "-";
		out.width(2);
		out << m_month << "-";
		out.width(2);
		out << m_day;

		out.fill(oldFill);
	}

	void Date::read(std::istream& in, bool interractive)
	{
		if (interractive)
			std::cout << "(year-month-day): ";

		char delimiter = '\0';
		in >> m_year >> delimiter >> m_month >> delimiter >> m_day;
	}

	std::ostream& operator<<(std::ostream& out, const Date& dt)
	{
		dt.write(out);
		return out;
	}

	std::istream& operator>>(std::istream& in, Date& dt)
	{
		dt.read(in);
		return in;
	}


	DepositInfo::DepositInfo(const char* transit, const char* institution, const char* account)
	{
		strcpy(m_transit, transit);
		strcpy(m_institution, institution);
		strcpy(m_account, account);
	}

	const char* DepositInfo::getTransit() const
	{
		return m_transit;
	}

	const char* DepositInfo::getInstitution() const
	{
		return m_institution;
	}

	const char* DepositInfo::getAccount() const
	{
		return m_account;
	}

	void DepositInfo::write(std::ostream& out) const
	{
		out << m_transit << "," << m_institution << "," << m_account;
	}

	void DepositInfo::read(std::istream& in, bool interractive)
	{
		if (interractive)
			std::cout << "Transit #: ";
		in >> m_transit;

		if (interractive)
			std::cout << "Institution #: ";
		in >> m_institution;

		if (interractive)
			std::cout << "Account #: ";
		in >> m_account;
		in.ignore(10000, '\n');
	}

	std::ostream& operator<<(std::ostream& out, const DepositInfo& info)
	{
		info.write(out);
		return out;
	}

	std::istream& operator>>(std::istream& in, DepositInfo& info)
	{
		info.read(in);
		return in;
	}
}
