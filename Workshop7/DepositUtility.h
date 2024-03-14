// Cody MacDonald
// cmacdonald33@myseneca.ca
// 159702232
// March 13th, 2024
#ifndef SENECA_DEPOSITUTILITY_H
#define SENECA_DEPOSITUTILITY_H

#include <iostream>

namespace seneca
{
	const unsigned int MAX_STRING_LEN = 100;
	class Date
	{
		int m_day{};
		int m_month{};
		int m_year{};

	public:
		Date() = default;
		Date(int day, int month, int year);

		// Added copy constructor for easier assignment in BankAccount.cpp
		//Date(const Date& that);

		int getDay() const;
		int getMonth() const;
		int getYear() const;

		void write(std::ostream& out) const;
		void read(std::istream& in, bool interractive = true);
	};

	class DepositInfo
	{
		char m_transit[MAX_STRING_LEN + 1]{};
		char m_institution[MAX_STRING_LEN + 1]{};
		char m_account[MAX_STRING_LEN + 1]{};

	public:
		DepositInfo() = default;
		DepositInfo(const char* transit, const char* institution, const char* account);

		const char* getTransit() const;
		const char* getInstitution() const;
		const char* getAccount() const;

		void write(std::ostream& out) const;
		void read(std::istream& in, bool interractive = true);
	};

	std::ostream& operator<<(std::ostream& out, const Date& dt);
	std::istream& operator>>(std::istream& in, Date& dt);

	std::ostream& operator<<(std::ostream& out, const DepositInfo& info);
	std::istream& operator>>(std::istream& in, DepositInfo& info);
}

#endif