// Cody MacDonald
// cmacdonald33@myseneca.ca
// 159702232
// March 13th, 2024
#ifndef SENECA_SAVINGSACCOUNT_H
#define SENECA_SAVINGSACCOUNT_H
#include "BankAccount.h"
#include "DepositUtility.h"

namespace seneca
{
	class SavingsAccount : public BankAccount
	{
		/// <summary>
		/// as a floating-point number in double precision representing the interest rate that must be paid on the balance. 
		/// This is a number between 0 and 1 (this is the percentage the account gains in interest every month).
		/// </summary>
		double m_interest;

		/// <summary>
		/// an object of type seneca::Date that represents the date when the interest was last applied to the account.
		/// </summary>
		seneca::Date m_interestDate;

		/// <summary>
		/// a query method that inserts into the stream received as a first parameter the interest rate stored in the current instance.
		/// </summary>
		/// <param name="out">a reference to an object of type std::ostream</param>
		void writeInterest(std::ostream& out) const;
	public:

		/// <summary>
		/// a custom constructor 
		/// </summary>
		/// <param name="name">the address of a C-style array of characters representing the name of the account holder</param>
		/// <param name="openDate">an object of type seneca::Date representing when the account was open</param>
		/// <param name="depInfo">an object of type seneca::DepositInfo containing some extra info about the account</param>
		/// <param name="balance">the amount of money that exists in the account</param>
		/// <param name="interest">the interest for this account as a floating-point number in double precision</param>
		/// <param name="interestDate">an object of type seneca::Date representing when the date when the interest was last applied to the account.</param>
		SavingsAccount(const char* name, seneca::Date openDate, seneca::DepositInfo depInfo, double balance, double interest, seneca::Date interestDate);
		
		/// <summary>
		/// a mutator that increases the account balance by adding the interest 
		/// </summary>
		/// <param name="today">an unmodifiable reference to an object of type seneca::Date.</param>
		void applyInterest(seneca::Date today);

		/// <summary>
		/// a query that inserts into the stream received as parameter the content of the current instance 
		/// </summary>
		/// <param name="out">an unmodifiable reference to an object of type std::ostream.</param>
		/// <returns> a reference to an object of type std::ostream.</returns>
		std::ostream& write(std::ostream& out) const;

		/// <summary>
		/// a mutator that reads data from the stream received as the first parameter and stores it in the current instance. 
		/// </summary>
		/// <param name="in">an un-modifiable reference to an object of type std::istream</param>
		/// <returns>an un-modifiable reference to an object of type std::istream</returns>
		std::istream& read(std::istream& in);
	};
	/// <summary>
	/// overload the extraction to read from a stream some data that is stored in a SavingsAccount object. 
	/// </summary>
	/// <param name="in">a reference to an object of type std::istream</param>
	/// <param name="account">a reference to an object of type SavingsAccount.</param>
	/// <returns>a reference to an object of type std::istream</returns>
	std::istream& operator>> (std::istream& in, SavingsAccount& account);

	/// <summary>
	/// Overloaded the insertion operator to a SavingsAccount object into the first parameter.
	/// </summary>
	/// <param name="out">a reference to an object of type std::ostream.</param>
	/// <param name="account">an un-modifiable reference to an object of type SavingsAccount.</param>
	/// <returns>a reference to an object of type std::ostream</returns>
	std::ostream& operator<< (std::ostream& out, const SavingsAccount& account);
}
#endif // !SENECA_SAVINGSACCOUNT_H
