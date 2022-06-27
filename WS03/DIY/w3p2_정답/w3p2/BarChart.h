#ifndef SDDS_BARCHART_H
#define SDDS_BARCHART_H
#include "Bar.h"
namespace sdds {
	class BarChart
	{
		char* m_titleOfChart;
		Bar* m_bars;
		char m_fillChar;
		int m_sizeOfBars;
		int m_noOfAddedSamples;
	public:
		bool isValid() const;
		void init(const char* title, int noOfSamples, char fill);
		void add(const char* bar_title, int value);
		void draw()const;
		void deallocate();
	};
}
#endif // !SDDS_BARCHART_H



