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

#pragma once
#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H
#include <iostream>

namespace sdds {
    class Book {
        std::string m_title{};
        unsigned m_numChapters{};
        unsigned m_numPages{};
    public:
        Book();
        Book(const std::string& title, unsigned nChapters, unsigned nPages);
        std::ostream& print(std::ostream& os) const;
    };

    std::ostream& operator<<(std::ostream& os, const Book& bk);
}

#endif // !SDDS_BOOK_H
