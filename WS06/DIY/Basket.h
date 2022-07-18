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

#ifndef SDDS_BASKET_H
#define SDDS_BASKET_H
#include <iostream>
namespace sdds
{
	struct Fruit
	{
		char m_name[30 + 1]; // the name of the fruit
		double m_qty;        // quantity in kilograms
	};
	class Basket
	{
		Fruit* m_fruits;
		int m_cnt;
		double m_price;
		void setEmpty();
	public:
		Basket();
		Basket(Fruit* fruits, int size, double price);
		Basket(const Basket& origin);
		Basket& operator=(const Basket& origin);
		~Basket();
		void setPrice(double price);
		operator bool()const;
		Basket& operator+=(Fruit fruit);
		friend std::ostream& operator<< (std::ostream& os, const Basket& basket);
	};

}

#endif // !SDDS_BASKET_H





