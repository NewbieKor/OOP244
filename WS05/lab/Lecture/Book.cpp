#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Book.h"

using namespace std;
namespace sdds {
	void Book::init_book() {
		m_title[0] = '\0';
		m_author[0] = '\0';
		m_num_chapters = 0;
		m_num_pages = 0;
	}

	int Book::add_chapter(Chapter* chapter)
	{
		if (m_num_chapters < MAX_NUM_CHAPTERS) {
			(*this)++; // *this는 Book의 인스턴스(temp) <- Book Book::operator++(int). m_num_chapters에 1 추가. 
			m_chapters[m_num_chapters - 1] = *chapter; // m_num_chapters - 1 : 인덱스 번호. 즉, 마지막 
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
		m_num_chapters++; // 현재 객체(*this)의 멤버변수.
		return temp; 
	}

	std::ostream& Book::display(std::ostream& os) const // Argument os = cout.
	{
		os << "Title:'" << m_title << '\'' << endl; //이 프로젝트에서 os는 cout으로 쓰임.
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
		bool hasGreaterThanZeroPage = false;
		for (int i = 0; i < m_num_chapters && !hasGreaterThanZeroPage; i++) {
			if ((int)m_chapters[i] > 0) hasGreaterThanZeroPage = true; //(int)m_chapters는 Chapter 클래스의 operater int() const; 불러옴.
		}
		return m_title && m_title[0] != '\0' && m_author && m_author[0] != '\0' && m_num_chapters > 0 && hasGreaterThanZeroPage;
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

	Book& Book::operator+=(Chapter& chapter)
	{
		add_chapter(&chapter);
		m_num_pages += (int)chapter;
		return *this;
	}

	Book& Book::operator-=(double discount)
	{
		if (m_price > discount) m_price -= discount;
		else m_price = 0;
		return *this;
	}

	std::ostream& operator<<(std::ostream& os, const Book& book)
	{
		return book.display(os);
	}

}
