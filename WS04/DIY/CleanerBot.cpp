/*
*****************************************************************************
                          Workshop - #4 (P2)
Full Name  : Seonghoon Kim
Student ID#: 143080216
Email      : shkim61@myseneca.ca
Section    : NGG
Date	   : 06.13.2022

I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
#include "CleanerBot.h"

using namespace std;
namespace sdds
{
    void CleanerBot::setEmpty()
    {
        c_location = nullptr;
        c_battery = 0;
        c_brush = 0;
        c_isActive = false;
    }

    CleanerBot::CleanerBot()
    {
        setEmpty();
    }

    CleanerBot::CleanerBot(const char* location, double battery, int brush, bool isActive)
    {
        if (location && location[0] != '\0')
        {
            c_location = new char[strlen(location) + 1];
            strcpy(c_location, location);
            c_battery = battery;
            c_brush = brush;
            c_isActive = isActive;
        }
        else setEmpty();
    }

	CleanerBot::~CleanerBot()
	{
		delete[] c_location;
	}

	void CleanerBot::set(const char* location, double battery, int brush, bool isActive)
	{
		delete[] c_location;
		if (location && location[0] != '\0' && battery > 0 && brush > 0)
		{
			setLocation(location);
			c_battery = battery;
			c_brush = brush;
			c_isActive = isActive;
		}
		else setEmpty();
	}

	void CleanerBot::setLocation(const char* location)
	{
		if (location && location[0] != '\0')
		{
			c_location = new char[strlen(location) + 1];
			strcpy(c_location, location);
		}
	}

	void CleanerBot::setActive(bool isActive)
	{
		c_isActive = isActive;
	}

	const char* CleanerBot::getLocation() const
	{
		return c_location;
	}

	double CleanerBot::getBattery() const
	{
		return c_battery;
	}

	int CleanerBot::getBrush() const
	{
		return c_brush;
	}
	bool CleanerBot::isActive() const
	{
		return c_isActive;
	}

	bool CleanerBot::isValid() const
	{
		return c_location && c_location[0] != '\0' && c_battery > 0 && c_brush > 0;
	}

	void CleanerBot::display() const
	{
		cout << setprecision(1) << fixed;
		cout << "| " << setw(10) << left << c_location << " | " << setw(7) << right << c_battery << " | " << setw(18) << c_brush << " | " << setw(6) << left << (c_isActive ? "YES" : "NO") << " |" << endl;
	}

	int report(CleanerBot* bot, short num_bots)
	{
		short lessThan30 = 0;
		cout << "         ------ Cleaner Bots Report -----" << endl;
		cout << "     ---------------------------------------" << endl;
		cout << "| Location   | Battery |  Number of Brushes | Active |" << endl;
		cout << "|------------+---------+--------------------+--------|" << endl;
		for (short i = 0; i < num_bots; i++)
		{
			if (bot[i].isValid()) bot[i].display();
			if (bot[i].isValid() && bot[i].getBattery() < 30) lessThan30++;
		}
		cout << endl;
		if (lessThan30 > 0)
		{
			cout << "|====================================================|" << endl;
			cout << "| LOW BATTERY WARNING:                               |" << endl;
			cout << "|====================================================|" << endl;
			cout << "| Number of robots to be charged: " << lessThan30 << "                  |" << endl;
			cout << "| Sorting robots based on their available power:     |" << endl;
			sort(bot, num_bots);
			cout << "| Location   | Battery |  Number of Brushes | Active |" << endl;
			cout << "|------------+---------+--------------------+--------|" << endl;

			for (short i = 0; i < num_bots; i++)
			{
				if (bot[i].isValid()) bot[i].display();
			}
		}
		cout << "|====================================================|" << endl;

		return 0;
	}
	// refered to the existing workshop
	void sort(CleanerBot* bot, short num_bots)
	{
		short i, j;
		CleanerBot temp;
		for (i = num_bots - 1; i > 0; i--)
		{
			for (j = 0; j < i; j++)
			{
				if (bot[j].getBattery() < bot[j + 1].getBattery())
				{
					temp.set(bot[j].getLocation(), bot[j].getBattery(), bot[j].getBrush(), bot[j].isActive());
					bot[j].set(bot[j + 1].getLocation(), bot[j + 1].getBattery(), bot[j + 1].getBrush(), bot[j + 1].isActive());
					bot[j + 1].set(temp.getLocation(), temp.getBattery(), temp.getBrush(), temp.isActive());
				}
			}
		}
	}
}