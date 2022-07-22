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

#include "Account.h"
namespace sdds
{
	Account::Account(double balance)
	{
		if (balance > 0) m_balance = balance;
		else m_balance = 0.0;
	}

	bool Account::credit(double amount)
	{
		if (amount > 0) m_balance += amount;
		return amount > 0;
	}

	bool Account::debit(double amount)
	{
		if (amount > 0) m_balance -= amount;
		return amount > 0;
	}

	double Account::balance() const
	{
		return m_balance;
	}
}

