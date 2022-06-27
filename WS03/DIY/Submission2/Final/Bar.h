/*
*****************************************************************************
						  Workshop - #3 (P2)
Full Name  : Seonghoon Kim
Student ID#: 143080216
Email      : shkim61@myseneca.ca
Section    : NGG
Date	   : 06.06.2022

I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#ifndef SDDS_BAR_H
#define SDDS_BAR_H

namespace sdds
{
	const int MAX_CHAR = 20;

	class Bar
	{
		char b_title[MAX_CHAR + 1];
		char b_fillChar;
		int b_sampleVal;
	public:
		void setEmpty();
		void setMembers(const char* title, char fillChar, int value);
		bool isValid() const;
		void draw() const;
	};
}

#endif // !SDDS_BAR_H

