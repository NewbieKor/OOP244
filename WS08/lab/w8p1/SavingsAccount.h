#ifndef SDDS_SAVINGSACCOUNT_H
#define SDDS_SAVINGSACCOUNT_H
#include "Account.h"
namespace sdds {
	class SavingsAccount :public Account {
		double m_interestRate;
	public:
		SavingsAccount(double balance, double interestRate);
		void monthEnd();
		void display(std::ostream&) const;
	};
}
#endif // !SDDS_SAVINGSACCOUNT_H
