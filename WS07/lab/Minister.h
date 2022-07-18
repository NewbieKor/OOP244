/*
*****************************************************************************
						  Workshop - #7 (P1)
Full Name  : Seonghoon Kim
Student ID#: 143080216
Email      : shkim61@myseneca.ca
Section    : NGG
Date	   : 07.15.2022

I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#ifndef SDDS_MINISTER_H
#define SDDS_MINISTER_H
#include <iostream>
#include "MemberParliament.h"
namespace sdds
{
	class Minister :public MemberParliament
	{
		char m_name[50];
		int m_year;
	public:
		Minister(const char* id, int age, int year, const char* name, const char* district);
		void changePM(const char* pm);
		void assumeOffice(double year);
		std::ostream& write(std::ostream& os) const;
		std::istream& read(std::istream& in);
	};
	std::ostream& operator<<(std::ostream& os, const Minister& minister);
	std::istream& operator>>(std::istream& is, Minister& minister);
}

#endif // !SDDS_MINISTER_H
