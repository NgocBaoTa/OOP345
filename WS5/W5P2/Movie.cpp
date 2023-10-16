/*/////////////////////////////////////////////////////////////////////////
						  Workshop - #5 (P2)
Full Name  : Bao Ngoc Ta
Student ID#: 116038225
Email      : bta@myseneca.ca
Date	   : 13/10/2023
Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/


#define _CRT_SECURE_NO_WARNINGS
#include "Movie.h"
#include <iomanip>
#include <string>
using namespace std;

namespace sdds {
	Movie::Movie() : m_title(""), m_year(0), m_description("") {};

	Movie::Movie(const string& strMovie) : m_title(""), m_year(0), m_description("") {
		unsigned startPos = 0;
		unsigned endPos = strMovie.find(',');

		if (endPos != string::npos) {
			m_title = strMovie.substr(startPos, endPos - startPos);
			m_title.erase(0, m_title.find_first_not_of(" \t"));
			m_title.erase(m_title.find_last_not_of(" \t") + 1);

			startPos = endPos + 1;
			endPos = strMovie.find(',', startPos);

			if (endPos != string::npos) {
				string year = strMovie.substr(startPos, endPos - startPos);
				year.erase(0, year.find_first_not_of(" \t"));
				year.erase(year.find_last_not_of(" \t") + 1);
				m_year = stoul(year);

				startPos = endPos + 1;
				m_description = strMovie.substr(startPos);
				m_description.erase(0, m_description.find_first_not_of(" \t"));
				m_description.erase(m_description.find_last_not_of(" \t") + 1);
			}
		}
	}

	const std::string& Movie::title() const {
		return m_title;
	}
	
	ostream& operator<<(std::ostream& os, const Movie& movie) {
		os << right << setw(40) << movie.m_title << " | "
			<< setw(4) << movie.m_year << " | "
			<< left << movie.m_description << "\n";

		return os;
	}
}