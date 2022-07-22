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

#ifndef SDDS_CHEQUINGAACCOUNT_H
#define SDDS_CHEQUINGAACCOUNT_H
#include "Account.h"
namespace sdds
{
	class ChequingAccount :public Account
	{
		double m_transactionFee;
		double m_monthlyFee;
	public:
		ChequingAccount(double, double, double);
		bool credit(double);
		bool debit(double);
		void monthEnd();
		void display(std::ostream&) const;
	};
}

#endif // !SDDS_CHEQUINGAACCOUNT_H
