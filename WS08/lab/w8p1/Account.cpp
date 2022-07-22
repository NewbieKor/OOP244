#include "Account.h"
namespace sdds {
	Account::Account(double balance)
	{
		if (balance > 0) {
			m_balance = balance;
		}
		else {
			m_balance = 0.0;
		}
	}
	bool Account::credit(double amount)
	{
		bool result = false;
		if (amount > 0) {
			m_balance += amount;
			result = true;
		}
		return result;
	}
	bool Account::debit(double amount)
	{
		bool result = false;
		if (amount > 0) {
			m_balance -= amount;
			result = true;
		}
		return result;
	}
	double Account::balance() const
	{
		return m_balance;
	}
}