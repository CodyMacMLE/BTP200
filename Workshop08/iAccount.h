#ifndef SENECA_IACCOUNT_H
#define SENECA_IACCOUNT_H
#include <iostream>
namespace seneca 
{
	class iAccount
	{
	public:
		/// <summary>
		/// adds a positive amount to the account balance
		/// </summary>
		/// <param name="amount">amount</param>
		/// <returns></returns>
		virtual bool credit(double) = 0;

		/// <summary>
		/// subtracts a positive amount from the account balance
		/// </summary>
		/// <param name="amount">amount</param>
		/// <returns></returns>
		virtual bool debit(double) = 0;

		/// <summary>
		/// applies month-end transactions to the account
		/// </summary>
		virtual void monthEnd() = 0;

		/// <summary>
		/// inserts account information into an ostream object
		/// </summary>
		/// <param name="out">out stream</param>
		virtual void display(std::ostream&) const = 0;

		/// <summary>
		/// Deallocates memory
		/// </summary>
		virtual ~iAccount() = 0;
	};
	/// <summary>
	/// receives a C-style string identifying the type of account and the initial account balance, creates the account with the starting balance and returns its address.
	/// </summary>
	iAccount* CreateAccount(const char* str, double balance);
}
#endif //SENECA_IACCOUNT_H