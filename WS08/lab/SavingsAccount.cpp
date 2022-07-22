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
#include "SavingsAccount.h"
using namespace std;
namespace sdds
{
	SavingsAccount::SavingsAccount(double balance, double rate): Account(balance)
	{
		if (rate > 0) m_interestRate = rate;
		else m_interestRate = 0.0;
	}

	void SavingsAccount::monthEnd()
	{
		Account::credit(Account::balance() * m_interestRate);
	}

	void SavingsAccount::display(std::ostream& os) const
	{
		os << "Account type: Savings" << endl;
		os << "Balance: $" << setprecision(2) << fixed << Account::balance() << endl;
		os << "Interest Rate (%): " << m_interestRate * 100 << endl;
	}

}
