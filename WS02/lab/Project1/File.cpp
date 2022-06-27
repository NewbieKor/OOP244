#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "File.h"

namespace sdds {
	FILE* fptr;
	bool openFile(const char filename[]) {
		fptr = fopen(filename, "r");
		return fptr != NULL;
	}
	int noOfRecords() {
		int noOfRecs = 0;
		char ch;
		while (fscanf(fptr, "%c", &ch) == 1) {
			noOfRecs += (ch == '\n');
		}
		rewind(fptr);
		return noOfRecs;
	}
	bool read(char* cstr)
	{
		return fscanf(fptr, "%[^,],", cstr) == 1;
	}
	bool read(int& stdNumber)
	{
		return fscanf(fptr, "%d,", &stdNumber) == 1;
	}
	bool read(char& stdGrade)
	{
		return fscanf(fptr, "%c\n", &stdGrade) == 1;
	}
	void closeFile() {
		if (fptr) fclose(fptr);
	}

}