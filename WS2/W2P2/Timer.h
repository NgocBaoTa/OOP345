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
#ifndef SDDS_TIMER_H
#define SDDS_TIMER_H

#include <chrono>
#include <iostream>

namespace sdds {
    class Timer {
        std::chrono::steady_clock::time_point m_start;
        std::chrono::steady_clock::time_point m_end;

    public:
        void start();
        long long stop();
    };
}

#endif  // !SDDS_TIMER_H