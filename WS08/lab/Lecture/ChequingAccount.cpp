#include <iomanip>
#include "ChequingAccount.h"
using namespace std;
namespace sdds {
    ChequingAccount::ChequingAccount(double balance, double transactionFee, double monthlyFee) : Account(balance)
    {
        if (transactionFee > 0) {
            m_transactionFee = transactionFee;
        }
        else m_transactionFee = 0.0;

        if (monthlyFee > 0) {
            m_monthlyFee = monthlyFee;
        }
        else m_monthlyFee = 0.0;
    }
    bool ChequingAccount::credit(double amount)
    {
        bool result = false;
        if (Account::credit(amount)) {
            result = Account::debit(m_transactionFee);            
        }
        return result;
    }
    bool ChequingAccount::debit(double amount)
    {
        bool result = false;
        if (Account::debit(amount)) {
            result = Account::debit(m_transactionFee);
        }
        return result;
    }
    void ChequingAccount::monthEnd()
    {
        Account::debit(m_monthlyFee);
    }
    void ChequingAccount::display(std::ostream& os) const
    {
        os << setprecision(2);
        os << fixed;
        os << "Account type: Chequing" << endl;
        os << "Balance: $" << Account::balance() << endl;
        os << "Per Transaction Fee: " << m_transactionFee << endl;
        os << "Monthly Fee: " << m_monthlyFee << endl;
    }
}