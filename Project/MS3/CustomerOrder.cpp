// Name: Bao Ngoc Ta
// Seneca Student ID: 116038225
// Seneca email: bta@myseneca.ca
// Date of completion: 29/11/2023
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <algorithm>
#include "CustomerOrder.h"
using namespace std;

namespace sdds {
	size_t CustomerOrder::m_widthField = 0;

	CustomerOrder::CustomerOrder(const std::string& record) : m_name(""), m_product(""), m_cntItem(0), m_lstItem(nullptr) {
		Utilities utility;
		size_t next_pos = 0;
		bool more = true;

		m_name = utility.extractToken(record, next_pos, more);
		m_product = utility.extractToken(record, next_pos, more);
		m_cntItem = std::count(record.begin(), record.end(), utility.getDelimiter()) - 1;

		m_lstItem = new Item * [m_cntItem];

		for (size_t i = 0; i < m_cntItem; i++) {
			std::string item = utility.extractToken(record, next_pos, more);
			m_lstItem[i] = new Item(item);
		}

		if (m_widthField < utility.getFieldWidth()) {
			m_widthField = utility.getFieldWidth();
		}
	}


	CustomerOrder::CustomerOrder(const CustomerOrder& other)
	{
		throw "Copy constructor for CustomerOrder is not allowed.";
	}

	CustomerOrder::CustomerOrder(CustomerOrder&& other) noexcept
	{
		*this = std::move(other);
	}

	CustomerOrder& CustomerOrder::operator=(CustomerOrder&& other) noexcept
	{
		if (this != &other) {
			if (m_lstItem) {
				for (auto i = 0u; i < m_cntItem; ++i)
					delete m_lstItem[i];
			}
			m_name = other.m_name;
			m_product = other.m_product;
			m_lstItem = other.m_lstItem;
			m_cntItem = other.m_cntItem;

			other.m_name = "";
			other.m_product = "";
			other.m_lstItem = nullptr;
			other.m_cntItem = 0;
		}

		return *this;
	}

	CustomerOrder::~CustomerOrder()
	{
		if (m_lstItem) {
			for (size_t i = 0; i < m_cntItem; i++) {
				delete m_lstItem[i];
			}

			delete[] m_lstItem;
		}
	}


	bool CustomerOrder::isOrderFilled() const
	{
		bool result = true;
		for (size_t i = 0; i < m_cntItem && result; i++) {
			if (!m_lstItem[i]->m_isFilled) {
				result = false;
			}
		}
		return result;
	}

	bool CustomerOrder::isItemFilled(const std::string& itemName) const {
		bool flag = true;
		for (size_t i = 0; i < m_cntItem && flag; i++) {
			if (m_lstItem[i]->m_itemName == itemName) {
				if (!m_lstItem[i]->m_isFilled) {
					flag = false;
				}
			}
		}
		return flag;
	}


	void CustomerOrder::fillItem(Station& station, std::ostream& os) {
		bool filled{ false };
		for (size_t i = 0; i < m_cntItem && !filled; i++) {
			if ((m_lstItem[i]->m_itemName == station.getItemName()) && !m_lstItem[i]->m_isFilled && (station.getQuantity() > 0)) {
				station.updateQuantity();
				m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();
				m_lstItem[i]->m_isFilled = true;
				filled = true;
				os << "    Filled " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << endl;
			}
			else if ((m_lstItem[i]->m_itemName == station.getItemName()) && (station.getQuantity() == 0)) {
				os << "    Unable to fill " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << endl;
			}
		}
	}


	void CustomerOrder::display(std::ostream& os) const {
		os << m_name << " - " << m_product << std::endl;
		for (size_t i{ 0 }; i < m_cntItem; i++) {
			os << std::right << std::setfill('0');
			os << "[" << std::setw(6) << m_lstItem[i]->m_serialNumber << "] ";
			os << std::setfill(' ') << std::left;
			os << std::setw(m_widthField) << m_lstItem[i]->m_itemName;
			os << " - ";
			os << (m_lstItem[i]->m_isFilled ? "FILLED" : "TO BE FILLED");
			os << std::endl;
		}
	}
}




