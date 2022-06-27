#ifndef CLEANERBOT_H
#define CLEANERBOT_H
namespace sdds {
	class CleanerBot {
		char* m_location;
		double m_battery;
		int m_brush;
		bool m_isActive;
		void setEmpty();
	public:
		CleanerBot();
		CleanerBot(const char* location, double battery, int brush, bool isActive);
		~CleanerBot();
		void set(const char* location, double battery, int brush, bool isActive);
		void setLocation(const char* location);
		void setActive(bool isActive);
		const char* getLocation() const;
		double getBattery() const;
		int getBrush() const;
		bool isActive() const;
		bool isValid() const;
		void display() const;
	};
	int report(CleanerBot* bot, short num_bots);
	void sort(CleanerBot* bot, short num_bots);
}

#endif // !CLEANERBOT_H
