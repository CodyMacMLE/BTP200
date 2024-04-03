#include <iostream>
#include <iomanip>
#include "ChequingAccount.h"

namespace seneca 
{
    ChequingAccount::ChequingAccount(double balance, double transactionFee, double monthlyFee) :
        Account(balance)
    {
        if (transactionFee >= 0.0)
            m_transactionFee = transactionFee;
        else
            m_transactionFee = 0.0;
        if (monthlyFee >= 0.0)
            m_monthlyFee = monthlyFee;
        else
            m_monthlyFee = 0.0;
    }

    bool ChequingAccount::credit(double amount)
    {
        bool exitFlag = false;
        if (amount > 0)
        {
            this->Account::credit(amount);
            this->Account::debit(m_transactionFee);
        }
        return exitFlag;
    }
    
    bool ChequingAccount::debit(double amount)
    {
        bool exitFlag = false;
        if (amount > 0)
        {
            this->Account::debit(amount);
            this->Account::debit(m_transactionFee);
        }
        return exitFlag;
    }

    void ChequingAccount::monthEnd()
    {
        this->Account::debit(m_monthlyFee);
    }

    void ChequingAccount::display(std::ostream& out) const
    {
        out << "Account Type: Chequing\nBalance: $";
        out << std::setprecision(2) << std::fixed << this->balance() << std::endl;
        out << "Per Transaction Fee: " << this->m_transactionFee << std::endl;
        out << "Monthly Fee: " << this->m_monthlyFee << std::endl;
        out << std::setprecision(6);
    }
}