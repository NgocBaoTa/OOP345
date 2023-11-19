/*/////////////////////////////////////////////////////////////////////////
						  Workshop - #7 (P2)
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

	void CovidCollection::display(std::ostream& out, const std::string& country) const
	{
		size_t totalCases = 0;
		size_t totalDeaths = 0;

		std::for_each(m_covidData.begin(), m_covidData.end(), [&totalCases, &totalDeaths](const Covid& covid) {
			totalCases += covid.m_numOfCase;
			totalDeaths += covid.m_numOfDeath;
			});

		if (country == "ALL") {
			std::for_each(m_covidData.begin(), m_covidData.end(), [&out](const Covid& covid) {
				out << covid << "\n";
				});

			std::string line;
			line = "Total cases around the world: " + std::to_string(totalCases);
			out << "| " << setw(84) << line << " |\n";
			line = "Total deaths around the world: " + std::to_string(totalDeaths);
			out << "| " << setw(84) << line << " |\n";
		}
		else {
			size_t countryCases = 0;
			size_t countryDeaths = 0;
			out << "Displaying information of country = " << country << "\n";
			std::for_each(m_covidData.begin(), m_covidData.end(), [&out, &countryCases, &countryDeaths, country](const Covid& covid) {
				if (covid.m_country == country) {
					countryCases += covid.m_numOfCase;
					countryDeaths += covid.m_numOfDeath;
					out << covid << "\n";
				}
				});

			double casesPercentage = (static_cast<double>(countryCases) / totalCases) * 100.0;
			double deathsPercentage = (static_cast<double>(countryDeaths) / totalDeaths) * 100.0;

			std::string line;
			out << "----------------------------------------------------------------------------------------\n";
			line = "Total cases in " + country + ": " + std::to_string(countryCases);
			out << "| " << setw(84) << line << " |\n";
			line = "Total deaths in " + country + ": " + std::to_string(countryDeaths);
			out << "| " << setw(84) << line << " |\n";
			line = country + " has " + std::to_string(casesPercentage) + "% of global cases and " + std::to_string(deathsPercentage) + "% of global deaths";
			out << "| " << setw(84) << line << " |\n";
		}
	}

	void CovidCollection::sort(const std::string& field)
	{
		if (field == "country") {
			//Sorted by country
			std::sort(m_covidData.begin(), m_covidData.end(), [](const Covid& a, const Covid& b) {
				if (a.m_country == b.m_country) {
					return a.m_numOfDeath < b.m_numOfDeath;
				}

				return a.m_country < b.m_country;
				});
		}
		else if (field == "DEFAULT") {
			//Sorted by deaths
			std::sort(m_covidData.begin(), m_covidData.end(), [](const Covid& a, const Covid& b) {
				return a.m_numOfDeath < b.m_numOfDeath;
				});
		}
		else if (field == "year") {
			//Sorted by year
			std::sort(m_covidData.begin(), m_covidData.end(), [](const Covid& a, const Covid& b) {
				if (a.m_year == b.m_year) {
					return a.m_numOfDeath < b.m_numOfDeath;
				}

				return a.m_year < b.m_year;
				});
		}
		else if (field == "variant") {
			//Sorted by variant
			std::sort(m_covidData.begin(), m_covidData.end(), [](const Covid& a, const Covid& b) {
				if (a.m_variant == b.m_variant) {
					return a.m_numOfDeath < b.m_numOfDeath;
				}

				return a.m_variant < b.m_variant;
				});
		}
	}

	bool CovidCollection::inCollection(const std::string& variant, const std::string& country, unsigned int deaths) const {
		return std::any_of(m_covidData.begin(), m_covidData.end(), [&variant, &country, deaths](const Covid& covid) {
			return covid.m_variant == variant && covid.m_country == country && covid.m_numOfDeath > deaths;
			});
	}

	std::list<Covid> CovidCollection::getListForDeaths(unsigned int deaths) const {
		std::list<Covid> listCovid;
		std::copy_if(m_covidData.begin(), m_covidData.end(), std::back_inserter(listCovid), [deaths](const Covid& covid) {        
			return covid.m_numOfDeath >= deaths;
			});

		return listCovid;
	}

	void CovidCollection::updateStatus() {
		std::transform(m_covidData.begin(), m_covidData.end(), m_covidData.begin(), [](Covid& covid) {
			if (covid.m_numOfDeath > 300) {
				covid.m_severity = "EPIDEMIC";
			}
			else if (covid.m_numOfDeath < 50) {
				covid.m_severity = "EARLY";
			}
			else {
				covid.m_severity = "MILD";
			}
			return covid;
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
			<< " | " << setw(3) << theCovid.m_numOfDeath << " | "
			<< "| " << setw(8) << theCovid.m_severity << " |";
		return out;
	}
}


