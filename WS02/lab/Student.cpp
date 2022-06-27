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
#include <cstring>
#include <iostream>
#include "Student.h"
#include "File.h"
using namespace std;
namespace sdds
{
	int noOfStudents;
	Student* students; // ���纻�� �ƴ� ���� ������ �����ϱ� ���� ������ ���.
	void sort()
	{
		int i, j;
		Student temp;
		for (i = noOfStudents - 1; i > 0; i--)
		{
			for (j = 0; j < i; j++)
			{
				if (students[j].m_grade > students[j + 1].m_grade)
				{
					temp = students[j];
					students[j] = students[j + 1];
					students[j + 1] = temp;
				}
			}
		}
	}

	bool load(Student& student) // ���纻�� �ƴ� ������ �����ϱ� ���� ���۷��� ���.
	{
		bool isReadable = false;
		char localArr[128]; // �̸� ������ ���ϱ� ���� (�����Ҵ� �ϱ� ����) �ӽ� ���ڿ� ����.(�й��̳� ������ �� �����Ƿ� ���̰� ����������)
		if (read(localArr) && read(student.m_studentNumber) && read(student.m_grade)) // read�Լ��� ���ؼ� localArr�� �̸� ������ ����. 
		{
			
			student.m_name = new char[strlen(localArr) + 1]; // m_name�� �����Ҵ�.(�� �̸� ���� ������ ����)
			
			strcpy(student.m_name, localArr); // �ӽ� ������ ����Ǿ� �ִ� �̸����� m_name�� ����.
			isReadable = true;
		}
		return isReadable;
	}

	bool load(const char* filename)
	{
		int noOfread = 0;
		bool isConsistent = false;

		openFile(filename); // ���� ����
		noOfStudents = noOfRecords(); // ���ڵ� ���� noOfStudent ������ ����.
		students = new Student[noOfStudents]; // ���ڵ� ����ŭ�� ����ü �����ϱ� ���� ���� �Ҵ�.
		for (int i = 0; i < noOfStudents; i++)
		{
			if (load(students[noOfread])) // ���پ�(��� �ϳ���) �ҷ���. 
			{
				noOfread++; // ��� �ϳ��� üũ.
			}
			else
			{
				break;
			}
		}
		//while (load(students[noOfread])) noOfread++;
		if (noOfread != noOfStudents)
			cout << "Error: incorrect number of records read; the data is possibly corrupted." << endl;
		else isConsistent = true;
		closeFile();

		return isConsistent;
	}


	void display(const Student& student)
	{
		cout << student.m_name << ", " << student.m_studentNumber << ": " << student.m_grade << endl;
	}

	void display()
	{
		sort();
		for (int i = 0; i < noOfStudents; i++)
		{
			cout << i + 1 << ": ";
			display(students[i]);
		}
	}

	void deallocateMemory()
	{
		for (int i = 0; i < noOfStudents; i++) // �����Ҵ� ������ ������ �̸� �ϳ��� �����ؾ� �Ѵ�. 
		{
			delete[] students[i].m_name;
		}
		delete[] students; // ����� �Ҵ�� �����޸� ��� ������ �Ŀ� ����ü�� ������ �ش�.
	}
}


