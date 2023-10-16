/*/////////////////////////////////////////////////////////////////////////
						  Workshop - #1 (P1)
Full Name  : Bao Ngoc Ta
Student ID#: 116038225
Email      : bta@myseneca.ca
Date	   : 11/09/2023
Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "RideRequest.h"
using namespace std;


double g_taxrate = 0.0;
double g_discount = 0.0;

namespace sdds {
	RideRequest::RideRequest() {
		m_name[0] = '\0';
		m_ride[0] = '\0';
		m_price = 0.0;
		m_isDiscounted = false;
	}

	istream& RideRequest::read(istream &is) {
		if (!is) return is;
		is.getline(m_name, 10, ',');
		is.getline(m_ride, 25, ',');
		is >> m_price;
		is.ignore();
		char discountStatus;
		is >> discountStatus;
		m_isDiscounted = discountStatus == 'Y' ? true : false;
		is.ignore();

		return is;
	}

	void RideRequest::display() const {
		static int couter = 1;
		cout << left << setw(2) << couter << ". ";
		if (m_name[0] == '\0') {
			cout << "No Ride Request\n";
		}
		else {
			cout << left << setw(10) << m_name << "|" << setw(25) << m_ride
				<< "|" << fixed << setprecision(2) << setw(12) << m_price * (1 + g_taxrate)
				<< "|";
			if (m_isDiscounted) {
				cout << right << setw(13) << m_price * (1 + g_taxrate) / g_discount; 
			}

			cout << "\n";
		}
		couter++;
	}
}
