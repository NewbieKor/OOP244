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

#ifndef SDDS_SAVINGSACCOUNT_H
#define SDDS_SAVINGSACCOUNT_H
#include "Account.h"
namespace sdds
{
	class SavingsAccount: public Account
	{
		double m_interestRate;
	public:
		SavingsAccount(double balance, double rate);
		void monthEnd();
		void display(std::ostream&) const;
	};
}

#endif // !SDDS_SAVINGSACCOUNT_H
