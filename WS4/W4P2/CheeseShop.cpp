/*/////////////////////////////////////////////////////////////////////////
						  Workshop - #4 (P2)
Full Name  : Bao Ngoc Ta
Student ID#: 116038225
Email      : bta@myseneca.ca
Date	   : 07/10/2023
Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/


#define _CRT_SECURE_NO_WARNINGS
#include "CheeseShop.h"
#include <iomanip>
#include <string>
using namespace std;

namespace sdds {
	CheeseShop::CheeseShop() {
		m_name = "No Name";
		m_cheeses = nullptr;
		m_count = 0;
	}

	CheeseShop::CheeseShop(const std::string& name) {
		m_name = name;
		m_cheeses = nullptr;
		m_count = 0;
	}

	CheeseShop& CheeseShop::addCheese(const Cheese& cheese) {
		const Cheese** temp = new const Cheese * [m_count + 1];

		for (unsigned i = 0; i < m_count; i++) {
			temp[i] = m_cheeses[i];
		} 

		temp[m_count] = new Cheese(cheese);

		if (m_cheeses) {
			delete[] m_cheeses;
		}
		m_cheeses = temp;
		m_count++;

		return *this;
	}


	CheeseShop& CheeseShop::operator=(const CheeseShop& src) {
		if (this == &src) {
			return *this;
		}

		if (m_cheeses != nullptr) {
			for (unsigned i = 0; i < m_count; i++) {
				delete m_cheeses[i];
				m_cheeses[i] = nullptr;
			}
			delete[] m_cheeses;
			m_cheeses = nullptr;
		}

		m_cheeses = new const Cheese * [src.m_count];
		m_count = src.m_count;
		m_name = src.m_name;

		for (unsigned i = 0; i < m_count; i++) {
			m_cheeses[i] = new Cheese{ *(src.m_cheeses[i]) };
		}

		return *this;
	}

	CheeseShop& CheeseShop::operator=(CheeseShop&& src) 
	{
		if (this == &src) {
			return *this;
		}

		if (m_cheeses != nullptr) {
			for (size_t i = 0; i < m_count; i++)
			{
				delete m_cheeses[i];
				m_cheeses[i] = nullptr;
			}

			delete[] m_cheeses;
			m_cheeses = nullptr;
		}

		
		if (src.m_cheeses != nullptr) {
			m_cheeses = src.m_cheeses;
			src.m_cheeses = nullptr;
			m_count = src.m_count;
			src.m_count = 0;
			m_name = src.m_name;
			src.m_name = "";
		}
		
		return *this;
	}

	CheeseShop::CheeseShop(const CheeseShop& src) {
		operator=(src);
	}

	CheeseShop::CheeseShop(CheeseShop&& src) 
	{
		operator=(move(src));
	}

	CheeseShop::~CheeseShop() {
		if (m_cheeses != nullptr) {
			for (size_t i = 0; i < m_count; i++)
			{
				delete m_cheeses[i];
				m_cheeses[i] = nullptr;
			}

			delete[] m_cheeses;
			m_cheeses = nullptr;
		}
	}

	ostream& operator<<(std::ostream& os, const CheeseShop& shop) {
		os << "--------------------------\n"
			<< shop.m_name
			<< "\n--------------------------\n";

		if (shop.m_cheeses != nullptr)
		{
			for (size_t i = 0; i < shop.m_count; i++)
			{
				os << *(shop.m_cheeses[i]);
			}
			os << "--------------------------\n";
		}
		else
		{
			os << "This shop is out of cheese!\n"
				<< "--------------------------\n";
		}
		return os;
	}
}