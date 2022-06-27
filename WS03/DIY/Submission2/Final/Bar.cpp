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

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Bar.h"

using namespace std;

namespace sdds
{
    void Bar::setEmpty()
    {
        b_title[0] = '\0';
        b_fillChar = '\0';
        b_sampleVal = -1; // should not be between 0 and 100.
    }
    void Bar::setMembers(const char* title, char fillChar, int value)
    {
        if (value >= 0 && value <= 100)
        {
            strncpy(b_title, title, 20);
            b_fillChar = fillChar;
            b_sampleVal = value;
        }
        else setEmpty(); // set the bar to an invalid state.
    }
    bool Bar::isValid() const
    {
        return b_title && b_title[0] != '\0' && b_sampleVal >= 0 && b_sampleVal <= 100;
    }
    void Bar::draw() const
    {
        int i;
        if (b_sampleVal >= 0 && b_sampleVal <= 100)
        {
            for (i = 0; i < MAX_CHAR; i++)
            {
                if (b_title[i] != '\0') cout << b_title[i];
                else cout << '.';
            }
            cout << '|';
            for (i = 0; i < b_sampleVal / 2; i++) cout << b_fillChar;
            cout << endl;
        }
    }
}