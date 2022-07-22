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

#ifndef SDDS_IACCOUNT_H
#define SDDS_IACCOUNT_H
#include <iostream>
namespace sdds
{
	class iAccount
	{
	public:
		virtual bool credit(double) = 0; // adds a positive amount to the account balance
		virtual bool debit(double) = 0; // subtracts a positive amount from the account balance
		virtual void monthEnd() = 0; // applies month-end transactions to the account
		virtual void display(std::ostream&) const = 0; // inserts account information into an ostream object
		virtual ~iAccount() {};
	};
	iAccount* CreateAccount(const char*, double);
}
#endif // !SDDS_IACCOUNT_H


