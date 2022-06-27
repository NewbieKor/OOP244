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

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include <iomanip>
#include "Car.h"

using namespace std;
namespace sdds
{
    void Car::resetInfo()
    {
		c_type = nullptr;
		c_brand = nullptr;
		c_model = nullptr;
		c_year = 0;
		c_code = 0;
		c_price = 0;
    }
	Car::Car()
	{
		resetInfo();
	}
	Car::Car(const char* type, const char* brand, const char* model, int year, int code, double price)
	{
		if (type && type[0] != '0' && brand && brand[0] != '0' && model && model[0] != '0' && year >= 1990 && code >= 100 && code < 1000 && price > 0)
		{
			c_type = new char[strlen(type) + 1];
			strcpy(c_type, type);
			c_brand = new char[strlen(brand) + 1];
			strcpy(c_brand, brand);
			c_model = new char[strlen(model) + 1];
			strcpy(c_model, model);
			c_year = year;
			c_code = code;
			c_price = price;
		}
		else resetInfo();

	}
	Car::~Car()
	{
		delete[] c_type;
		delete[] c_brand;
		delete[] c_model;
	}
	Car& Car::setInfo(const char* type, const char* brand, const char* model, int year, int code, double price)
	{
		delete[] c_type;
		delete[] c_brand;
		delete[] c_model;
		if (type && type[0] != '0' && brand && brand[0] != '0' && model && model[0] != '0' && year >= 1990 && code >= 100 && code < 1000 && price > 0)
		{
			c_type = new char[strlen(type) + 1];
			strcpy(c_type, type);
			c_brand = new char[strlen(brand) + 1];
			strcpy(c_brand, brand);
			c_model = new char[strlen(model) + 1];
			strcpy(c_model, model);
			c_year = year;
			c_code = code;
			c_price = price;
		}
		else resetInfo();
		
		return *this;
	}
	void Car::printInfo() const
	{
		cout << fixed << setprecision(2);
		cout << left << "| " << setw(10) << c_type;
		cout << " | " << setw(16) << c_brand;
		cout << " | " << setw(16) << c_model;
		cout << right << " | " << c_year << " | ";
		cout << setw(4) << c_code << " | ";
		cout << setw(9) << c_price << " |" << endl;
	}
	bool Car::isValid() const
	{
		return c_type && c_type[0] != '\0' && c_brand && c_brand[0] != '\0' && c_model && c_model[0] != '\0' && c_year >= 1990 && c_code >= 100 && c_code < 1000 && c_price > 0;
	}
	bool Car::isSimilarTo(const Car& car) const
	{
		return isValid() && car.isValid() && !strcmp(c_type, car.c_type) && !strcmp(c_brand, car.c_brand) && !strcmp(c_model, car.c_model) && c_year == car.c_year;
	}

	bool has_similar(const Car car[], const int num_cars)
	{
		bool isSimilar = false;
		for (int i = 0; i < num_cars && !isSimilar; i++) // if isSimillar = true, this for statement will be broken
		{
			for (int j = i + 1; j < num_cars && !isSimilar; j++)
			{
				if (car[i].isSimilarTo(car[j]))
				{
					isSimilar = true;
				}
			}
		}
		return isSimilar;
	}

	bool has_invalid(const Car car[], const int num_cars)
	{
		bool isInvalid = false;
		for (int i = 0; i < num_cars && !isInvalid; i++)
		{
			if (!car[i].isValid()) isInvalid = true;
		}
		return isInvalid;
	}

	void print(const Car car[], const int num_cars)
	{
		for (int i = 0; i < num_cars; i++)
		{
			if (car[i].isValid()) car[i].printInfo();
		}
	}

}