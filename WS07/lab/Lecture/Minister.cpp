#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Minister.h"
using namespace std;
namespace sdds {
	Minister::Minister(const char* id, int age, int year, const char* name, const char* district) : MemberParliament(id, age) // 자식 클래스의 생성자 부를 때, 부모 클래스의 생성자 먼저 불러라.
	{
		MemberParliament::NewDistrict(district); // 부모 클래스의 NewDistrict를 불러오겠다.(없어도 되지만 의미 강조). 자식 클래스가 부모 클래스와 동일한 함수를 갖고 있다면(오버라이드), 자식의 함수를 가져옴. 습관적으로 부모 함수를 가져올 때는 resolution 쓰는게 좋다.
		strcpy(m_pm, name);
		m_year = year;
	}
	void Minister::changePM(const char* pm)
	{
		strcpy(m_pm, pm);
	}
	void Minister::assumeOffice(double year)
	{
		m_year = year;
	}
	std::ostream& Minister::write(std::ostream& os) const
	{
		MemberParliament::write(os);
		os << " | " << m_pm << '/' << m_year;
		return os;
	}
	std::istream& Minister::read(std::istream& in)
	{
		MemberParliament::read(in);
		cout << "Reports TO: ";
		in >> m_pm;
		cout << "Year Assumed Office: ";
		in >> m_year;
		return in;
	}
	std::ostream& operator<<(std::ostream& os, const Minister& minister)
	{
		return minister.write(os);
	}
	std::istream& operator>>(std::istream& is, Minister& minister)
	{
		return minister.read(is);
	}
}