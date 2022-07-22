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

#ifndef SDDS_ACCOUNT_H
#define SDDS_ACCOUNT_H
#include "iAccount.h"
namespace sdds
{
	class Account: public iAccount
	{
		double m_balance;
	public:
		Account(double); //  the initial account balance
		bool credit(double);
		bool debit(double);
	protected:
		double balance() const;
	};
}

#endif // !SDDS_ACCOUNT_H
