/*
*****************************************************************************
						  Workshop - #2 (P2)
Full Name  : Seonghoon Kim
Student ID#: 143080216
Email      : shkim61@myseneca.ca
Section    : NGG
Date	   : 05.30.2022

I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#ifndef SDDS_BIRTHDATE_H
#define SDDS_BIRTHDATE_H
namespace sdds {
	struct Employee
	{
		char* m_name;
		int m_birthMonth;
		int m_birthDate;
		int m_birthYear;
	};

	bool beginSearch(const char* filename);
	bool readBirthDate(int month);
	void sort();
	void displayBirthdays();
	void deallocate();
	void endSearch();
}


#endif