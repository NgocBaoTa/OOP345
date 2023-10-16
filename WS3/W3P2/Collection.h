/*/////////////////////////////////////////////////////////////////////////
						  Workshop - #3 (P2)
Full Name  : Bao Ngoc Ta
Student ID#: 116038225
Email      : bta@myseneca.ca
Date	   : 30/09/2023
Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/

#pragma once
#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H
#include <iostream>
#include <iomanip>
#include "Book.h"

namespace sdds {
    template<typename T, unsigned C>
    class Collection {
        T m_items[C]{};
        unsigned m_size{ };
        static T m_smallestItem;
        static T m_largestItem;

    protected:
        void setSmallestItem(const T& item) {
            if (item < m_smallestItem) {
                m_smallestItem = item;
            }
        }

        void setLargestItem(const T& item) {
            if (item > m_largestItem) {
                m_largestItem = item;
            }
        }

        T& operator[](unsigned index) {
            return m_items[index];
        }

        void incrSize() {
            m_size++;
        }

    public:

        T getSmallestItem() const {
            std::cout.setf(std::ios::fixed);
            std::cout.precision(1);
            return m_smallestItem;
        }

        T getLargestItem() const {
            std::cout.setf(std::ios::fixed);
            std::cout.precision(1);
            return m_largestItem;
        }

        unsigned size() const {
            return m_size;
        }

        unsigned capacity() const {
            return C;
        }

        bool operator+=(const T& item) {
            bool result = false;
            if (m_size < C) {
                setLargestItem(item);
                setSmallestItem(item);
                m_items[m_size++] = item;
                result = true;
            }

            return result;
        }

        std::ostream& print(std::ostream& os) const {
            os << "[";
            for (unsigned i = 0; i < m_size; i++) {
                os << m_items[i];
                if (i < m_size - 1) {
                    os << ",";
                }
            }
            os << "]\n";

            return os;
        }
    };

    template <typename T, unsigned C>
    T Collection<T, C>::m_smallestItem{9999};

    template <typename T, unsigned C>
    T Collection<T, C>::m_largestItem{-9999};

    template <>
    Book Collection<Book, 10>::m_largestItem = Book("", 10000, 1);

    template <>
    Book Collection<Book, 10>::m_smallestItem = Book("", 1, 10000);

    template <>
    Book Collection<Book, 72>::m_smallestItem = Book("", 1, 10000);

    template <>
    Book Collection<Book, 72>::m_largestItem = Book("", 10000, 1);

    template <>
    std::ostream& Collection<Book, 10>::print(std::ostream& os) const {
        os << "| ---------------------------------------------------------------------------|" << std::endl;
        for (unsigned i = 0; i < m_size; i++) {
            os << "| " << std::setw(58) << std::left << m_items[i] << " |" << std::endl;
        }
        os << "| ---------------------------------------------------------------------------|" << std::endl;

        return os;
    }

    template <>
    std::ostream& Collection<Book, 72>::print(std::ostream& os) const {
        os << "| ---------------------------------------------------------------------------|" << std::endl;
        for (unsigned i = 0; i < m_size; i++) {
            os << "| " << std::setw(58) << std::left << m_items[i] << " |" << std::endl;
        }
        os << "| ---------------------------------------------------------------------------|" << std::endl;

        return os;
    }
}

#endif // !SDDS_COLLECTION_H
