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

#ifndef SDDS_BARCHART_H
#define SDDS_BARCHART_H
#include "Bar.h"

namespace sdds
{
    class BarChart
    {
        char* bc_titleOfChart;
        Bar* bc_bars;
        char bc_fillChar;
        int bc_sizeOfBars;
        int bc_noOfAddedSamples;
    public:
        bool isValid() const;
        void init(const char* title, int noOfSampels, char fill);
        void add(const char* bar_title, int value);
        void draw() const;
        void deallocate();
    };
    
}
#endif // !SDDS_BARCHART_H

