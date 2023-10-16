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
#ifndef SDDS_CHEESEPARTY_H
#define SDDS_CHEESEPARTY_H
#include <iostream>
#include "Cheese.h"

namespace sdds {
    class CheeseParty {
        const Cheese** m_partyCheeses{nullptr}; // Array of pointers to Cheese objects
        unsigned m_partyCount{ 0 };
    public:
        CheeseParty() : m_partyCheeses(nullptr), m_partyCount(0) {};
        ~CheeseParty();


        void deleteCheese(const unsigned index);
        int findEmptyCheese();

        CheeseParty& operator=(const CheeseParty& src);
        CheeseParty& operator=(CheeseParty&& src);
        CheeseParty(const CheeseParty& src);
        CheeseParty(CheeseParty&& src);

        CheeseParty& addCheese(const Cheese&);
        CheeseParty& removeCheese();
        friend std::ostream& operator<<(std::ostream& os, const CheeseParty& party);
    };
}

#endif // !SDDS_CHEESEPARTY_H