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

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstring>
#include "BirthDate.h"
using namespace std;
namespace sdds
{
	FILE* fptr;
	Employee* employees;
	int noOfEmployees;

	bool beginSearch(const char* filename)
	{
		bool isOpen = false;

		fptr = fopen(filename, "r");

		if (fptr)
		{
			cout << "Birthdate search program" << endl;
			isOpen = true;
		}
		else
		{
			cout << "Data file " << '\"' << filename << '\"' << " not found!" << endl;
		}

		return isOpen;
	}

	bool readBirthDate(int month)
	{
		char temp[50];
		int birthMonth;
		int birthDate;
		int birthYear;
		int noOfMatching = 0;
		noOfEmployees = 0;

		while (fscanf(fptr, "%[^,],", temp) == 1 && 
			fscanf(fptr, "%d/", &birthMonth) == 1 && 
			fscanf(fptr, "%[^\n]\n", temp) == 1)
		{
			if (birthMonth == month) noOfEmployees++;
		}
		
		employees = new Employee[noOfEmployees]; 
		rewind(fptr);

		while (fscanf(fptr, "%[^,],", temp) == 1)
		{
			if (fscanf(fptr, "%d/", &birthMonth) == 1 && birthMonth == month &&
				fscanf(fptr, "%d/", &birthDate) == 1 && fscanf(fptr, "%d\n", &birthYear) == 1)
			{
				employees[noOfMatching].m_name = new char[strlen(temp) + 1];
				strcpy(employees[noOfMatching].m_name, temp);
				employees[noOfMatching].m_birthMonth = birthMonth;
				employees[noOfMatching].m_birthDate = birthDate;
				employees[noOfMatching].m_birthYear = birthYear;
				noOfMatching++;
			}
			else
			{
				fscanf(fptr, "%[^\n]\n", temp);
			}
		}
		
		rewind(fptr);

		return noOfEmployees > 0;
	}

	void sort() // referred to part 1.
	{
		int i, j;
		Employee temp;

		for (i = noOfEmployees - 1; i > 0; i--)
		{
			for (j = 0; j < i; j++)
			{
				if (employees[j].m_birthYear > employees[j + 1].m_birthYear)
				{
					temp = employees[j];
					employees[j] = employees[j + 1];
					employees[j + 1] = temp;
				}
			}
		}
	}

	void displayBirthdays()
	{
		cout << noOfEmployees << " birthdates found:" << endl;

		for (int i = 0; i < noOfEmployees; i++)
		{
			cout << i + 1 << ") " << employees[i].m_name << ':' << endl;
			cout << employees[i].m_birthYear << '-' << employees[i].m_birthMonth << '-' << employees[i].m_birthDate << endl;
			cout << "===================================" << endl;
		}
	}

	void deallocate()
	{
		for (int i = 0; i < noOfEmployees; i++)
		{
			delete[] employees[i].m_name;
		}

		delete[] employees;
	}

	void endSearch()
	{
		if (fptr) fclose(fptr);

		cout << "Birthdate Search Program Closed." << endl;
	}
}