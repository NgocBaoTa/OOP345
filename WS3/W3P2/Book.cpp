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
using namespace std;

namespace sdds {
	Book::Book() : m_title(""), m_numChapters(0), m_numPages(0) {};
	Book::Book(const string& title, unsigned nChapters, unsigned nPages) : m_title(title), m_numChapters(nChapters), m_numPages(nPages) {};

	ostream& Book::print(ostream& os) const {
		if (m_title[0] != '\0' && m_numChapters > 0 && m_numPages > 0) {

			os << right << fixed << setw(m_numChapters > 9 ? 49 : 50) << m_title << ","
				<< m_numChapters << "," << m_numPages << " | ("
				<< setprecision(6) << m_numPages / static_cast<double>(m_numChapters) << ")    "
				<< left;
		}
		else {
			cout << "| Invalid book data";
		}

		return os;
	}

	ostream& operator<<(ostream& os, const Book& bk)
	{
		return bk.print(os);
	}

	Book& Book::operator=(const Book& src) {
		if (this != &src) {
			m_numChapters = src.m_numChapters;
			m_numPages = src.m_numPages;
			m_title = src.m_title;
		}

		return *this;
	}

	bool Book::operator>(const Book& src) const {
		return double(m_numPages) / m_numChapters > double(src.m_numPages) / src.m_numChapters;
	}

	bool Book::operator<(const Book& src) const {
		return src > *this;
	}
}