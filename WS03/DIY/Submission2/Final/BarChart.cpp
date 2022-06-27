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
#include "BarChart.h"

using namespace std;
namespace sdds
{
    bool BarChart::isValid() const
    {
        bool valid = true;
        if (bc_titleOfChart && bc_bars && bc_noOfAddedSamples == bc_sizeOfBars) 
        {
            for (int i = 0; i < bc_sizeOfBars && valid; i++) 
                if (!bc_bars[i].isValid()) valid = false;
        }
        else valid = false;
        
        return valid;
    }

    void BarChart::init(const char* title, int noOfSampels, char fill)
    {
        bc_titleOfChart = new char[strlen(title) + 1];
        strcpy(bc_titleOfChart, title);
        bc_sizeOfBars = noOfSampels;
        bc_bars = new Bar[bc_sizeOfBars];
        bc_fillChar = fill;
        bc_noOfAddedSamples = 0;
    }

    void BarChart::add(const char* bar_title, int value)
    {
        bc_bars[bc_noOfAddedSamples++].setMembers(bar_title, bc_fillChar, value);
    }

    void BarChart::draw() const
    {
        if (isValid())
        {
            cout << bc_titleOfChart << endl;
            cout << "-----------------------------------------------------------------------" << endl;
            for (int i = 0; i < bc_sizeOfBars; i++) bc_bars[i].draw();
            cout << "-----------------------------------------------------------------------" << endl;
        }
        else cout << "Invalid Chart!" << endl;
    }
    void BarChart::deallocate()
    {
        delete[] bc_titleOfChart;
        delete[] bc_bars;
    }
}