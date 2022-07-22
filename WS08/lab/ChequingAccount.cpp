/*
*****************************************************************************
						  Workshop - #8 (P1)
Full Name  : Seonghoon Kim
Student ID#: 143080216
Email      : shkim61@myseneca.ca
Section    : NGG
Date	   : 07.21.2022

I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#include <iomanip>
#include "ChequingAccount.h"
using namespace std;
namespace sdds
{
	ChequingAccount::ChequingAccount(double balance, double transaction, double monthly):Account(balance)
	{
		if (transaction > 0) m_transactionFee = transaction;
		else m_transactionFee = 0.0;
		if (monthly > 0) m_monthlyFee = monthly;
		else m_monthlyFee = 0.0;

	}
	bool ChequingAccount::credit(double amount)
	{
		bool isSucessful = false;
		if (Account::credit(amount))
			isSucessful = Account::debit(m_transactionFee);
		return isSucessful;
	}
	bool ChequingAccount::debit(double amount)
	{
		bool isSucessful = false;
		if(Account::debit(amount)) 
			isSucessful = Account::debit(m_transactionFee);
		return isSucessful;
	}
	void ChequingAccount::monthEnd()
	{
		Account::debit(m_monthlyFee);
	}
	void ChequingAccount::display(std::ostream& os) const
	{
		os << "Account type: " << "Chequing" << endl;
		os << "Balance: $" << setprecision(2) << fixed << Account::balance() << endl;
		os << "Per Transaction Fee: " << m_transactionFee << endl;
		os << "Monthly Fee: " << m_monthlyFee << endl;
	}
}