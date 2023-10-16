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
#ifndef SDDS_AIRPORTMODELS_H
#define SDDS_AIRPORTMODELS_H
#include <iostream>
#include <iomanip>

namespace sdds {
	struct Airport {
		std::string m_code{};
		std::string m_name{};
		std::string m_city{};
		std::string m_state{};
		std::string m_country{};
		double m_latitude{ 0 };
		double m_longitude{ 0 };

		void write(std::ostream& os) const;
	};

	std::ostream& operator<<(std::ostream& os, const Airport& src);

	class AirportLog {
		Airport* m_airports;
		size_t m_count;
	public:
		AirportLog();
		~AirportLog();
		AirportLog(const char* filename);
		AirportLog& operator=(const AirportLog& src);
		AirportLog(const AirportLog& src);
		void addAirport(const Airport& src);
		AirportLog& findAirport(std::string state, std::string country);
		Airport& operator[](size_t index) const;
		operator size_t() const;
	};
}

#endif // !SDDS_AIRPORTMODELS_H