#ifndef SDDS_BAR_H
#define SDDS_BAR_H
namespace sdds {
	class Bar
	{
		char m_title[21];
		char m_fillChar;
		int m_sampleVal;
	public:
		void setEmpty();
		void set(const char* title, char fillchar, int sampleVal);
		bool isValid();
		void draw()const;
	};

}


#endif // !SDDS_BAR_H


