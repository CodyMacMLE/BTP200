#ifndef SENECA_ACCOUNT_H
#define SENECA_ACCOUNT_H
#include "iAccount.h"
namespace seneca 
{
    class Account :
        public iAccount
    {
        /// <summary>
        /// Current balance
        /// </summary>
        double m_balance;
    public:
        /// <summary>
        /// Initializes the account with a balance
        /// </summary>
        /// <param name="balance">balance</param>
        Account(double balance = 0.0);

        /// <summary>
        /// receives an amount to be credited (added) to the account balance
        /// </summary>
        /// <param name="amount">amount to be added</param>
        /// <returns>Whether addition was successful</returns>
        bool credit(double amount);
    };
}
#endif // !SENECA_ACCOUNT_H
