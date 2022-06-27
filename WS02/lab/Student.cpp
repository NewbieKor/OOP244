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
	Student* students; // 복사본이 아닌 직접 원본에 접근하기 위해 포인터 사용.
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

	bool load(Student& student) // 복사본이 아닌 원본에 접근하기 위해 레퍼런스 사용.
	{
		bool isReadable = false;
		char localArr[128]; // 이름 사이즈 정하기 위해 (동적할당 하기 위해) 임시 문자열 생성.(학번이나 학점은 다 같으므로 길이가 정해져있음)
		if (read(localArr) && read(student.m_studentNumber) && read(student.m_grade)) // read함수를 통해서 localArr에 이름 데이터 저장. 
		{
			
			student.m_name = new char[strlen(localArr) + 1]; // m_name에 동적할당.(각 이름 별로 사이즈 지정)
			
			strcpy(student.m_name, localArr); // 임시 변수에 저장되어 있는 이름들을 m_name에 복사.
			isReadable = true;
		}
		return isReadable;
	}

	bool load(const char* filename)
	{
		int noOfread = 0;
		bool isConsistent = false;

		openFile(filename); // 파일 열기
		noOfStudents = noOfRecords(); // 레코드 수를 noOfStudent 변수에 저장.
		students = new Student[noOfStudents]; // 레코드 수만큼의 구조체 생성하기 위한 동적 할당.
		for (int i = 0; i < noOfStudents; i++)
		{
			if (load(students[noOfread])) // 한줄씩(기록 하나씩) 불러옴. 
			{
				noOfread++; // 기록 하나씩 체크.
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
		for (int i = 0; i < noOfStudents; i++) // 동적할당 해제할 때에는 이름 하나씩 해제해야 한다. 
		{
			delete[] students[i].m_name;
		}
		delete[] students; // 멤버에 할당된 동적메모리 모두 해제한 후에 구조체도 해제해 준다.
	}
}


