/*
*****************************************************************************
						  Workshop - #5 (P1)
Full Name  : Seonghoon Kim
Student ID#: 143080216
Email      : shkim61@myseneca.ca
Section    : NGG
Date	   : 06.15.2022

I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Book.h"

using namespace std;
namespace sdds {
	void Book::init_book() {
		m_title[0] = '\0';
		m_author[0] = '\0';
		m_num_chapters=0;
		m_num_pages=0;
	}

	int Book::add_chapter(Chapter* chapter)
	{
		if (m_num_chapters < MAX_NUM_CHAPTERS)
		{
			(*this)++;
			m_chapters[m_num_chapters - 1] = *chapter;
		}
		return m_num_chapters;
	}

	Book::Book() {
		init_book();
	}

	Book::Book(const char* title_) {
		init_book();
		strcpy(m_title, title_);
	}

	Book::Book(const char* title_, const char* author_, double price_) {
		init_book();
		strcpy(m_title, title_);
		strcpy(m_author, author_);
		m_price = price_;
	}

	// Print a book summary
	void Book::summary() {
		cout.setf(ios::left);
		cout << "| ";
		cout.width(MAX_BOOK_TITEL);
		cout << m_title << " | ";
		cout.width(MAX_AUTHOR_NAME);
		cout << m_author << " | ";
		cout.width(3);
		cout << m_num_chapters << "  ";
		cout.width(4);
		cout << m_num_pages << " | ";
		cout.width(6);
		cout << m_price << " |" << endl;
	}

	Book Book::operator++(int)
	{
		Book temp = *this;
		m_num_chapters++;
		return temp;
	}

	std::ostream& Book::display(std::ostream& os) const
	{
		os << "Title:'" << m_title << '\'' << endl;
		os << "Author: '" << m_author << '\'' << endl;
		for (int i = 0; i < m_num_chapters; i++)
		{
			os << m_chapters[i];
		}
		return os;
	}

	Book::operator int() const
	{
		return m_num_chapters;
	}

	Book::operator bool() const
	{
		bool isExtant = false;
		for (int i = 0; i < m_num_pages && !isExtant; i++)
		{
			if ((int)m_chapters[i] > 0) isExtant = true;
		}

		return m_title && m_title[0] != '\0' && m_author && m_author[0] != '\0' && m_num_chapters > 0 && isExtant;
	}

	Book::operator double() const
	{
		return m_price;
	}

	Book::operator const char* () const
	{
		return m_title;
	}

	bool Book::operator!() const
	{
		return !((bool)*this);
	}

	Book& Book::operator+=(Chapter& rhs)
	{
		add_chapter(&rhs);
		m_num_pages += (int)rhs;
		return *this;
	}
	Book& Book::operator-=(double disc)
	{
		if (m_price > disc) m_price -= disc;
		else m_price = 0;
		return *this;
	}
	std::ostream& operator<<(std::ostream& os, const Book& rhs)
	{
		return rhs.display(os);
	}
}
