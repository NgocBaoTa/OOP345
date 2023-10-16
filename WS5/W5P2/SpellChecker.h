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

#pragma once
#ifndef SDDS_SPELLCHECKER_H
#define SDDS_SPELLCHECKER_H
#include <iostream>

namespace sdds {
    class SpellChecker {
        std::string m_badWords[6]{};
        std::string m_goodWords[6]{};
        size_t m_count[6]{};
    public:
        SpellChecker(const char* filename);
        void operator()(std::string& text);
        void showStatistics(std::ostream& out) const;
    };
}

#endif // !SDDS_SPELLCHECKER_H