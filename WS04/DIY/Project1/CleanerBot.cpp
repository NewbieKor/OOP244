#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include <iomanip>
#include "CleanerBot.h"
using namespace std;
namespace sdds {
	void CleanerBot::setEmpty()
	{
		m_location = nullptr;
		m_battery = 0;
		m_brush = 0;
		m_isActive = false;
	}
	CleanerBot::CleanerBot() // 생성자(인스턴스가 생성될 때 자동으로 컴파일러가 호출함).
	{
		setEmpty();
	}

	CleanerBot::CleanerBot(const char* location, double battery, int brush, bool isActive)
	{
		setEmpty();
		set(location, battery, brush, isActive);
	}
	CleanerBot::~CleanerBot()
	{
		delete[] m_location;     
	}
	bool CleanerBot::operator~()
	{
		return false;
	}
	CleanerBot& CleanerBot::operator=(const CleanerBot& other)
	{
		cout << "= 오퍼레이터 호출!" << endl;
		return *this;
	}
	void CleanerBot::set(const char* location, double battery, int brush, bool isActive)
	{
		delete[] m_location;
		if (location && location[0] != '\0' && battery > 0 && brush > 0) {
			setLocation(location);
			m_battery = battery;
			m_brush = brush;
			setActive(isActive);
		}
		else setEmpty();
	}
	void CleanerBot::setLocation(const char* location)
	{
		if (location && location[0] != '\0') {
			m_location = new char[strlen(location) + 1];
			strcpy(m_location, location);
		}
	}
	void CleanerBot::setActive(bool isActive)
	{
		m_isActive = isActive;
	}
	const char* CleanerBot::getLocation() const
	{
		return m_location;
	}
	double CleanerBot::getBattery() const
	{
		return m_battery;
	}
	int CleanerBot::getBrush() const
	{
		return m_brush;
	}
	bool CleanerBot::isActive() const
	{
		return m_isActive;
	}
	bool CleanerBot::isValid() const
	{
		return m_location && m_location[0] != '\0' && m_battery > 0 && m_brush > 0;
	}
	void CleanerBot::display() const
	{
		cout << setprecision(1) << fixed; //fixed : 소수점만 precision이 보도록. //left, right도 다음 left, right 나올 떄까지 적용. 
		cout << "| " << setw(10) << left << m_location << " | " << setw(7) << right << m_battery << " | " << setw(18) << m_brush << " | " << setw(6) << left << (m_isActive ? "YES" : "NO")<<" |"<< endl; //삼항 연산자 (ternary expression) // setw 일회성.


	}
	int report(CleanerBot* bot, short num_bots)
	{
		short lowBatteryCount = 0;
		cout << "         ------ Cleaner Bots Report -----" << endl;
		cout << "     ---------------------------------------" << endl;
		cout << "| Location   | Battery |  Number of Brushes | Active |" << endl;
		cout << "|------------+---------+--------------------+--------|" << endl;
		for (short i = 0; i < num_bots; i++) {
			if (bot[i].isValid())
			{
				bot[i].display();
				if (bot[i].getBattery() < 30) lowBatteryCount++;
			}
			
		}
		cout << endl;
		if (lowBatteryCount > 0) {
			cout << "|====================================================|" << endl;
			cout << "| LOW BATTERY WARNING:                               |" << endl;
			cout << "|====================================================|" << endl;
			cout << "| Number of robots to be charged: " << lowBatteryCount << "                  |" << endl;
			cout << "| Sorting robots based on their available power:     |" << endl;
			sort(bot, num_bots);			
			cout << "| Location   | Battery |  Number of Brushes | Active |" << endl;
			cout << "|------------+---------+--------------------+--------|" << endl;
			
			for (short i = 0; i < num_bots; i++) {
				if (bot[i].isValid()) bot[i].display();
			}
		}
		cout << "|====================================================|" << endl;
		

		return 0;
	}
	void sort(CleanerBot* bot, short num_bots) //bubble sort
	{
		short i, j;
		CleanerBot temp;
		for (i = num_bots - 1; i > 0; i--) {
			for (j = 0; j < i; j++) {
				if (bot[j].getBattery() < bot[j + 1].getBattery()) {
					/*temp = bot[j];*/
					temp.set(bot[j].getLocation(), bot[j].getBattery(), bot[j].getBrush(), bot[j].isActive());

					/*bot[j] = bot[j + 1];*/
					bot[j].set(bot[j+1].getLocation(), bot[j+1].getBattery(), bot[j+1].getBrush(), bot[j+1].isActive());

					/*bot[j + 1] = temp;*/
					bot[j + 1].set(temp.getLocation(), temp.getBattery(), temp.getBrush(), temp.isActive());
				}
			}
		}
	}
}