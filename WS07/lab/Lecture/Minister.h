#ifndef SDDS_MINISTER_H
#define SDDS_MINISTER_H
#include <iostream>
#include "MemberParliament.h"
namespace sdds {
	class Minister : public MemberParliament
	{
		char m_pm[50];
		int m_year;
	public:
		Minister(const char* id, int age, int year, const char* name, const char* district); // 헤더파일에는 부모 클래스 생성자 쓰는게 아님. 자식 클래스 생성자 부를 때 부모 클래스 생성자 부르기 때문에 정의 부분(실행 파일)에 작성.
		void changePM(const char* pm);
		void assumeOffice(double year);
		std::ostream& write(std::ostream& os) const;
		std::istream& read(std::istream& in);
	};
	std::ostream& operator<<(std::ostream& os, const Minister& minister);
	std::istream& operator>>(std::istream& is, Minister& minister);

}

#endif // !SDDS_MINISTER_H


