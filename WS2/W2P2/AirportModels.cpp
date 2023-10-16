/*/////////////////////////////////////////////////////////////////////////
						  Workshop - #2 (P2)
Full Name  : Bao Ngoc Ta
Student ID#: 116038225
Email      : bta@myseneca.ca
Date	   : 23/09/2023
Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/


#define _CRT_SECURE_NO_WARNINGS
#include "AirportModels.h"
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

namespace sdds {
	ostream& operator<<(ostream& os, const Airport& src) {
		if (src.m_code[0] == '\0') {
			os << "Empty Airport";
		}
		else {
			os << setfill('.') << right << setw(20) << "Airport Code" << " : " << left << setw(30) << src.m_code << "\n"
				<< right << setw(20) << "Airport Name" << " : " << left << setw(30) << src.m_name << "\n"
				<< right << setw(20) << "City" << " : " << left << setw(30) << src.m_city << "\n"
				<< right << setw(20) << "State" << " : " << left << setw(30) << src.m_state << "\n"
				<< right << setw(20) << "Country" << " : " << left << setw(30) << src.m_country << "\n"
				<< right << setw(20) << "Latitude" << " : " << left << setw(30) << src.m_latitude << "\n"
				<< right << setw(20) << "Longitude" << " : " << left << setw(30) << src.m_longitude << "\n";
			os << setfill(' ');

		}
		return os;
	}


	AirportLog::~AirportLog() {
		if (m_airports != nullptr) {
			delete[] m_airports;
			m_airports = nullptr;
		}
	}

	AirportLog& AirportLog::operator=(const AirportLog& src) {
		if (this == &src) {
			return *this;
		}

		if (src.m_count == 0) {
			m_airports = nullptr;
			m_count = 0;
			return *this;
		}


			if (m_airports != nullptr) {
				delete[] m_airports;
			}

			m_count = src.m_count;
			m_airports = new Airport[m_count];
			for (size_t i = 0; i < m_count; i++) {
				m_airports[i] = src.m_airports[i];
			}
		

		return *this;
	}

	AirportLog& AirportLog::operator=(AirportLog&& src)
	{
		if (this == &src) {
			return *this;
		}

		if (m_airports != nullptr) {
			delete[] m_airports;
		}

		m_count = src.m_count;
		src.m_count = 0;
		m_airports = src.m_airports;
		src.m_airports = nullptr;
		return *this;
	}

	AirportLog::AirportLog(const AirportLog& src) {
		operator=(src);
	}

	AirportLog::AirportLog(AirportLog&& src)
	{
		operator=(move(src));
	}


	AirportLog::AirportLog(const char* filename) {
		ifstream file(filename);
		if (!file)
		{
			cerr << "Could not open file: " << filename << endl;
			return;
		}

		string line{};
		getline(file, line); 
		while (getline(file, line)) {
			m_count++;
		}
		
		m_airports = new Airport[m_count];

		file.clear(); 
		file.seekg(0); 

		getline(file, line); 
		for (size_t i = 0; i < m_count; i++) {
			getline(file, m_airports[i].m_code, ',');
			getline(file, m_airports[i].m_name, ',');
			getline(file, m_airports[i].m_city, ',');
			getline(file, m_airports[i].m_state, ',');
			getline(file, m_airports[i].m_country, ',');
			file >> m_airports[i].m_latitude;
			file.ignore();
			file >> m_airports[i].m_longitude;
			file.ignore();
		}

	}


	void AirportLog::addAirport(const Airport& src) {
		Airport* newAirports = new Airport[m_count + 1];
		for (size_t i = 0; i < m_count; i++) {
			newAirports[i] = m_airports[i];
		}

		newAirports[m_count] = src;
		if (m_airports != nullptr) {
			delete[] m_airports;
		}
		m_airports = newAirports;
		m_count++;
	}


	AirportLog AirportLog::findAirport(string state, string country) {
		/*AirportLog* result = new AirportLog{};
		for (size_t i = 0; i < m_count; i++) {
			if (m_airports[i].m_country == country && m_airports[i].m_state == state) {
				result->addAirport(m_airports[i]);
			}
		}
		return *result;*/
		AirportLog result;
		for (size_t i = 0; i < m_count; i++) {
			if (m_airports[i].m_country == country && m_airports[i].m_state == state) {
				result.addAirport(m_airports[i]);
			}
		}
		return result;
	}

	Airport AirportLog::operator[](size_t index) const
	{
		if (index >= m_count)
		{
			/*Airport* empty = new Airport{};
			return *empty*/;

			return Airport{};
		}
		return m_airports[index];
	}

	AirportLog::operator size_t() const
	{
		return m_count;
	}
}