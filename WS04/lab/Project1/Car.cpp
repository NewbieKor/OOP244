#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include <iomanip>
#include "Car.h"

using namespace std;
namespace sdds {
	void Car::resetInfo()
	{
		m_type = nullptr;
		m_brand = nullptr;
		m_model = nullptr;
		m_year = 0;
		m_code = 0;
		m_price = 0;
	}
	Car::Car()
	{
		resetInfo();
	}
	Car::Car(const char* type, const char* brand, const char* model, int year, int code, double price)
	{
		if (type && type[0] != '\0' && brand && brand[0] != '\0' && model && model[0] != '\0' && year >= 1990 && code >= 100 && code < 1000 && price>0) {
			m_type = new char[strlen(type) + 1];
			strcpy(m_type, type);
			m_brand = new char[strlen(brand) + 1];
			strcpy(m_brand, brand);
			m_model = new char[strlen(model) + 1];
			strcpy(m_model, model);
			m_year = year;
			m_code = code;
			m_price = price;
		}
		else resetInfo();
	}
	Car::~Car()
	{
		delete[] m_type;
		delete[] m_brand;
		delete[] m_model;
	}
	Car& Car::setInfo(const char* type, const char* brand, const char* model, int year, int code, double price)
	{
		delete[] m_type; //memory leak을 방지하는 용도(만약에 메모리가 할당된 상태에서 다시 할당하면 원래 할당된 값이 붕 떠버림)
		delete[] m_brand;
		delete[] m_model;
		if (type && type[0] != '\0' && brand && brand[0] != '\0' && model && model[0] != '\0' && year >= 1990 && code >= 100 && code < 1000 && price>0) {
			m_type = new char[strlen(type) + 1];
			strcpy(m_type, type);
			m_brand = new char[strlen(brand) + 1];
			strcpy(m_brand, brand);
			m_model = new char[strlen(model) + 1];
			strcpy(m_model, model);
			m_year = year;
			m_code = code;
			m_price = price;
		}

		else resetInfo();
		return *this;
	}
	void Car::printInfo() const
	{
		/*cout.width(10);
		cout.fill('*');
		cout <<setw(10)<<setfill('*') << "Hello";*/
		//cout.setf(ios::fixed);//%.2lf
		//cout.precision(2); //1.23
		cout << fixed << setprecision(2);
		cout << left << "| " << setw(10) << m_type;
		cout << " | " << setw(16) << m_brand;
		cout << " | " << setw(16) << m_model;
		cout << right << " | " << m_year << " | " << setw(4) << m_code << " | " << setw(9) << m_price << " |" << endl;
	}
	bool Car::isValid() const
	{
		return m_type && m_type[0] != '\0' && m_brand && m_brand[0] != '\0' && m_model && m_model[0] != '\0' && m_year >= 1990 && m_code >= 100 && m_code < 1000 && m_price>0;
	}
	bool Car::isSimilarTo(const Car& car) const
	{
		return isValid() && car.isValid() && !strcmp(m_type, car.m_type) && !strcmp(m_brand, car.m_brand) && !strcmp(m_model, car.m_model) && m_year == car.m_year;
	}
	bool has_similar(const Car car[], const int num_cars)
	{
		bool isFound = false;
		for (int i = 0; i < num_cars && !isFound; i++) {
			for (int j = i + 1; j < num_cars && !isFound; j++) {
				if (car[i].isSimilarTo(car[j])) {
					isFound = true;
				}
			}
		}
		return isFound;
	}
	bool has_invalid(const Car car[], const int num_cars)
	{
		bool isFound = false;
		for (int i = 0; i < num_cars && !isFound; i++) {
			if (!car[i].isValid()) isFound = true;
		}
		/*for (int i = 0; i < num_cars; i++) {
			if (!car[i].isValid()) return true;
		}*/
		return isFound;
	}
	void print(const Car car[], const int num_cars)
	{
		for (int i = 0; i < num_cars; i++) {
			if (car[i].isValid()) car[i].printInfo();
		}
	}
}