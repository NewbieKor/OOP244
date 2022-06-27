#ifndef SDDS_ARMY_H
#define SDDS_ARMY_H
#define MAX_NAME_LEN 50

namespace sdds {
	class Army {
		char* m_nation;
		int m_noOfUnits;
		double m_power;

	public:
		Army();
		Army(sdds::Army& other);
		~Army();
		Army& operator=(sdds::Army& other);
		void setEmpty();
		void createArmy(const char* country, double pow, int troops);
		void updateUnits(int troops);
		const char* checkNationality() const;
		bool isEmpty() const;
		bool isStrongerThan(const Army& army)const;
	};
	
	void battle(Army& arm1, Army& arm2);
	void displayDetails(const Army* armies, int size);
}

#endif 



