#ifndef SDDS_STUDENT_H
#define SDDS_STUDENT_H
namespace sdds {
	struct Student {
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
