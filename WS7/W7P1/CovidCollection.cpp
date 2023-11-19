/*/////////////////////////////////////////////////////////////////////////
						  Workshop - #7 (P1)
Full Name  : Bao Ngoc Ta
Student ID#: 116038225
Email      : bta@myseneca.ca
Date	   : 08/11/2023
Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/


#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <algorithm>
#include <fstream>
#include "CovidCollection.h"

using namespace std;

namespace sdds {
	std::string CovidCollection::trimSpaces(const std::string& str)
	{
		size_t startPos = str.find_first_not_of(" \t");
		size_t endPos = str.find_last_not_of(" \t");

		if (startPos != std::string::npos && endPos != std::string::npos) {
			return str.substr(startPos, endPos - startPos + 1);
		}
		else {
			return str;
		}
	}

	CovidCollection::CovidCollection(const std::string& filename)
	{
		std::ifstream file(filename);
		if (!file) {
			throw std::runtime_error("Failed to open the file.");
		}
		else {
			std::string line;  
			while (std::getline(file, line)) {
				Covid covid;
				covid.m_country = trimSpaces(line.substr(0, 25));
				covid.m_city = trimSpaces(line.substr(25, 25));
				covid.m_variant = trimSpaces(line.substr(50, 25));
				covid.m_year = std::stoi(line.substr(75, 5));
				covid.m_numOfCase = std::stoul(line.substr(80, 5));
				covid.m_numOfDeath = std::stoul(line.substr(85, 5));
				m_covidData.push_back(covid);
			}
		}
	}

	void CovidCollection::display(std::ostream& out) const {
		std::for_each(m_covidData.begin(), m_covidData.end(), [&out](const Covid& covid) {
			out << covid;
		});
	}

	std::ostream& operator<<(std::ostream& out, const Covid& theCovid)
	{
		out << "| " << left << setw(21) << theCovid.m_country
			<< " | " << setw(15) << theCovid.m_city
			<< " | " << setw(20) << theCovid.m_variant
			<< " | " << right;

		if (theCovid.m_year > 0) {
			out << setw(6) << theCovid.m_year;
		}
		else {
			out << setw(6) << " ";
		}
		 
		out << " | " << setw(4) << theCovid.m_numOfCase
			<< " | " << setw(3) << theCovid.m_numOfDeath << " |\n";
		return out;
	}
}


