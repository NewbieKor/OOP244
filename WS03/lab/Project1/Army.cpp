/*
*****************************************************************************
                          Workshop - #3 (P1)
Full Name  : Seonghoon Kim
Student ID#: 143080216
Email      : shkim61@myseneca.ca
Section    : NGG
Date	   : 06.03.2022

I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Army.h"

using namespace std;
namespace sdds
{
    void Army::setEmpty()
    {
        nationality[0] = '\0'; 
        numOfUnits = 0;
    }

    void Army::createArmy(const char* country, double pow, int troops)
    {
        if (country && strlen(country) > 0 && troops > 0 && pow > 0)
        {
            strncpy(nationality, country, MAX_NAME_LEN);
            numOfUnits = troops;
            powerOfArmy = pow;
        }
        else
        {
            setEmpty();
        }
    }

    void Army::updateUnits(int troops)
    {
        numOfUnits += troops;
        powerOfArmy += 0.25 * troops;
    }

    const char* Army::checkNationality() const
    {
        return nationality;
    }

    int Army::checkCapacity() const
    {
        return numOfUnits;
    }

    double Army::checkPower() const
    {
        return powerOfArmy;
    }

    bool Army::isEmpty() const
    {
        return nationality[0] == '\0' && numOfUnits == 0;
    }

    bool Army::isStrongerThan(const Army& army) const
    {
        return powerOfArmy > army.powerOfArmy;
    }

    void battle(Army& arm1, Army& arm2)
    {
        cout << "In battle of " << arm1.checkNationality() << " and " << arm2.checkNationality() << ", ";
        if (!arm1.isEmpty() && !arm2.isEmpty())
        {
            if (arm1.isStrongerThan(arm2))
            {
                arm2.updateUnits((int)-(arm2.checkCapacity()) / 2);
                cout << arm1.checkNationality();
            }
            else
            {
                arm1.updateUnits((int)-(arm1.checkCapacity()) / 2);
                cout << arm2.checkNationality();
            }
        }
        cout << " is victorious!" << endl;
    }

    void displayDetails(const Army* armies, int size)
    {
        cout << fixed;
        cout.precision(1);
        cout << "Armies reporting to battle: " << endl;
        for (int i = 0; i < size; i++)
        {
            if (!armies[i].isEmpty())
            {
                cout << "Nationality: " << armies[i].checkNationality()
                    << ", Units Count: " << armies[i].checkCapacity()
                    << ", Power left: " << armies[i].checkPower() << endl;
            }
        }
    }
}
