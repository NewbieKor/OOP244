#ifndef SDDS_CHEQUINGACCOUNT_H
#define SDDS_CHEQUINGACCOUNT_H
#include "Account.h"
namespace sdds {
	class ChequingAccount : public Account {
		double m_transactionFee;
		double m_monthlyFee;
	public:
		ChequingAccount(double, double, double);
		bool credit(double);
		bool debit(double);
		void monthEnd();
		void display(std::ostream&) const;
	};
}

#endif // !SDDS_CHEQUINGACCOUNT_H
