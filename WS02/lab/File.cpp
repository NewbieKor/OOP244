/*
*****************************************************************************
                          Workshop - #2 (P1)
Full Name  : Seonghoon Kim
Student ID#: 143080216
Email      : shkim61@myseneca.ca
Section    : NGG
Date	   : 05.27.2022

I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "File.h"

namespace sdds {
   FILE* fptr;
   bool openFile(const char filename[]) {
      fptr = fopen(filename, "r");
      return fptr != NULL;
   }

   int noOfRecords() {
      int noOfRecs = 0;
      char ch;
      while (fscanf(fptr, "%c", &ch) == 1) {
         noOfRecs += (ch == '\n');
      }
      rewind(fptr);
      return noOfRecs;
   }

   bool read(char* cstr)
   {
       return fscanf(fptr, "%[^,],", cstr) == 1;
   }

   bool read(int& stdNum)
   {
       return fscanf(fptr, "%d,", &stdNum) == 1;
   }

   bool read(char& stdGrd)
   {
       return fscanf(fptr, "%c\n", &stdGrd) == 1;
   }

   void closeFile() {
      if (fptr) fclose(fptr);
   }
}