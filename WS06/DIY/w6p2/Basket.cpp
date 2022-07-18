#include <iomanip>
#include "Basket.h"
using namespace std;
namespace sdds {
	Basket::Basket()
	{
		m_fruits = nullptr;
		m_cnt = 0;
		m_price = 0;
	}
	Basket::Basket(Fruit* fruits, int size, double price)
	{
		if (fruits && size > 0 && price>=0) {
			m_cnt = size;
			m_fruits = new Fruit[m_cnt];
			for (int i = 0; i < m_cnt; i++) {
				m_fruits[i] = fruits[i];
			}
			m_price = price;
		}
		else {
			m_fruits = nullptr;
			m_cnt = 0;
			m_price = 0;
		}
	}
	Basket::Basket(const Basket& I)
	{
		m_fruits = nullptr;
		m_cnt = 0;
		m_price = 0;
		*this = I;
	}
	Basket::~Basket()
	{
		delete[] m_fruits;
	}
	Basket& Basket::operator=(const Basket& other)
	{
		if (this != &other) {
			delete[] m_fruits;
			m_cnt = other.m_cnt;
			m_fruits = new Fruit[m_cnt];
			for (int i = 0; i < m_cnt; i++) {
				m_fruits[i] = other.m_fruits[i];
			}
			m_price = other.m_price;
		}
		return *this;
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
		for (int i = 0; i < m_cnt; i++) {
			temp[i] = m_fruits[i];
		}
		temp[m_cnt++] = fruit;
		delete[] m_fruits;
		m_fruits = temp;
		return *this;
	}
	
	

	std::ostream& operator<<(std::ostream& os, const Basket& basket)
	{
		if (basket) {
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
