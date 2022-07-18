#ifndef SDDS_BASKET_H
#define SDDS_BASKET_H
#include <iostream>
namespace sdds {
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
	public:
		Basket();
		Basket(Fruit* fruits, int size, double price);
		Basket(const Basket& I); // copy constructor
		~Basket();
		Basket& operator=(const Basket& other);
		void setPrice(double price);
		operator bool()const;
		Basket& operator+=(Fruit fruit);
		friend std::ostream& operator<<(std::ostream& os, const Basket& basket);
	};
	
	
}
#endif // !SDDS_BASKET_H


