#ifndef SDDS_MEMBERPARLIAMENT_H
#define SDDS_MEMBERPARLIAMENT_H
#include <iostream>
namespace sdds {
	class MemberParliament
	{
		char m_id[32];
		char m_district[64];
		int m_age;
	public:
		MemberParliament(const char* id, int age);
		void NewDistrict(const char* district);
		std::ostream& write(std::ostream& os) const;
		std::istream& read(std::istream& in);
	};
	std::ostream& operator<<(std::ostream& os, const MemberParliament& member);
	std::istream& operator>>(std::istream& is, MemberParliament& member);
	
}

#endif

