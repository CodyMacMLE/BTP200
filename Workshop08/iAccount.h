#ifndef SENECA_IACCOUNT_H
#define SENECA_IACCOUNT_H
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
		virtual bool credit(double);

		/// <summary>
		/// subtracts a positive amount from the account balance
		/// </summary>
		/// <param name="amount">amount</param>
		/// <returns></returns>
		virtual bool debit(double);

		/// <summary>
		/// applies month-end transactions to the account
		/// </summary>
		virtual void MonthEnd();

		/// <summary>
		/// inserts account information into an ostream object
		/// </summary>
		/// <param name="out">out stream</param>
		virtual void display(std::ostream&) const;

		/// <summary>
		/// Deallocates memory
		/// </summary>
		virtual ~iAccount();

		/// <summary>
		/// receives a C-style string identifying the type of account and the initial account balance, creates the account with the starting balance and returns its address.
		/// </summary>
		friend iAccount* CreateAccount(const char*, double);
	};
}
#endif //SENECA_IACCOUNT_H