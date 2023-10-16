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

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <istream>
#include <fstream>
#include <cstring>
#include "RideRequest.h"
using namespace std;


double g_taxrate = 0.0;
double g_discount = 0.0;

namespace sdds {
	RideRequest::RideRequest() {
		m_name[0] = '\0';
		m_ride = nullptr;
		m_price = 0.0;
		m_isDiscounted = false;
	}

	RideRequest::~RideRequest() { 
		delete[] m_ride; 
		m_ride = nullptr;
	}

	RideRequest& RideRequest::operator=(const RideRequest& src) {
		if (this != &src) {
			strcpy(m_name, src.m_name);
			if (m_ride) {
				delete[] m_ride;
				m_ride = nullptr;
			}

			if (src.m_ride) {
				m_ride = new char[strlen(src.m_ride) + 1];
				strcpy(m_ride, src.m_ride);
			}

			m_price = src.m_price;
			m_isDiscounted = src.m_isDiscounted;
		}

		return *this;
	}

	istream& RideRequest::read(istream& is) {
		if (!is) return is;
		char* temp_desc = nullptr;
		is.getline(m_name, 10, ',');

		char temp[256];
		is.getline(temp, sizeof(temp), ',');
		string input(temp);

		temp_desc = new char[input.length() + 1];
		strcpy(temp_desc, input.c_str());

		if (!temp_desc) {
			return is;
		}

		if (m_ride) {
			delete[] m_ride;
			m_ride = nullptr;
		}

		m_ride = new char[strlen(temp_desc) + 1];
		strcpy(m_ride, temp_desc);
		delete[] temp_desc;

		is >> m_price;
		is.ignore();
		char discountStatus;
		is >> discountStatus;
		m_isDiscounted = discountStatus == 'Y' ? true : false;

		return is;
	}

	RideRequest::RideRequest(const RideRequest& src) {
		*this = src;
	}


	void RideRequest::display() const {
		static int couter = 1;
		cout << left << setw(2) << couter << ". ";
		if (m_name[0] == '\0') {
			cout << "No Ride Request\n";
		}
		else {
			cout << left << setw(10) << m_name << "|";
			string rideDescriptionString(m_ride);
			if (rideDescriptionString.length() <= 25) {
				cout << setw(25) << m_ride;
			}
			else {
				cout << m_ride;
			}
			cout << "|" << fixed << setprecision(2) << setw(12) << m_price * (1 + g_taxrate)
				<< "|";

			if (m_isDiscounted) {
				double taxedPrice = (m_price * (1 + g_taxrate));
				taxedPrice = (int)((taxedPrice + 0.005) * 100) / 100.0;

				cout << right << setw(13) << taxedPrice - g_discount;
			}

			cout << "\n";
		}
		couter++;
	}
}
