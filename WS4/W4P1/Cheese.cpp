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
#include "Cheese.h"
#include <iomanip>
#include <string>
using namespace std;

namespace sdds { 
	Cheese::Cheese() : m_name("NaC"), m_weight(0), m_price(0.0), m_features("") {};

	Cheese::Cheese(const string& str): m_name("NaC"), m_weight(0), m_price(0.0), m_features("") {
		unsigned startPos = 0;
		unsigned endPos = str.find(',');

		if (endPos != string::npos) {
			m_name = str.substr(startPos, endPos - startPos);
			m_name.erase(0, m_name.find_first_not_of(" \t"));
			m_name.erase(m_name.find_last_not_of(" \t") + 1);
			
			startPos = endPos + 1;
			endPos = str.find(',', startPos);

			if (endPos != string::npos) {
				string weight = str.substr(startPos, endPos - startPos);
				weight.erase(0, weight.find_first_not_of(" \t"));
				weight.erase(weight.find_last_not_of(" \t") + 1);
				m_weight = stoul(weight);

				startPos = endPos + 1;
				endPos = str.find(',', startPos);

				if (endPos != string::npos) {
					string price = str.substr(startPos, endPos - startPos);
					price.erase(0, price.find_first_not_of(" \t"));
					price.erase(price.find_last_not_of(" \t") + 1);
					m_price = stod(price);

					startPos = endPos + 1;
					int flag = 0;
					for (unsigned i = startPos; flag == 0; i = (endPos + 1)) {
						endPos = str.find(',', i);
						if (endPos != string::npos) {
							if (endPos - i <= str.size()) {
								string temp = str.substr(i, endPos - i);
								temp.erase(0, temp.find_first_not_of(" \t"));
								temp.erase(temp.find_last_not_of(" \t") + 1);
								m_features.append(temp);
								m_features.append(", ");
							}
							else {
								string temp = str.substr(i);
								temp.erase(0, temp.find_first_not_of(" \t"));
								temp.erase(temp.find_last_not_of(" \t") + 1);
								m_features.append(temp);
								flag = 1;
							}
						}
						else {
							string temp = str.substr(i);
							temp.erase(0, temp.find_first_not_of(" \t"));
							temp.erase(temp.find_last_not_of(" \t") + 1);
							m_features.append(temp);
							flag = 1;
						}
					}
				}
			}
		}
	}

	Cheese Cheese::slice(size_t weight) {
		Cheese slicedCheese;
		if (weight <= static_cast<size_t>(m_weight)) {
			slicedCheese.m_features = m_features;
			slicedCheese.m_name = m_name;
			slicedCheese.m_price = m_price;
			slicedCheese.m_weight = static_cast<unsigned>(weight);
			m_weight -= weight;
		}
		return slicedCheese;
	}

	string Cheese::getName() {
		return m_name;
	};

	unsigned Cheese::getWeight() {
		return m_weight;
	};

	double Cheese::getPrice() {
		return m_price;
	};

	string Cheese::getFeatures() {
		return m_features;
	};

	std::ostream& Cheese::print(std::ostream& os) const {
		os << "|" << left << setw(21) << m_name << "|" << setw(5) << m_weight << "|"
			<< fixed << setprecision(2) << setw(5) << m_price << "|"
			<< right << setw(34) << m_features << "|\n";

		return os;
	}

	std::ostream& operator<<(std::ostream& os, const Cheese& c) {
		return c.print(os);
	}
}