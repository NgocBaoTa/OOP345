// Name: Bao Ngoc Ta
// Seneca Student ID: 116038225
// Seneca email: bta@myseneca.ca
// Date of completion: 11/12/2023
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.


#pragma once
#ifndef SDDS_STATION_H
#define SDDS_STATION_H
#include <iostream>
#include <string>
#include "Utilities.h"

namespace sdds
{
	class Station
	{
		int m_id;
		std::string m_itemName;
		std::string m_description;
		size_t m_nextSerialNum;
		size_t m_quantity;
		static size_t m_widthField;
		static size_t id_generator;
	public:
		Station(const std::string& record);
		const std::string& getItemName() const;
		size_t getNextSerialNumber();
		size_t getQuantity() const;
		void updateQuantity();
		void display(std::ostream& os, bool full) const;
	};
}

#endif