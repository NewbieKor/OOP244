#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include "Army.h"

using namespace std;
namespace sdds {
	Army::Army() //디폴트 생성자
	{
		
	}
	Army::Army(sdds::Army& other)
	{
		//this 현재 인스턴스의 주소
		*this = other;
		
	}
	Army::~Army()
	{
		cout << "파괴자 호출!!" << endl;
	}
	Army& Army::operator=(sdds::Army& other)
	{
		delete[] m_nation;
		m_nation = new char[strlen(other.m_nation) + 1];
		strcpy(m_nation, other.m_nation);
		m_noOfUnits = other.m_noOfUnits;
		m_power = other.m_power;
		return *this;
	}
	void Army::setEmpty()
	{
		m_nation[0] = '\0';
		m_noOfUnits = 0;
		
	}
	
	void Army::createArmy(const char* country, double pow, int troops)
	{
		if (country && country[0] != '\0' && troops > 0 && pow > 0) {
			strncpy(m_nation, country, 49);
			m_noOfUnits = troops;
			m_power = pow;
		}
		else {
			setEmpty();
		}
	}

	void Army::updateUnits(int troops)
	{
		m_noOfUnits += troops;
		m_power += 0.25 * troops;
	}

	const char* Army::checkNationality() const
	{
		return m_nation;
	}

	bool Army::isEmpty() const
	{
		return m_nation && m_nation[0] == '\0' && m_noOfUnits == 0;
	}

	bool Army::isStrongerThan(const Army& army) const
	{
		return false;
	}

	

	void battle(Army& arm1, Army& arm2)
	{
		
	}

	void displayDetails(const Army* armies, int size)
	{
		cout << "Armies reporting to battle:" << endl;
		for (int i = 0; i < size; i++) {
			

		}
	}

}

