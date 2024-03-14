// Cody MacDonald
// cmacdonald33@myseneca.ca
// 159702232
// March 13th, 2024
#include <iostream>
#include <cstring>

#include "SavingsAccount.h"
#include "SavingsAccount.h"
#include "BankAccount.h"
#include "BankAccount.h"
#include "DepositUtility.h"
#include "DepositUtility.h"

int cout = 0; // prevents compilation if headers don't follow convention

void printHeader(std::ostream& out, const char* title, const char* values = nullptr);

int main()
{
	std::cout << "SENECA Banking System" << std::endl << std::endl;

	// Test the base "BankAccount" class.
	::printHeader(std::cout, "[#1] Bank Account (Constructors)");

	seneca::Date bankDate(19, 5, 2023);
	seneca::DepositInfo bankDep("04853", "001", "0037857");
	seneca::BankAccount bankAcct("Jane Doe", bankDate, bankDep, 0.0f);

	std::cout << bankAcct << std::endl << std::endl;

	::printHeader(std::cout, "[#2] Bank Account (I/O)", "John Evans\n100.25\n2022-12-6\n01234\n002\n0012345");
	std::cin >> bankAcct;
	std::cout << bankAcct << std::endl << std::endl;


	// Test the base "SavingsAccount" class.
	::printHeader(std::cout, "[#3] Savings Account (Constructors)");

	seneca::Date savDate(19, 5, 2023);
	seneca::Date interestDate = savDate;
	seneca::DepositInfo savDep("04853", "001", "0037857");
	seneca::SavingsAccount savAcct("Frank Wilson", savDate, savDep, 99.5f, 0.055f, interestDate);

	std::cout << savAcct << std::endl;

	interestDate = seneca::Date(interestDate.getDay(), interestDate.getMonth() + 1, interestDate.getYear());
	savAcct.applyInterest(interestDate);

	interestDate = seneca::Date(interestDate.getDay(), interestDate.getMonth() + 1, interestDate.getYear());
	savAcct.applyInterest(interestDate);

	std::cout << savAcct << std::endl << std::endl;

	::printHeader(std::cout, "[#4] Savings Account (I/O)", "Olivia Wright\n555.55\n2023-2-10\n54321\n003\n1122334\n2023-3-1\n0.047");
	std::cin >> savAcct;
	std::cout << savAcct << std::endl;

	interestDate = seneca::Date(10, 2, 2015);
	savAcct.applyInterest(interestDate);

	interestDate = seneca::Date(interestDate.getDay(), interestDate.getMonth() + 1, interestDate.getYear());
	savAcct.applyInterest(interestDate);

	std::cout << savAcct << std::endl << std::endl;

	std::cout << "-- END --" << std::endl;

	return cout;
}

void printHeader(std::ostream& out, const char* title, const char* values)
{
	if (values)
	{
		out << "Enter the following values when prompted:"
			<< std::endl
			<< values
			<< std::endl
			<< "------------------------------" << std::endl;
	}
	char oldFill = out.fill('-');

	out << title << std::endl;
	out.width(std::strlen(title));
	out << "" << std::endl;

	out.fill(oldFill);
}
