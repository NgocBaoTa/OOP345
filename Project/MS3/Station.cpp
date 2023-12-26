// Name: Bao Ngoc Ta
// Seneca Student ID: 116038225
// Seneca email: bta@myseneca.ca
// Date of completion: 29/11/2023
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include "Station.h"
using namespace std;

namespace sdds {
	size_t Station::id_generator = 0;
	size_t Station::m_widthField = 0;
	Station::Station(const std::string& record) {
		Utilities utility;
		size_t next_pos = 0;
		bool more = true;

		m_id = ++id_generator;
		m_itemName = utility.extractToken(record, next_pos, more);
		m_nextSerialNum = std::stoul(utility.extractToken(record, next_pos, more));
		m_quantity = std::stoul(utility.extractToken(record, next_pos, more));

		if (m_widthField < utility.getFieldWidth()) {
			m_widthField = utility.getFieldWidth();
		}
		m_description = utility.extractToken(record, next_pos, more);
	}

	const std::string& Station::getItemName() const
	{
		return m_itemName;
	}

	size_t Station::getNextSerialNumber()
	{
		return m_nextSerialNum++;
	}

	size_t Station::getQuantity() const
	{
		return m_quantity;
	}

	void Station::updateQuantity()
	{
		if (m_quantity > 0) {
			m_quantity--;
		}
	}

	void Station::display(std::ostream& os, bool full) const
	{
		os << std::right << setw(3) << setfill('0') << m_id
			<< setfill(' ') << " | "
			<< setw(int(m_widthField)) << left << m_itemName << right
			<< " | " << setw(6) << setfill('0')
			<< m_nextSerialNum << setfill(' ') << " | ";

		if (full) {
			os << setw(4) << m_quantity << " | " << m_description;
		}

		os << endl;
	}

}


