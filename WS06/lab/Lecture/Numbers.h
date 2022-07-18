#ifndef SDDS_NUMBERS_H_
#define SDDS_NUMBERS_H_
#include <iostream>
namespace sdds {
   class Numbers {
      double* m_numbers; // 배열
      char* m_filename;  // 문자열
      bool m_isOriginal; // 기본적으로 false로 설정되어있음.
      int m_numCount;    // 배열 갯수
      bool isEmpty()const;
      void setEmpty();
      void setFilename(const char* filename);
      void sort();
   public:
      Numbers();
      Numbers(const char* filename);
      Numbers(const Numbers& I); // copy constructor. 
      int numberCount() const;
      bool load();
      void save() const;
      Numbers& operator+=(double val);
      std::ostream& display(std::ostream& ostr) const;
      double average()const;
      double max()const;
      double min()const;
      Numbers& operator=(const Numbers& other); // copy assignment 
      ~Numbers();
   };
   std::ostream& operator<<(std::ostream& os, const Numbers& N);
   std::istream& operator>>(std::istream& istr, Numbers& N); // 
}
#endif // !SDDS_NUMBERS_H_

