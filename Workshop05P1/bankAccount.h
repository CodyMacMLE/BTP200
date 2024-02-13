#ifndef SENECA_BANKACCOUNT_H
#define SENECA_BANKACCOUNT_H

// Cody MacDonald
// cmacdonald33@myseneca.ca
// 159702232
// February 13th, 2024

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
		BankAccount(const char* name = "", bool checking = false);

		/// <summary>
		/// Displays the account info to screen
		/// </summary>
		void display() const;

		/// <summary>
		/// Converts to bool whether account is open (true) or closed (false)
		/// </summary>
		operator bool() const;

		/// <summary>
		/// the conversion-to-double operator is a query that returns the balance from the current account if the account is open, or std::nan("") if the account is not open.
		/// </summary>
		operator double() const;

		/// <summary>
		/// the conversion-to-string operator is a query that returns address of the account owner attribute if the account is open, or "Not Open" if the account is not open.
		/// </summary>
		operator const char* () const;

		/// <summary>
		/// the conversion-to-int operator is a query that returns the number of transactions performed in this account if the account is open, or -1 if the account is not open.
		/// </summary>
		operator int() const;

		/// <summary>
		/// a modifier that adds to the balance the amount received as parameter
		/// </summary>
		/// <param name="amount"> a floating point number in double precision that represents how much money should be added to the balance.</param>
		/// <returns>a reference to the current instance</returns>
		BankAccount& operator+= (double amount);

		/// <summary>
		/// a modifier that withdraws from the balance the amount received as parameter
		/// </summary>
		/// <param name="amount">a floating point number in double precision that represents how much money should be removed from the balance.</param>
		/// <returns>a reference to the current instance</returns>
		BankAccount& operator-= (double amount);

		/// <summary>
		/// a query that creates a new account and adds to it the amount specified as parameter.
		/// </summary>
		/// <param name="amount">a floating point number in double precision that represents how much money should be added to the balance of the new account.</param>
		/// <returns>an object of type BankAccount</returns>
		BankAccount operator+ (double amount) const;

		/// <summary>
		/// the prefix increment is a modifier that adds the interest to the account balance.
		/// </summary>
		/// <returns>a reference to the current instance</returns>
		BankAccount& operator++ ();

		/// <summary>
		/// the postfix increment is a modifier that adds the interest to the account balance.
		/// </summary>
		/// <param name="">an un-named parameter of type int; this parameter helps us distinguish between prefix/post fix verions of the operator.</param>
		/// <returns>an object of type BankAccount (this is different from the prefix version)</returns>
		BankAccount operator++ (int);

		/// <summary>
		///  the greater-than comparison operator is a query compares the balance from current instance with the amount specified as parameter.
		/// </summary>
		/// <param name="amount">a floating point number in double precision.</param>
		/// <returns>true if the balance is greater than the parameter, false otherwise</returns>
		bool operator> (double amount) const;
	};

	/// <summary>
	/// the greater-than comparison operator compares amount specified in the first parameter with the balance of the account specified in the second parameter.
	/// </summary>
	/// <param name="amount">a floating point number in double precision.</param>
	/// <param name="account">an un-modifiable reference to an object of type BankAccount.</param>
	/// <returns>true if the first parameter is greater than the balance of the second parameter, false otherwise</returns>
	bool operator> (double amount, BankAccount account);

}

#endif // !SENECA_BANKACCOUNT_H