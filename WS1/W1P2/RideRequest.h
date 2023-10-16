/*/////////////////////////////////////////////////////////////////////////
						  Workshop - #1 (P2)
Full Name  : Bao Ngoc Ta
Student ID#: 116038225
Email      : bta@myseneca.ca
Date	   : 14/09/2023
Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/

#pragma once
#include <iostream>
#ifndef SDDS_RIDEREQUEST_H
#define SDDS_RIDEREQUEST_H
#include <iostream>
#include <iomanip>

extern double g_taxrate;
extern double g_discount;

namespace sdds {
	class RideRequest {
		char m_name[11]{};
		char* m_ride{ nullptr };
		double m_price;
		bool m_isDiscounted;
	public:
		RideRequest();
		~RideRequest();
		RideRequest& operator=(const RideRequest& src);
		RideRequest(const RideRequest& src);
		std::istream& read(std::istream& is);
		void display() const;
	};
}

#endif // !SDDS_RIDEREQUEST_H