/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #4 (P1)
Full Name  : Bao Ngoc Ta
Student ID#: 116038225
Email      : bta@myseneca.ca
Date	   : 30/09/2023
Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/

#pragma once
#ifndef SDDS_CHEESE_H
#define SDDS_CHEESE_H
#include <iostream>

namespace sdds {
    class Cheese {
        std::string m_name{"NaC"};
        unsigned m_weight{ 0 };
        double m_price{ 0.0 };
        std::string m_features{""};
    public:
        Cheese();
        Cheese(const std::string& str);
        Cheese slice(size_t weight);
        std::string getName() const;
        unsigned getWeight() const;
        double getPrice() const;
        std::string getFeatures() const;
        std::ostream& print(std::ostream& os) const;
    };

    std::ostream& operator<<(std::ostream& os, const Cheese& cheese);
}

#endif // !SDDS_CHEESE_H