/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #4 (P2)
Full Name  : Bao Ngoc Ta
Student ID#: 116038225
Email      : bta@myseneca.ca
Date	   : 07/10/2023
Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/

#pragma once
#ifndef SDDS_CHEESESHOP_H
#define SDDS_CHEESESHOP_H
#include <iostream>
#include "Cheese.h"

namespace sdds {
    class CheeseShop {
        std::string m_name{};
        const Cheese** m_cheeses{nullptr}; // Array of pointers to Cheese objects
        unsigned m_count{ 0 };
    public:
        CheeseShop();
        CheeseShop(const std::string& name);
        ~CheeseShop();

        CheeseShop& operator=(const CheeseShop& src);
        CheeseShop& operator=(CheeseShop&& src);
        CheeseShop(const CheeseShop& src);
        CheeseShop(CheeseShop&& src);

        CheeseShop& addCheese(const Cheese&);
        friend std::ostream& operator<<(std::ostream& os, const CheeseShop& shop);
    };

}

#endif // !SDDS_CHEESESHOP_H