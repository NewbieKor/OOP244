/*
*****************************************************************************
                          Workshop - #7 (P1)
Full Name  : Seonghoon Kim
Student ID#: 143080216
Email      : shkim61@myseneca.ca
Section    : NGG
Date	   : 07.15.2022

I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#ifndef SDDS_MEMBERPARLIAMENT_H
#define SDDS_MEMBERPARLIAMENT_H
#include <iostream>
namespace sdds
{
    class MemberParliament
    {
        char m_id[32];
        char m_district[64];
        int m_age;
    public:
        MemberParliament(const char* id, int age);
        void NewDistrict(const char* district);
        std::ostream& write(std::ostream& os) const;
        std::istream& read(std::istream& in);
    };
    std::ostream& operator<<(std::ostream& os, const MemberParliament& member);
    std::istream& operator>>(std::istream& is, MemberParliament& member);
}

#endif // !SDDS_MEMBERPARLIAMENT_H



