#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <fstream>
#include "Numbers.h"
#include "Numbers.h"  // intentional
using namespace std;
namespace sdds {

  
   Numbers::Numbers() { 
      setEmpty();
      m_isOriginal = false;
   }

   Numbers::Numbers(const char* filename) { 
      setEmpty();
      m_isOriginal = true; // ������ �� = true, ���纻�� �� = false
      setFilename(filename);
      m_numCount = numberCount();
      if (m_numCount == 0 || !load()) {
         delete[] m_numbers;
         delete[] m_filename;
         setEmpty();
         m_isOriginal = false; 
      }
      else {
         sort();
      }
   }
   Numbers::Numbers(const Numbers& I)
   {
       setEmpty();
       m_isOriginal = false; // ���纻��(������ �ƴ�)
       *this = I; // ���� ������Ʈ���ٰ� I�� ����(copy assignment operator���)
   }
   int Numbers::numberCount() const // incapable of modifying the curent object
   {
       ifstream istr(m_filename); // ���Ϸκ��� ���ڿ��� �о��. ������ ��� ����.
       // ifstream�� �����ڸ� �ҷ��´�. istr�̶�� �ν��Ͻ� ����.
       // ofstream�� ���� ����, ifstream�� ���� �б�.
       // ofstream�� ostream���� ��ӹ��� �ڽ�.
       char ch; 
       int lineCount = 0; // �迭 ����
       while (istr) { // eof ĳ���� ������ false ��ȯ��.
           ch = istr.get(); // Ŀ�� �ϳ� �� �̵�(ĳ���� �ϳ� �� ����). �׸��� �� ĳ���͸� ��ȯ�ؼ� ch�� �Է�.
           if (ch == '\n') lineCount++;
       }
       return lineCount;
   }
   bool Numbers::load() // ���� �Ҵ�� �迭�� �����ִ� �Լ�.
   {
       bool result = false; // ���� �ϳ��� ����ϱ� ���� bool ���� ���.
       if (m_numCount > 0) {
           m_numbers = new double[m_numCount];
           ifstream istr(m_filename); 
           int i=0;
           while(istr){ // �߿�(true�� ���� eof �� �о��ٴ� �̾߱���)
               istr >> m_numbers[i]; // ������ �ϳ��� �˾Ƽ� �о �� �迭 ��ҿ� ����.
               if (istr) i++;
           }
           result = (i == m_numCount);
       }

       return result;
   }
   void Numbers::save() const
   {
       if (m_isOriginal && !isEmpty()) {
           ofstream ostr(m_filename); // ���Ͽ��ٰ� ����ϴ� ��ü. ����Ʈ�� �׻� �����.
           for (int i = 0; i < m_numCount; i++) {
               ostr << m_numbers[i] << endl;
           }
       }
   }

   Numbers& Numbers::operator+=(double val) // val�� �о ���� ������Ʈ�� 
   {
       double* temp = new double[m_numCount + 1];
       for (int i = 0; i < m_numCount; i++) {
           temp[i] = m_numbers[i];
       }
       temp[m_numCount++] = val;
       delete[] m_numbers;
       m_numbers = temp;
       sort();
       return *this;
   }

   ostream& Numbers::display(ostream& ostr) const
   {
       if (isEmpty()) {
           ostr << "Empty list";
       }
       else {
           ostr << "=========================" << endl;
           if (m_isOriginal) {
               ostr << m_filename << endl;
           }
           else {
               ostr << "*** COPY ***" << endl;
           }
           for (int i = 0; i < m_numCount; i++) {
               ostr << m_numbers[i] << (i<m_numCount-1?", ":"");
           }
           ostr << endl;
           ostr <<"-------------------------" << endl;
           ostr << "Total of " << m_numCount << " number(s)" << endl;
           ostr << "Largest number:  " << max() << endl;
           ostr << "Smallest number: " << min() << endl;
           ostr << "Average :        " << average() << endl;
           ostr << "=========================";
           
       }
       return ostr;
   }

  
   
   Numbers::~Numbers() {
      save();
      delete[] m_numbers;
      delete[] m_filename;
   }
   
   bool Numbers::isEmpty() const { 
      return m_numbers == nullptr;
   }

   void Numbers::setEmpty() { 
      m_numbers = nullptr;
      m_filename = nullptr;
      m_numCount = 0;
   }
   void Numbers::setFilename(const char* filename) { 
      delete[] m_filename;
      m_filename = new char[strlen(filename) + 1];
      strcpy(m_filename, filename);
   }
   void Numbers::sort() {
      int i, j;
      double temp;
      for (i = m_numCount - 1; i > 0; i--) {
         for (j = 0; j < i; j++) {
            if (m_numbers[j] > m_numbers[j + 1]) {
               temp = m_numbers[j];
               m_numbers[j] = m_numbers[j + 1];
               m_numbers[j + 1] = temp;
            }
         }
      }
   }

   double Numbers::average() const {
      double aver = 0.0;
      if (!isEmpty()) {
         for (int i = 0; i < m_numCount; i++)
            aver += m_numbers[i];
         aver = aver / m_numCount;
      }
      return aver;
   }
   double Numbers::min() const {
      double minVal = 0.0;
      if (!isEmpty()) {
         minVal = m_numbers[0];
         for (int i = 1; i < m_numCount; i++)
            if (minVal > m_numbers[i]) minVal = m_numbers[i];
      }
      return minVal;
   }
   Numbers& Numbers::operator=(const Numbers& other)
   {
       if (this != &other) { //this�� ���� ��ü �ּ�. ������ �� �ʿ� ����
           delete[] m_numbers;
           m_numCount = other.m_numCount;
           /*m_filename = other.m_filename;
           m_isOriginal = false;*/ // �ָ��ؼ� �ּ�ó���Ͻ�
           // �ν�Ʈ���ǿ� �ȳ�������. ������ �������δ� ��� ������� �������ִ� ����.
           m_numbers = new double[m_numCount];
           for (int i = 0; i < m_numCount; i++) {
               m_numbers[i] = other.m_numbers[i];
           }
           
       }
       return *this; // ü���� ���ؼ� 
   }
   double Numbers::max() const {
      double maxVal = 0.0;
      if (!isEmpty()) {
         maxVal = m_numbers[0];
         for (int i = 1; i < m_numCount; i++)
            if (maxVal < m_numbers[i]) maxVal = m_numbers[i];
      }
      return maxVal;
   }


   
   ostream& operator<<(ostream& os, const Numbers& N)
   {
       return N.display(os);
   }

   istream& operator>>(istream& istr, Numbers& N)
   {
       double val;
       istr >> val;
       N += val;
       return istr;
   }

}
