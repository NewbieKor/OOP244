/*
*****************************************************************************
						  Workshop - #1 (P2)
Full Name  : Seonghoon Kim
Student ID#: 143080216
Email      : shkim61@myseneca.ca
Section    : NGG
Date	   : 05.23.2022

I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include "quiz.h"


using namespace std;

namespace quizzer
{
	Question question;
	Quiz quiz;

	FILE* fp;

	int LoadQuiz(const char* filename)
	{
		int load_valid;
		
		fp = fopen(filename, "r");
		
		if (fp != NULL)
		{
			load_valid = 0;
		}
		else
		{
			load_valid = 1;
		}

		return load_valid;
	}

	int IsQuizValid()
	{
		if(fscanf(fp, "%[^ ]", question.typeOfQuestion) == 1);
		{

		}

		for (int i = 0; i < quiz.numQuestions; i++)
		{
			cout << "Question " << i + 1 << " -> X";
		}

		return 1;
	}

	//int HasMoreQuestions()
	//{

	//}

	//void ShowNextQuestion()
	//{

	//}

	//void ShowQuizResults()
	//{

	//}
}

