#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "BarChart.h"
using namespace std;
namespace sdds {
	bool BarChart::isValid() const
	{
		return m_titleOfChart && m_bars && m_noOfAddedSamples == m_sizeOfBars;
	}
	void BarChart::init(const char* title, int noOfSamples, char fill)
	{
		m_titleOfChart = new char[strlen(title) + 1];
		strcpy(m_titleOfChart, title);
		m_sizeOfBars = noOfSamples;
		m_bars = new Bar[m_sizeOfBars];
		m_fillChar = fill;
		m_noOfAddedSamples = 0;

	}
	void BarChart::add(const char* bar_title, int value)
	{
		m_bars[m_noOfAddedSamples++].set(bar_title, m_fillChar, value);
	}
	void BarChart::draw() const
	{
		bool isAllValid = true;
		if (isValid()) {// isValid();만 쓰면 되도록 수정해야됨.
			for (int i = 0; i < m_sizeOfBars && isAllValid; i++) {
				if (!m_bars[i].isValid()) {
					isAllValid = false;
				}
			}
		}
		else isAllValid = false;

		if (isAllValid) {
			cout << m_titleOfChart << endl;
			cout << "-----------------------------------------------------------------------" << endl;
			for (int i = 0; i < m_sizeOfBars; i++) {
				m_bars[i].draw();
			}
			cout << "-----------------------------------------------------------------------" << endl;
		}
		else {
			cout << "Invalid Chart!" << endl;
		}
		
	}
	void BarChart::deallocate()
	{
		delete[] m_titleOfChart;
		delete[] m_bars;
	}
}