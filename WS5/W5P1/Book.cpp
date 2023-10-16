/*/////////////////////////////////////////////////////////////////////////
						  Workshop - #3 (P2)
Full Name  : Bao Ngoc Ta
Student ID#: 116038225
Email      : bta@myseneca.ca
Date	   : 30/09/2023
Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/


#define _CRT_SECURE_NO_WARNINGS
#include "Book.h"
#include <iomanip>
#include <string>
using namespace std;

namespace sdds {
	Book::Book() : m_author(""), m_title(""), m_country(""), m_year(0), m_price(0.0), m_description("") {};

	const string& Book::title() const {
		return m_title;
	}

	const string& Book::country() const {
		return m_country;
	}

	const size_t& Book::year() const {
		return m_year;
	}

	double& Book::price() {
		return m_price;
	}
	Book::Book(const string& strBook) : m_author(""), m_title(""), m_country(""), m_year(0), m_price(0.0), m_description("") {
		unsigned startPos = 0;
		unsigned endPos = strBook.find(',');

		if (endPos != string::npos) {
			m_author = strBook.substr(startPos, endPos - startPos);
			m_author.erase(0, m_author.find_first_not_of(" \t"));
			m_author.erase(m_author.find_last_not_of(" \t") + 1);

			startPos = endPos + 1;
			endPos = strBook.find(',', startPos);

			if (endPos != string::npos) {
				m_title = strBook.substr(startPos, endPos - startPos);
				m_title.erase(0, m_title.find_first_not_of(" \t"));
				m_title.erase(m_title.find_last_not_of(" \t") + 1);

				startPos = endPos + 1;
				endPos = strBook.find(',', startPos);

				if (endPos != string::npos) {
					m_country = strBook.substr(startPos, endPos - startPos);
					m_country.erase(0, m_country.find_first_not_of(" \t"));
					m_country.erase(m_country.find_last_not_of(" \t") + 1);

					startPos = endPos + 1;
					endPos = strBook.find(',', startPos);

					if (endPos != string::npos) {
						string price = strBook.substr(startPos, endPos - startPos);
						price.erase(0, price.find_first_not_of(" \t"));
						price.erase(price.find_last_not_of(" \t") + 1);
						m_price = stod(price);

						startPos = endPos + 1;
						endPos = strBook.find(',', startPos);

						if (endPos != string::npos) {
							string year = strBook.substr(startPos, endPos - startPos);
							year.erase(0, year.find_first_not_of(" \t"));
							year.erase(year.find_last_not_of(" \t") + 1);
							m_year = stoul(year);

							startPos = endPos + 1;
							m_description = strBook.substr(startPos);
							m_description.erase(0, m_description.find_first_not_of(" \t"));
							m_description.erase(m_description.find_last_not_of(" \t") + 1);
						}
					}
				}
			}
		}
	}

	ostream& operator<<(std::ostream& os, const Book& book) {
		os << right << setw(20) << book.m_author << "|"
			<< setw(22) << book.m_title << "|"
			<< setw(5) << book.m_country << "|"
			<< setw(4) << book.m_year << "|"
			<< fixed << setprecision(2) << setw(6) << book.m_price << "|"
			<< left << book.m_description;

		return os;
 	}
}