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
#include "CheeseParty.h"
#include <iomanip>
#include <string>
using namespace std;

namespace sdds {
	CheeseParty& CheeseParty::addCheese(const Cheese& cheese) {
		bool duplicate = false;
		for (unsigned i = 0; i < m_partyCount && duplicate == false; i++) {
			if (m_partyCheeses[i] == &cheese) {
				duplicate = true;
			}
		}

		if (duplicate == false) {
			const Cheese** temp = new const Cheese * [m_partyCount + 1];

			for (unsigned i = 0; i < m_partyCount; i++) {
				temp[i] = m_partyCheeses[i];
			}

			temp[m_partyCount] = &cheese;
			if (m_partyCheeses != nullptr) {
				delete[] m_partyCheeses;
			}
			m_partyCheeses = temp;
			m_partyCount++;
		}

		return *this;
	}

	int CheeseParty::findEmptyCheese()
	{
		int index = -1;
		bool found = false;

		for (unsigned i = 0; i < m_partyCount && !found; i++)
		{
			if (m_partyCheeses[i]->getWeight() == 0)
			{
				index = i;
				found = true;
			}
		}

		return index;
	}

	void CheeseParty::deleteCheese(const unsigned index)
	{
		if (index < m_partyCount)
		{
			const Cheese** newCheeseParty = new const Cheese * [m_partyCount - 1];
			for (unsigned i = 0, j = 0; i < m_partyCount - 1; i++, j++)
			{
				if (j == index) { j++; }
				newCheeseParty[i] = m_partyCheeses[j];
			}

			if (m_partyCheeses != nullptr) {
				delete[] m_partyCheeses;
			}
			m_partyCheeses = newCheeseParty;
			m_partyCount--;
		}
	}

	CheeseParty& CheeseParty::removeCheese() {
		if (m_partyCheeses != nullptr)
		{
			int empty;
			bool foundEmpty = false;
			do
			{
				empty = findEmptyCheese();
				foundEmpty = empty >= 0;
				if (foundEmpty)
				{
					deleteCheese(empty);
				}
			} while (foundEmpty);
		}

		return *this;
	}


	CheeseParty& CheeseParty::operator=(const CheeseParty& src) {
		if (this == &src) {
			return *this;
		}

		if (m_partyCheeses != nullptr) {
			for (size_t i = 0; i < m_partyCount; i++)
			{
				m_partyCheeses[i] = nullptr;
			}
			delete[] m_partyCheeses;
			m_partyCheeses = nullptr;
		}

		m_partyCheeses = new const Cheese * [src.m_partyCount];
		m_partyCount = src.m_partyCount;

		for (unsigned i = 0; i < m_partyCount; ++i) {
			m_partyCheeses[i] = src.m_partyCheeses[i];
		}

		return *this;
	}

	CheeseParty& CheeseParty::operator=(CheeseParty&& src)
	{
		if (this != &src) {
			if (m_partyCheeses != nullptr) {
				for (size_t i = 0; i < m_partyCount; i++)
				{
					m_partyCheeses[i] = nullptr;
				}

				delete[] m_partyCheeses;
				m_partyCheeses = nullptr;
			}

				m_partyCount = src.m_partyCount;
				src.m_partyCount = 0;
				m_partyCheeses = src.m_partyCheeses;
				src.m_partyCheeses = nullptr;
			
		}
		return *this;
	}

	CheeseParty::CheeseParty(const CheeseParty& src) {
		operator=(src);
	}

	CheeseParty::CheeseParty(CheeseParty&& src)
	{
		operator=(move(src));
	}

	CheeseParty::~CheeseParty() {
		if (m_partyCheeses) {
			for (size_t i = 0; i < m_partyCount; i++)
			{
				m_partyCheeses[i] = nullptr;
			}

			delete[] m_partyCheeses;
			m_partyCheeses = nullptr;
		}
	}

	ostream& operator<<(std::ostream& os, const CheeseParty& party) {
		os << "--------------------------\nCheese Party\n--------------------------\n";
		if (party.m_partyCount == 0) {
			os << "This party is just getting started!\n";
		}
		else {
			for (unsigned i = 0; i < party.m_partyCount; i++) {
				party.m_partyCheeses[i]->print(os);
			}
		}

		os << "--------------------------\n";
		return os;
	}
}