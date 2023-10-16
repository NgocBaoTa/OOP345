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
#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H
#include <iostream>
#include "Book.h"

namespace sdds {
	template<typename T, unsigned C>
	class Collection {
		T m_items[C]{};
		unsigned m_size{ 0 };
		static T m_smallestItem;
		static T m_largestItem;
	protected:
		void setSmallestItem(const T item) {
			if (m_smallestItem < item) {
				m_smallestItem = item;
			}
		};
		void setLargestItem(const T item) {
			if (m_largestItem > item) {
				m_largestItem = item;
			}
		};
	public:
		Collection() { };
		T getSmallestItem() {
			return m_smallestItem;
		};

		T getLargestItem() {
			return m_largestItem;
		};

		unsigned size() const {
			return m_size;
		};

		unsigned capacity() const {
			return C;
		};

		bool operator+=(const T item) {
			if (m_size == C) {
				return false;
			}
			else {
				setLargestItem(item);
				setSmallestItem(item);
				m_size++;
				m_items[m_size] = item;
				return true;
			}
		};
		std::ostream& print(std::ostream& os) const {
			os << "[";
			for (unsigned i = 0; i < m_size - 1; i++) {
				os << m_items[i] << ",";
			}
			os << m_items[m_size - 1];

			os << "]\n";

			return os;
		};
	};


	template <typename T, unsigned C>
	T Collection<T, C>::m_smallestItem{9999};

	template <typename T, unsigned C>
	T Collection<T, C>::m_largestItem{-9999};

	template <>
	Book Collection<Book, 10>::m_smallestItem = Book("", 1, 10000);

	template <>
	Book Collection<Book, 10>::m_largestItem = Book("", 10000, 1);
}

#endif // !SDDS_COLLECTION_H