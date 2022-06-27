/*
*****************************************************************************
						  Workshop - #4 (P1)
Full Name  : Seonghoon Kim
Student ID#: 143080216
Email      : shkim61@myseneca.ca
Section    : NGG
Date	   : 06.10.2022

I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#ifndef	SDDS_CAR_H
#define SDDS_CAR_H
namespace sdds
{
	class Car
	{
		char* c_type;
		char* c_brand;
		char* c_model;
		int c_year;
		int c_code;
		double c_price;
		void resetInfo();
	public:
		Car();
		Car(const char* type, const char* brand, const char* model, int year = 2022, int code = 100, double price = 1);
		~Car();
		Car& setInfo(const char* type,
			const char* brand,
			const char* model,
			int year,
			int code,
			double price);
		void printInfo() const;
		bool isValid() const;
		bool isSimilarTo(const Car& car) const;
	};
	bool has_similar(const Car car[], const int num_cars);
	bool has_invalid(const Car car[], const int num_cars);
	void print(const Car car[], const int num_cars);
}
#endif 