// Cody MacDonald
// cmacdonald33@myseneca.ca
// 159702232
// March 13th, 2024
#ifndef SENECA_BANKACCOUNT_H
#define SENECA_BANKACCOUNT_H
#include "DepositUtility.h"

namespace seneca 
{
	class BankAccount
	{
		/// <summary>
		/// Owner of the account.
		/// </summary>
		char m_name[100 + 1];

		/// <summary>
		/// The date the account was opened.
		/// </summary>
		seneca::Date m_openDate;

		/// <summary>
		/// Holds bank info: instition name, transit code,account number, etc.
		/// </summary>
		seneca::DepositInfo m_depInfo;

		/// <summary>
		/// The amount of money accessible to the owner in the account.
		/// </summary>
		double m_balance;
	
	protected:
		/// <summary>
		/// Accesses balance of account
		/// </summary>
		/// <returns>the balance of the account as a double</returns>
		double getBalance() const;

		/// <summary>
		/// Sets the balance of the account
		/// </summary>
		/// <param name="newBalance">The amount the balance is to be set to</param>
		void setBalance(double newBalance);

		/// <summary>
		/// a query method that inserts into the stream received as a first
		/// parameter a formatted dollar amount received as a second parameter
		/// </summary>
		/// <param name="out">a reference to an object of type std::ostream</param>
		/// <param name="amount">a floating-point number in double precision</param>
		void writeCurrency(std::ostream& out, double amount) const;

	public:
		/// <summary>
		/// Custom Constructor
		/// </summary>
		/// <param name="name">The address of a C-style array of characters 
		/// representing the name of the account holder</param>
		/// <param name="openDate">an object of type seneca::Date representing when the account was open</param>
		/// <param name="depInfo">an object of type seneca::DepositInfo containing some extra info about the account</param>
		/// <param name="balance">the amount of money that exists in the account</param>
		BankAccount(const char* name, const seneca::Date openDate, const seneca::DepositInfo depInfo, double balance);

		/// <summary>
		/// a query that inserts into the stream received as parameter the content of the current instance
		/// </summary>
		/// <param name="out">an unmodifiable reference to an object of type std::ostream</param>
		/// <returns>a reference of the ostream</returns>
		std::ostream& write(std::ostream& out) const;

		/// <summary>
		/// a mutator that reads data from the stream received as the first parameter and stores it in the current instance.
		/// </summary>
		/// <param name="in">an un-modifiable reference to an object of type std::istream</param>
		/// <returns>a reference of the istream</returns>
		std::istream& read(std::istream& in);
	};

	/// <summary>
	/// Overloaded extraction to read from a stream some data that is stored in a BankAccount object.
	/// </summary>
	/// <param name="in">a reference to an object of type std::istream</param>
	/// <param name="account">a reference to an object of type BankAccount.</param>
	/// <returns>std::istream as a reference</returns>
	std::istream& operator>> (std::istream& in, BankAccount& account);

	/// <summary>
	/// Overloaded insertion operator to insert an BankAccount object into the first parameter.
	/// </summary>
	/// <param name="out">a reference to an object of type std::ostream.</param>
	/// <param name="account">an un-modifiable reference to an object of type BankAccount</param>
	/// <returns>std::ostream as a reference</returns>
	std::ostream& operator<< (std::ostream& out, const BankAccount& account);
}
#endif // !SENECA_BANKACCOUNT_H

