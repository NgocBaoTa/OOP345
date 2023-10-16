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
			<< setprecision(6) << m_numPages / static_cast<double>(m_numChapters) << ")   "
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
}