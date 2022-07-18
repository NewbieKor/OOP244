#ifndef SDDS_NUMBERS_H_
#define SDDS_NUMBERS_H_
#include <iostream>
namespace sdds {
   class Numbers {
      double* m_numbers; // �迭
      char* m_filename;  // ���ڿ�
      bool m_isOriginal; // �⺻������ false�� �����Ǿ�����.
      int m_numCount;    // �迭 ����
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

