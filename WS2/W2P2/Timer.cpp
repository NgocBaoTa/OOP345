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

#define _CRT_SECURE_NO_WARNINGS
#include "Timer.h"

namespace sdds {
    void Timer::start() {
        m_start = std::chrono::steady_clock::now();
    }

    long long Timer::stop() {
        m_end = std::chrono::steady_clock::now();
        long long time = std::chrono::duration_cast<std::chrono::nanoseconds>(m_end - m_start).count();
        return time;
    }
}