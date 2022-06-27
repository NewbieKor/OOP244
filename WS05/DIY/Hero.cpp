/*
*****************************************************************************
						  Workshop - #5 (P2)
Full Name  : Seonghoon Kim
Student ID#: 143080216
Email      : shkim61@myseneca.ca
Section    : NGG
Date	   : 06.19.2022

I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Hero.h"

using namespace std;
namespace sdds
{
	void Hero::setEmpty()
	{
		m_nameOfHero[0] = '\0';
		m_powerSet = nullptr;
		m_noOfPowers = 0;
		m_powerLevel = 0;
	}

	void Hero::setLevel()
	{
		int sum = 0;
		for (int i = 0; i < m_noOfPowers; i++) sum += m_powerSet[i].checkRarity();
		m_powerLevel = sum * m_noOfPowers;
	}

	Hero::Hero()
	{
		setEmpty();
	}

	Hero::Hero(const char* name, Power* powers, int noOfpowers)
	{
		if (name && name[0] != '\0' && powers && noOfpowers)
		{
			strncpy(m_nameOfHero, name, MAX_NAME_LENGTH);
			m_noOfPowers = noOfpowers;
			m_powerSet = new(nothrow) Power[m_noOfPowers];
			if (m_powerSet)
			{
				for (int i = 0; i < m_noOfPowers; i++) m_powerSet[i] = powers[i];
			}
			setLevel();
		}
		else setEmpty();
	}

	Hero::~Hero()
	{
		delete[] m_powerSet;
	}

	std::ostream& Hero::display() const
	{
		cout << "Name: " << m_nameOfHero << endl;
		displayDetails(m_powerSet, m_noOfPowers);
		cout << "Power Level: " << m_powerLevel;
		return cout;
	}

	Hero& Hero::operator+=(Power& pow)
	{
		Power* temp = m_powerSet;
		m_powerSet = new(nothrow) Power[m_noOfPowers + 1];
		if (m_powerSet)
		{
			for (int i = 0; i < m_noOfPowers; i++) m_powerSet[i] = temp[i];
			m_powerSet[m_noOfPowers++] = pow;
			setLevel();
		}
		delete[] temp;
		return *this;
	}

	Hero& Hero::operator-=(const int& level)
	{
		m_powerLevel -= level;
		return *this;
	}

	int Hero::getPowerLevel() const
	{
		return m_powerLevel;
	}

	bool operator<(Hero& hero1, Hero& hero2)
	{
		return hero1.getPowerLevel() < hero2.getPowerLevel();
	}

	bool operator>(Hero& hero1, Hero& hero2)
	{
		return hero1.getPowerLevel() > hero2.getPowerLevel();
	}
	void operator>>(Power& power, Hero& hero)
	{
		hero += power;
	}
	void operator<<(Hero& hero, Power& power)
	{
		hero += power;
	}
	std::ostream& operator<<(std::ostream& os, const Hero& hero)
	{
		return hero.display();
	}
}



