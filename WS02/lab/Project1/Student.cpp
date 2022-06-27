#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include "Student.h"
#include "File.h"
using namespace std;
namespace sdds {
	int noOfStudents;
	Student* students;
	void sort() {
		int i, j;
		Student temp;
		for (i = noOfStudents - 1; i > 0; i--) {
			for (j = 0; j < i; j++) {
				if (students[j].m_grade > students[j + 1].m_grade) {
					temp = students[j];
					students[j] = students[j + 1];
					students[j + 1] = temp;
				}
			}
		}
	}

	bool load(Student& student)
	{
		bool result = false;
		char temp[128];
		if (read(temp) && read(student.m_studentNumber) && read(student.m_grade)) {
			student.m_name = new char[strlen(temp) + 1];
			strcpy(student.m_name, temp);
			result = true;
		}

		return result;
	}

	bool load(const char* filename)
	{
		int noOfread = 0;
		bool result = false;
		if (openFile(filename)) {
			noOfStudents = noOfRecords();
			students = new Student[noOfStudents];
			while (load(students[noOfread])) noOfread++;
			if (noOfread != noOfStudents)
				cout << "Error: incorrect number of records read; the data is possibly corrupted." << endl;
			else result = true;
			closeFile();
		}
		else cout << "Can't open file " << filename << endl;
		return result;
	}

	void display(const Student& student)
	{
		cout << student.m_name << ", " << student.m_studentNumber << ": " << student.m_grade << endl;
	}

	void display()
	{
		sort();
		for (int i = 0; i < noOfStudents; i++) {
			cout << i + 1 << ": ";
			display(students[i]);
		}
	}

	void deallocateMemory()
	{
		for (int i = 0; i < noOfStudents; i++) {
			delete[] students[i].m_name;
		}
		delete[] students;
	}



}
