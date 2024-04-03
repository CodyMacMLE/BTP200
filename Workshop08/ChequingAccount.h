#ifndef SENECA_CHEQUING_SAVINGS_ACCOUNT_H
#define SENECA_CHEQUING_SAVINGS_ACCOUNT_H
#include "Account.h"
namespace seneca 
{
    class ChequingAccount :
        public Account
    {
        double m_transactionFee;
        double m_monthlyFee;
    public:
        ChequingAccount(double balance, double transactionFee, double monthlyFee);
        bool credit(double amount);
        bool debit(double amount);
        void monthEnd();
        void display(std::ostream& out = std::cout) const;
    };
}
#endif //!SENECA_CHEQUING_ACCOUNT_H
