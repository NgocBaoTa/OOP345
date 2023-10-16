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
#ifndef SDDS_MOVIE_H
#define SDDS_MOVIE_H
#include <iostream>

namespace sdds {
    class Movie {
        std::string m_title{};
        size_t m_year{};
        std::string m_description{};
    public:
        Movie();
        const std::string& title() const;
        Movie(const std::string& strMovie);
        friend std::ostream& operator<<(std::ostream& os, const Movie& movie);

        template <typename T>
        void fixSpelling(T& spellChecker) {
            spellChecker(m_title);
            spellChecker(m_description);
        }
    };
}

#endif // !SDDS_MOVIE_H