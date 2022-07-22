#ifndef SDDS_ACCOUNT_H
#define SDDS_ACCOUNT_H
#include "iAccount.h"
namespace sdds {
	class Account : public iAccount {
		double m_balance;
	public:
		Account(double balance); // �� ������(custom constructor)�� �ֱ� ������ defalt constructor�� �������� ����.
		bool credit(double amount);
		bool debit(double amount); // monthend�� display ����.
	protected:
		double balance() const;
	};
}
#endif // !SDDS_ACCOUNT_H