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


#pragma once
#ifndef SDDS_COVIDCOLLECTION_H
#define SDDS_COVIDCOLLECTION_H
#include <string>
#include <vector>

namespace sdds
{
    struct Covid {
        std::string m_country;
        std::string m_city;
        std::string m_variant;
        int m_year;
        size_t m_numOfCase;
        size_t m_numOfDeath;
    };


    class CovidCollection {
        std::vector<Covid> m_covidData;  // a collection of objects of type Covid
        std::string trimSpaces(const std::string& str);
    public:
        CovidCollection(const std::string& file);
        void display(std::ostream& out) const;
    };

    std::ostream& operator<<(std::ostream& out, const Covid& theCovid);
}

#endif

