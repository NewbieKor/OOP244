#include <iomanip>
#include "SavingsAccount.h"
using namespace std;
sdds::SavingsAccount::SavingsAccount(double balance, double interestRate) : Account(balance)
{
	if (interestRate > 0) {
		m_interestRate = interestRate;
	}
	else {
		m_interestRate = 0.0;
	}
}

void sdds::SavingsAccount::monthEnd()
{
	double interest = Account::balance() * m_interestRate;
	Account::credit(interest);
}

void sdds::SavingsAccount::display(std::ostream& os) const
{
	os << setprecision(2);
	os << fixed;
	os << "Account type: Savings" << endl;
	os << "Balance: $" << Account::balance() << endl;
	os << "Interest Rate (%): " << m_interestRate * 100 << endl;
}
