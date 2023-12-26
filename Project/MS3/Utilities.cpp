// Name: Bao Ngoc Ta
// Seneca Student ID: 116038225
// Seneca email: bta@myseneca.ca
// Date of completion: 29/11/2023
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#define _CRT_SECURE_NO_WARNINGS
#include "Utilities.h"
using namespace std;

namespace sdds {
	char Utilities::m_delimiter = ',';

	std::string Utilities::trimSpaces(const std::string& str)
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

	void Utilities::setFieldWidth(size_t newWidth)
	{
		m_widthField = newWidth;
	}

	size_t Utilities::getFieldWidth() const
	{
		return m_widthField;
	}

	std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more) {
		std::string token;
		if (str.find(m_delimiter, next_pos) != std::string::npos) {
			if (str.find(m_delimiter, next_pos) == next_pos) {
				more = false;
				throw "Delimiter is found at the end of string";
			}

			size_t startPos = next_pos;
			size_t endPos = str.find(m_delimiter, next_pos);

			token = trimSpaces(str.substr(startPos, endPos - startPos));
			next_pos = endPos + 1;
			more = true;

			if (m_widthField < token.length()) {
				m_widthField = token.length();
			}
		}
		else {
			size_t startPos = next_pos;
			size_t endPos = str.find(m_delimiter, next_pos);

			token = trimSpaces(str.substr(startPos, endPos - startPos));
			next_pos = endPos + 1;
			more = false;


			if (m_widthField < token.length()) {
				m_widthField = token.length();
			}
		}

		return token;

	};

	void Utilities::setDelimiter(char newDelimiter)
	{
		m_delimiter = newDelimiter;
	}

	char Utilities::getDelimiter()
	{
		return m_delimiter;
	}


}

