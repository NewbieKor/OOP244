#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
//#include <iomanip> //?
#include "Army.h"

using namespace std;
namespace sdds {
	void Army::setEmpty()
	{
		m_nation[0] = '\0';
		m_noOfUnits = 0;
	}

	void Army::createArmy(const char* country, double pow, int troops)
	{
		if (country && strlen(country) > 0 && pow > 0 && troops > 0) {
			strncpy(m_nation, country, MAX_NAME_LEN);
			m_noOfUnits = troops;
			m_powOfArmy = pow;
		}
		else {
			setEmpty();
		}
	}

	void Army::updateUnits(int troops)
	{
		m_noOfUnits += troops;
		m_powOfArmy += 0.25 * troops;
	}

	const char* Army::checkNationality() const
	{
		return m_nation;
	}

	int Army::checkCapacity() const
	{
		return m_noOfUnits;
	}

	double Army::checkPower() const
	{
		return m_powOfArmy;
	}

	bool Army::isEmpty() const
	{
		return m_nation[0] == '\0' && m_noOfUnits == 0;
	}

	bool Army::isStrongerThan(const Army& army) const
	{
		return m_powOfArmy > army.m_powOfArmy;
	}

	void battle(Army& arm1, Army& arm2)
	{
		//valid 한지 isEmpty를 통해 판단!
		cout << "In battle of " << arm1.checkNationality() << " and " << arm2.checkNationality() << ", ";
		if (arm1.isStrongerThan(arm2)) {
			arm2.updateUnits((int)(-arm2.checkCapacity() / 2));
			cout << arm1.checkNationality();
		}
		else {
			arm1.updateUnits((int)(-arm1.checkCapacity() / 2));
			cout << arm2.checkNationality();
		}
		cout << " is victorious!" << endl;
	}

	void displayDetails(const Army* armies, int size)
	{
		cout.setf(ios::fixed);
		cout.precision(1);
		cout << "Armies reporting to battle: " << endl;
		for (int i = 0; i < size; i++) {
			if (!armies[i].isEmpty()) {
				cout << "Nationality: " << armies[i].checkNationality() << ", ";
				cout << "Units Count: " << armies[i].checkCapacity() << ", ";
				cout << "Power left: " << armies[i].checkPower() << endl;
			}
			
		}
	}

}

