#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Bar.h"
using namespace std;
namespace sdds {
	void Bar::setEmpty()
	{
		m_title[0] = '\0';
		m_sampleVal = -1;
	}
	void Bar::set(const char* title, char fillchar, int sampleVal)
	{
		if (title && title[0] != '\0' && sampleVal >= 0 && sampleVal <= 100) {
			strncpy(m_title, title, 20);
			m_fillChar = fillchar;
			m_sampleVal = sampleVal;
		}
		else setEmpty();
	}
	bool Bar::isValid()
	{
		return !(m_title[0] == '\0' && m_sampleVal == -1);
	}
	void Bar::draw() const
	{
		if (m_sampleVal >= 0 && m_sampleVal <= 100) {
			cout.setf(ios::left);
			cout.width(20);
			cout.fill('.');
			cout << m_title;
			cout << '|';
			cout.width(m_sampleVal / 2);
			cout.fill(m_fillChar);
			cout << m_fillChar;
			cout << endl;
		}
		
	}
}