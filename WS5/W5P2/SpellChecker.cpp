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
#include "SpellChecker.h"
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

namespace sdds {
	SpellChecker::SpellChecker(const char* filename) {
		std::ifstream file(filename);
		if (!file.is_open()) {
            throw "Bad file name!";
		}

        for (size_t i = 0; i < 6; i++) {
            file >> m_badWords[i] >> m_goodWords[i];
        }

        file.close();
	};


	void SpellChecker::operator()(std::string& text) {
		for (size_t i = 0; i < 6; i++) {
			size_t found = text.find(m_badWords[i]);
			if (found != string::npos) {
				text.replace(found, m_badWords[i].length(), m_goodWords[i]);
				m_count[i]++;
			}
			found = text.find(m_badWords[i]);
			if (found != string::npos) {
				--i;
			}
		}
	}

	void SpellChecker::showStatistics(std::ostream& out) const {
		out << "Spellchecker Statistics\n";
		for (size_t i = 0; i < 6; i++) {
			out << right << setw(15) << m_badWords[i] << ": " << left << m_count[i] << " replacements\n";
		}
	}
	
}