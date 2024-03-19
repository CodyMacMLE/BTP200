#ifndef SENECA_SAVINGS_ACCOUNT_H
#define SENECA_SAVINGS_ACCOUNT_H
#include "Account.h"
namespace seneca
{
    class SavingsAccount :
        public Account
    {
        /// <summary>
        /// Interest rate of the account
        /// </summary>
        double m_interestRate;
    public:
        /// <summary>
        /// constructor holding initial balance and interest rate to be applied
        /// </summary>
        /// <param name="balance">the initial balance amount</param>
        /// <param name="interestRate">the interest rate as decimal</param>
        SavingsAccount(double balance, double interestRate);

        /// <summary>
        /// modifier that calculates the interest on the current balance and credits the account with the interest
        /// </summary>
        void monthEnd();

        /// <summary>
        /// Displays account details
        /// </summary>
        /// <param name="out">a reference to std::ostream</param>
        void display(std::ostream& out = std::cout) const;
    };
}
#endif // !SENECA_SAVINGS_ACCOUNT_H

 