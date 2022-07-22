#ifndef SDDS_IACCOUNT_H
#define SDDS_IACCOUNT_H
#include <iostream>
namespace sdds {
	class iAccount { // 인터페이스(interface): 순수 가상함수로만 이루어진 클래스.
	public:
		virtual bool credit(double) = 0;
		virtual bool debit(double) = 0;
		virtual void monthEnd() = 0;
		virtual void display(std::ostream&) const = 0;
		virtual ~iAccount() {}
	};
	iAccount* CreateAccount(const char*, double);
}
#endif // !SDDS_IACCOUNT_H
