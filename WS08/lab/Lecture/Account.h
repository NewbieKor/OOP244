#ifndef SDDS_ACCOUNT_H
#define SDDS_ACCOUNT_H
#include "iAccount.h"
namespace sdds {
	class Account : public iAccount {
		double m_balance;
	public:
		Account(double balance); // 이 생성자(custom constructor)가 있기 때문에 defalt constructor는 존재하지 않음.
		bool credit(double amount);
		bool debit(double amount); // monthend랑 display 없음.
	protected:
		double balance() const;
	};
}
#endif // !SDDS_ACCOUNT_H