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


#pragma once
#ifndef SDDS_COVIDCOLLECTION_H
#define SDDS_COVIDCOLLECTION_H
#include <string>
#include <vector>
#include <list>

namespace sdds
{
    struct Covid {
        std::string m_country;
        std::string m_city;
        std::string m_variant;
        int m_year;
        size_t m_numOfCase;
        size_t m_numOfDeath;
        std::string m_severity = "General";
    };


    class CovidCollection {
        std::vector<Covid> m_covidData;  // a collection of objects of type Covid
        std::string trimSpaces(const std::string& str);
    public:
        CovidCollection(const std::string& file);
        void display(std::ostream& out, const std::string& country = "ALL") const;   // std::for_each()
        void sort(const std::string& field = "country");   // std::sort()
        bool inCollection(const std::string& variant, const std::string& country, unsigned int deaths) const;  // std::any_of()
        std::list<Covid> getListForDeaths(unsigned int deaths) const;    // std::copy_if()
        void updateStatus();   // std::transform()
    };

    std::ostream& operator<<(std::ostream& out, const Covid& theCovid);
}

#endif

