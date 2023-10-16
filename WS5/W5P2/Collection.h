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
#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H
#include <iomanip>
#include <functional>
#include <stdexcept>
#include <iostream>

namespace sdds {
    template<typename T>
    class Collection {
        std::string m_name{};
        T* m_items{};
        size_t m_size{ };
        std::function<void(const Collection<T>&, const T&)> m_observer;

    public:
        Collection(const std::string& name) : m_name(name), m_items(nullptr), m_size(0), m_observer(nullptr) {};

        ~Collection() {
            if (m_items) {
                delete[] m_items;
                m_items = nullptr;
            }
        }

        // Delete copy constructor and copy assignment operator to prevent copying
        Collection(const Collection<T>&) = delete;
        Collection<T>& operator=(const Collection<T>&) = delete;

        const std::string& name() const {
            return m_name;
        }

        size_t size() const {
            return m_size;
        }

        void setObserver(void (*observer)(const Collection<T>&, const T&)) {
            m_observer = observer;
        }

        Collection<T>& operator+=(const T& item) {
            for (size_t i = 0; i < m_size; i++) {
                if (m_items[i].title() == item.title()) {
                    return *this;
                };
            }

            T* newArr = new T[m_size + 1];
            for (size_t i = 0; i < m_size; ++i) {
                newArr[i] = m_items[i];
            }
            newArr[m_size] = item;
            if (m_items) {
                delete[] m_items;
                m_items = nullptr;
            }
            m_items = newArr;
            m_size += 1;

            if (m_observer) {
                m_observer(*this, item);
            }

            return *this;
        }

        T& operator[](size_t idx) const {
            if (idx >= m_size) {
                throw std::out_of_range("Bad index [" + std::to_string(idx) + "]. Collection has [" + std::to_string(m_size) + "] items.");
            }

            return m_items[idx];
        }

        T* operator[](const std::string& title) const {
            for (size_t i = 0; i < m_size; i++) {
                if (m_items[i].title() == title) {
                    return &m_items[i];
                }
            }

            return nullptr;
        }
    };

    // Overload the insertion operator for Collection
    template <typename T>
    std::ostream& operator<<(std::ostream& os, const Collection<T>& collection) {
        for (size_t i = 0; i < collection.size(); ++i) {
            os << collection[i];
        }
        return os;
    }
}

#endif // !SDDS_COLLECTION_H
