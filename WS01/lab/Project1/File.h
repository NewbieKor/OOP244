/*
*****************************************************************************
						  Workshop - #1 (P1)
Full Name  : Seonghoon Kim
Student ID#: 143080216
Email      : shkim61@myseneca.ca
Section    : NGG
Date	   : 05.20.2022

I have done all the coding by myself and only copied the code that 
my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#ifndef SDDS_FILE_H 
#define SDDS_FILE_H

#include "ShoppingRec.h"

namespace sdds
{
	bool openFileForRead();
	bool openFileForOverwrite();
	void closeFile();
	bool freadShoppingRec(ShoppingRec* rec);
	void fwriteShoppintRec(const ShoppingRec* rec);
}

#endif