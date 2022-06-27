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

#ifndef SDDS_STUDENT_H
#define SDDS_STUDENT_H
namespace sdds
{
    struct Student
    {
        char* m_name;
        int m_studentNumber;
        char m_grade;
    };

    void sort();
    bool load(Student& student);
    bool load(const char* filename);
    void display(const Student& student);
    void display();
    void deallocateMemory();
}

#endif // !SDDS_STUDENT_H