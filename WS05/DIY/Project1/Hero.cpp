#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Hero.h"
using namespace std;
namespace sdds {
	void Hero::setEmpty()
	{
		m_name[0] = '\0';
		m_powers = nullptr;
		m_noOfPowers = 0;
		m_powLevel = 0;
	}
	void Hero::updatePowLev()
	{
		int total = 0;
		for (int i = 0; i < m_noOfPowers; i++)
		{
			total += m_powers[i].checkRarity();
		}
		m_powLevel = total * m_noOfPowers;
	}

	Hero::Hero()
	{
		setEmpty();
	}
	Hero::Hero(const char* name, Power* powers, int noOfPowers)
	{
		if (name && name[0] != '\0' && powers && noOfPowers > 0) {
			strncpy(m_name, name, MAX_NAME_LENGTH); // 정적으로 할당되었으므로 최대값을 정해주기 위해 strncpy를 쓴다.
			m_noOfPowers = noOfPowers;
			m_powers = new Power[m_noOfPowers]; // 동적 메모리 할당
			for (int i = 0; i < m_noOfPowers; i++)
			{
				m_powers[i] = powers[i]; // 각 요소에 값 대입
			}
			updatePowLev();
		}
		else setEmpty();
	}

	Hero::~Hero()
	{
		delete[] m_powers;
	}

	std::ostream& Hero::display() const
	{
		cout << "Name: " << m_name << endl;
		displayDetails(m_powers, m_noOfPowers);
		cout << "Power Level: " << m_powLevel;
		return cout;
	}

	Hero& Hero::operator+=(Power& power)
	{
		Power* temp = m_powers; // temp를 m_powers(포인터)가 가리키는 곳을 가리키게 함.
		m_powers = new Power[m_noOfPowers + 1]; // m_powers를 재할당(새로운 곳) 
		for (int i = 0; i < m_noOfPowers; i++)
		{
			m_powers[i] = temp[i]; // 요소들을 복사 (문자열도 복사 됨)
		}
		m_powers[m_noOfPowers++] = power; // 마지막 요소에 power값 대입. 이 라인 뒤에 파워 갯수 하나 추가.
		updatePowLev(); // 파워 레벨 갱신
		delete[] temp; // 스코프가 끝나기 전에 할당 해제.(temp생명은 이 함수에서 안에서만 존재)
		return *this;
	}

	Hero& Hero::operator-=(const int& powLevel)
	{
		m_powLevel -= powLevel;
		return *this;
	}

	int Hero::getPowLevel() const
	{
		return m_powLevel;
	}

	bool operator<(const Hero& hero1, const Hero& hero2)
	{
		return hero1.getPowLevel() < hero2.getPowLevel();
	}

	bool operator>(const Hero& hero1, const Hero& hero2)
	{
		return hero1.getPowLevel() > hero2.getPowLevel();
	}

	void operator>>(Power& power, Hero& hero)
	{
		hero += power;
	}

	Hero& operator<<(Hero& hero, Power& power)
	{
		hero += power;
		return hero;
	}
	
	std::ostream& operator<<(std::ostream& os, const Hero& hero)
	{
		return hero.display();
	}



}