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
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iomanip>
#include "MemberParliament.h"
using namespace std;
namespace sdds
{
    MemberParliament::MemberParliament(const char* id, int age)
    {
        strcpy(m_id, id);
        m_age = age;
        strcpy(m_district, "Unassigned");
    }
    void MemberParliament::NewDistrict(const char* district)
    {
        cout << '|' << setw(8) << right << m_id << "| |" << setw(20) << m_district << " ---> ";
        strcpy(m_district, district);
        cout << setw(23) << left << m_district << "|" << endl;
    }
    ostream& MemberParliament::write(ostream& os) const
    {
        os << "| " << m_id << " | " << m_age << " | " << m_district;
        return os;
    }
    istream& MemberParliament::read(istream& in)
    {
        cout << "Age: ";
        in >> m_age;
        cout << "Id: ";
        in >> m_id;
        cout << "District: ";
        in >> m_district;
        return in;
    }
    std::ostream& operator<<(std::ostream& os, const MemberParliament& member)
    {
        return member.write(os);
    }
    std::istream& operator>>(std::istream& is, MemberParliament& member)
    {
        return member.read(is);
    }
}
