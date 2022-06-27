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

#ifndef QUIZZER_QUIZ_H 
#define QUIZZER_QUIZ_H 

namespace quizzer
{
	const int maxQuestions = 60;
	const int maxAnswers = 10;
	const int maxTextQueestion = 1024;
	const int maxTextAnswer = 128;

	struct Question
	{
		char typeOfQuestion[3 + 1]; // mc, ma
		char textOfQuestion[maxTextQueestion + 1]; // 질문 스트링
		int possibleAnswer;
		int correctAnswer;
	};

	struct Quiz
	{
		int numQuestions;
		int currentScore;
	};

	int LoadQuiz(const char* filename);
	int IsQuizValid();
	int HasMoreQuestions();
	void ShowNextQuestion();
	void ShowQuizResults();
}

#endif