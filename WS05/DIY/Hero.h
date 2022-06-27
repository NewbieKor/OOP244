/*
*****************************************************************************
                          Workshop - #5 (P2)
Full Name  : Seonghoon Kim
Student ID#: 143080216
Email      : shkim61@myseneca.ca
Section    : NGG
Date	   : 06.19.2022

I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#ifndef SDDS_HERO_H
#define SDDS_HERO_H
#include<iostream>
#include "Power.h"

namespace sdds{
    class Hero
    {
        char m_nameOfHero[MAX_NAME_LENGTH + 1];
        Power* m_powerSet;
        int m_noOfPowers;
        int m_powerLevel; 
        void setEmpty();
        void setLevel();
    public:
        // Constructors & Destructor
        Hero();
        Hero(const char* name, Power* powers, int noOfpowers); 
        ~Hero();
        // Member functions
        std::ostream& display() const; 
        Hero& operator+=(Power& pow);
        Hero& operator-=(const int& level);
        int getPowerLevel() const;
    };
    // Helper functions
    bool operator<(Hero& hero1, Hero& hero2);
    bool operator>(Hero& hero1, Hero& hero2);
    void operator>>(Power& power, Hero& hero);
    void operator<<(Hero& hero, Power& power);
    std::ostream& operator<<(std::ostream& os, const Hero& hero);
}

#endif // !SDDS_HERO_H
