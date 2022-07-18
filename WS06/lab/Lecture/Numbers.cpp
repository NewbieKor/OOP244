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
      m_isOriginal = true; // 원본일 때 = true, 복사본일 때 = false
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
       m_isOriginal = false; // 복사본임(원본이 아님)
       *this = I; // 현재 오브젝트에다가 I를 대입(copy assignment operator사용)
   }
   int Numbers::numberCount() const // incapable of modifying the curent object
   {
       ifstream istr(m_filename); // 파일로부터 문자열을 읽어옴. 앞으로 계속 나옴.
       // ifstream의 생성자를 불러온다. istr이라는 인스턴스 생성.
       // ofstream은 파일 쓰기, ifstream은 파일 읽기.
       // ofstream은 ostream에서 상속받은 자식.
       char ch; 
       int lineCount = 0; // 배열 길이
       while (istr) { // eof 캐릭터 읽으면 false 반환함.
           ch = istr.get(); // 커서 하나 씩 이동(캐릭터 하나 씩 읽음). 그리고 그 캐릭터를 반환해서 ch에 입력.
           if (ch == '\n') lineCount++;
       }
       return lineCount;
   }
   bool Numbers::load() // 동적 할당된 배열에 때려넣는 함수.
   {
       bool result = false; // 리턴 하나만 사용하기 위해 bool 변수 사용.
       if (m_numCount > 0) {
           m_numbers = new double[m_numCount];
           ifstream istr(m_filename); 
           int i=0;
           while(istr){ // 중요(true면 아직 eof 안 읽었다는 이야기임)
               istr >> m_numbers[i]; // 데이터 하나씩 알아서 읽어서 각 배열 요소에 넣음.
               if (istr) i++;
           }
           result = (i == m_numCount);
       }

       return result;
   }
   void Numbers::save() const
   {
       if (m_isOriginal && !isEmpty()) {
           ofstream ostr(m_filename); // 파일에다가 기록하는 객체. 디폴트는 항상 덮어쓰기.
           for (int i = 0; i < m_numCount; i++) {
               ostr << m_numbers[i] << endl;
           }
       }
   }

   Numbers& Numbers::operator+=(double val) // val값 읽어서 현재 오브젝트에 
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
       if (this != &other) { //this는 현재 객체 주소. 같으면 할 필요 없음
           delete[] m_numbers;
           m_numCount = other.m_numCount;
           /*m_filename = other.m_filename;
           m_isOriginal = false;*/ // 애매해서 주석처리하심
           // 인스트럭션에 안나와있음. 하지만 정석으로는 모든 멤버들을 복사해주는 것임.
           m_numbers = new double[m_numCount];
           for (int i = 0; i < m_numCount; i++) {
               m_numbers[i] = other.m_numbers[i];
           }
           
       }
       return *this; // 체인을 위해서 
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
