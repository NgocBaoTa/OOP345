#define _CRT_SECURE_NO_WARNINGS
#include "AirportModels.h"
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

namespace sdds {
	void Airport::write(ostream& os) const {
		if (m_code[0] == '\0') {
			os << "Empty Airport";
		}
		else {
			os << setfill('.') << right << setw(20) << "Airport Code" << " : " << left << setw(30) << m_code << "\n"
				<< right << setw(20) << "Airport Name" << " : " << left << setw(30) << m_name << "\n"
				<< right << setw(20) << "Airport City" << " : " << left << setw(30) << m_city << "\n"
				<< right << setw(20) << "Airport State" << " : " << left << setw(30) << m_state << "\n"
				<< right << setw(20) << "Airport Country" << " : " << left << setw(30) << m_country << "\n"
				<< right << setw(20) << "Airport Latitude" << " : " << left << setw(30) << m_latitude << "\n"
				<< right << setw(20) << "Airport Longitude" << " : " << left << setw(30) << m_longitude << "\n";
			os << setfill(' ');

		}
	}


	ostream& operator<<(ostream& os, const Airport& src) {
		src.write(os);
		return os;
	}


	AirportLog::AirportLog() : m_airports(nullptr), m_count(0) {}


	AirportLog::~AirportLog() {
		delete[] m_airports;
		m_airports = nullptr;
	}

	AirportLog& AirportLog::operator=(const AirportLog& src) {
		if (this != &src) {
			if (m_airports) {
				delete m_airports;
			}

			m_count = src.m_count;
			m_airports = new Airport[m_count];
			for (size_t i = 0; i < m_count; i++) {
				m_airports[i] = src.m_airports[i];
			}
		}

		return *this;
	}

	AirportLog::AirportLog(const AirportLog& src) {
		*this = src;
	}


	AirportLog::AirportLog(const char* filename) {
		m_count = 0;
		ifstream file(filename);
		if (file.is_open()) {
			string line;
			getline(file, line);
			while (getline(file, line)) {
				m_count++;
			}

			file.close();
		}

		m_airports = new Airport[m_count];
		file.open(filename);
		if (file.is_open()) {
			string line;
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
				file.ignore() ;
			}

			file.close();
		}

	}


	void AirportLog::addAirport(const Airport& src) {
		Airport* newAirports = new Airport[m_count + 1];
		for (size_t i = 0; i < m_count; i++) {
			newAirports[i].m_code = m_airports[i].m_code;
			newAirports[i].m_city = m_airports[i].m_city;
			newAirports[i].m_country = m_airports[i].m_country;
			newAirports[i].m_latitude = m_airports[i].m_latitude;
			newAirports[i].m_longitude = m_airports[i].m_longitude;
			newAirports[i].m_name = m_airports[i].m_name;
			newAirports[i].m_state = m_airports[i].m_state;
		}

		newAirports[m_count].m_code = src.m_code;
		newAirports[m_count].m_city = src.m_city; 
		newAirports[m_count].m_country = src.m_country;
		newAirports[m_count].m_latitude = src.m_latitude;
		newAirports[m_count].m_longitude = src.m_longitude;
		newAirports[m_count].m_name = src.m_name;
		newAirports[m_count].m_state = src.m_state;
		delete[] m_airports;
		m_airports = newAirports;
		m_count++;
	}


	AirportLog& AirportLog::findAirport(std::string state, std::string country) {
		AirportLog* result = new AirportLog{};
		for (size_t i = 0; i < m_count; i++) {
			if (m_airports[i].m_country == country && m_airports[i].m_state == state) {
				result->addAirport(m_airports[i]);
			}
		}
		return *result;
	}

	Airport& AirportLog::operator[](size_t index) const
	{
		if (index >= m_count)
		{
			Airport* empty = new Airport{};
			return *empty;
		}
		return m_airports[index];
	}

	AirportLog::operator size_t() const
	{
		return m_count;
	}
}