#ifndef SDDS_HERO_H
#define SDDS_HERO_H
#include <iostream>
#include "Power.h"
namespace sdds {
	class Hero {
		char m_name[MAX_NAME_LENGTH+1];
		Power* m_powers;
		int m_noOfPowers;
		int m_powLevel;
		void setEmpty();
		void updatePowLev();
	public:
		Hero();
		Hero(const char* name, Power* powers, int noOfPowers);
		~Hero();
		std::ostream& display() const;
		Hero& operator+=(Power& power);
		Hero& operator-=(const int& powLevel);
		int getPowLevel() const;
	};
	bool operator<(const Hero& hero1, const Hero& hero2);
	bool operator>(const Hero& hero1, const Hero& hero2);
	void operator>>(Power& power, Hero& hero);
	Hero& operator<<(Hero& hero, Power& power); // Hero&를 반환 함으로써 체인이 가능해진다.
	std::ostream& operator<<(std::ostream& os, const Hero& hero);
}
#endif // !SDDS_HERO_H
