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
#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H
#include <iostream>

namespace sdds {
    class Book {
        std::string m_author{};
        std::string m_title{};
        std::string m_country{};
        size_t m_year{};
        double m_price{ 0.0 };
        std::string m_description{};
    public:
        Book();
        Book(const std::string& strBook);
        const std::string& title() const;
        const std::string& country() const;
        const size_t& year() const;
        double& price();
        friend std::ostream& operator<<(std::ostream& os, const Book& book);

        template <typename T>
        void fixSpelling(T& spellChecker) {
            spellChecker(m_description);
        }
    };
}

#endif // !SDDS_BOOK_H