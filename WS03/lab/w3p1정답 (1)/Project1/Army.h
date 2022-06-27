#ifndef SDDS_ARMY_H
#define SDDS_ARMY_H
#define MAX_NAME_LEN 50
namespace sdds {
	class Army
	{
		char m_nation[MAX_NAME_LEN];
		int m_noOfUnits;
		double m_powOfArmy;
	public:
		void setEmpty();
		void createArmy(const char* country, double pow, int troops);
		void updateUnits(int troops);
		const char* checkNationality() const;
		int checkCapacity() const;
		double checkPower() const;
		bool isEmpty() const;
		bool isStrongerThan(const Army& army)const;
	};
	void battle(Army& arm1, Army& arm2);
	void displayDetails(const Army* armies, int size);
}

#endif 



