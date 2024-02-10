#ifndef SENECA_BANKACCOUNT_H
#define SENECA_BANKACCOUNT_H

namespace seneca {

	class BankAccount {
		/// <summary>
		/// The owner of the account: If empty the account is closed
		/// </summary>
		char m_userName[100 + 1];

		/// <summary>
		/// The ammount of money in the account
		/// </summary>
		double m_balance;

		/// <summary>
		/// True if is a checking account, false otherwise
		/// </summary>
		bool m_checking;

		/// <summary>
		/// The number of transactions made by the account (withdrawals and deposits)
		/// </summary>
		int m_transactions;

	public:
		/// <summary>
		/// Custom constructor to create a bank account
		/// </summary>
		/// <param name="name">Name of the account user</param>
		/// <param name="checking">True is the account is checking, false if it is savings</param>
		BankAccount(const char* name = "", bool checking);

		/// <summary>
		/// Displays the account info to screen
		/// </summary>
		void display();
	};

}

#endif // !SENECA_BANKACCOUNT_H