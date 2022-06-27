#ifndef SDDS_BOOK_H_
#define SDDS_BOOK_H_
#include <iostream>
#include "Chapter.h"

namespace sdds {
   const int MAX_NUM_CHAPTERS = 10;
   const int MAX_BOOK_TITEL = 40;
   const int MAX_AUTHOR_NAME = 20;
    class Book
    {
        char m_title[MAX_BOOK_TITEL+1];
        char m_author[MAX_AUTHOR_NAME+1];
        int m_num_chapters;
        int m_num_pages;
        double m_price;
        Chapter m_chapters[MAX_NUM_CHAPTERS];

        void init_book();
        int add_chapter(Chapter* chapter);
    public:
        Book();
        Book(const char* title_);
        Book(const char* title_, const char* author_, double price_);
        void summary(); // Print a book summary
        Book operator ++(int);
        std::ostream& display(std::ostream& os)const;
        operator int() const;
        operator bool() const;
        operator double() const;
        operator const char* () const;
        bool operator !() const;
        Book& operator+=(Chapter& chapter);
        Book& operator-=(double discount);
    };
    std::ostream& operator<<(std::ostream& os, const Book& book); // 주어(왼쪽 피연산자)가 ostream(객체:cout)이라서 멤버함수가 아님. 그래서 클래스 밖에 위치.
  

}
#endif
