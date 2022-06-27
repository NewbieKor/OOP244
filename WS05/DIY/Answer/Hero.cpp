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
			strncpy(m_name, name, MAX_NAME_LENGTH - 1); 
			m_noOfPowers = noOfPowers;
			m_powers = new Power[m_noOfPowers]; 
			for (int i = 0; i < m_noOfPowers; i++) 
			{
				m_powers[i] = powers[i];
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
		Power* temp = m_powers;
		m_powers = new Power[m_noOfPowers + 1];
		for (int i = 0; i < m_noOfPowers; i++)
		{
			m_powers[i] = temp[i];
		}
		m_powers[m_noOfPowers++] = power;
		updatePowLev();
		delete[] temp;
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