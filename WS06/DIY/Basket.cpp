/*
*****************************************************************************
						  Workshop - #6 (P2)
Full Name  : Seonghoon Kim
Student ID#: 143080216
Email      : shkim61@myseneca.ca
Section    : NGG
Date	   : 07.13.2022

I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#include <iomanip>
#include "Basket.h"
using namespace std;
namespace sdds
{
	void Basket::setEmpty()
	{
		m_fruits = nullptr;
		m_cnt = 0;
		m_price = 0.0;
	}

	Basket::Basket()
	{
		setEmpty();
	}

	Basket::Basket(Fruit* fruits, int size, double price)
	{
		if (fruits && size > 0 && price > 0)
		{
			m_cnt = size;
			m_fruits = new Fruit[m_cnt];
			for (int i = 0; i < m_cnt; i++) m_fruits[i] = fruits[i];
			m_price = price;
		}
		else setEmpty();
	}

	Basket::Basket(const Basket& origin)
	{
		setEmpty();
		*this = origin;
	}

	Basket& Basket::operator=(const Basket& origin)
	{
		if (this != &origin) 
		{
			if (m_fruits != nullptr) delete[] m_fruits;
			m_cnt = origin.m_cnt;
			m_fruits = new Fruit[m_cnt];
			for (int i = 0; i < m_cnt; i++) { m_fruits[i] = origin.m_fruits[i]; }
			m_price = origin.m_price;
		}
		return *this;
	}

	Basket::~Basket()
	{
		delete[] m_fruits;
	}

	void Basket::setPrice(double price)
	{
		m_price = price;
	}

	Basket::operator bool() const
	{
		return m_cnt > 0;
	}

	Basket& Basket::operator+=(Fruit fruit)
	{
		Fruit* temp = new Fruit[m_cnt + 1];
		for (int i = 0; i < m_cnt; i++) temp[i] = m_fruits[i];
		temp[m_cnt++] = fruit;
		delete[] m_fruits;
		m_fruits = temp;
		return *this;
	}

	std::ostream& operator<<(std::ostream& os, const Basket& basket)
	{
		if (basket.m_cnt > 0) {
			os << "Basket Content:" << endl;
			for (int i = 0; i < basket.m_cnt; i++) {
				os << setprecision(2) << fixed;
				os << setw(10) << right << basket.m_fruits[i].m_name << ": " << basket.m_fruits[i].m_qty << "kg" << endl;
			}
			
			os << "Price: " << basket.m_price << endl;
		}
		else {
			os << "The basket is empty!" << endl;
		}
		
		return os;
	}

}

