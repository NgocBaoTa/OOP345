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
#ifndef SDDS_ORDEREDCOLLECTION_H
#define SDDS_ORDEREDCOLLECTION_H
#include <iostream>
#include <iomanip>
#include "Book.h"

namespace sdds {
	template<typename T>
	class OrderedCollection : public Collection<T, 72> {
	public:
		using Collection<T, 72>::size;
		using Collection<T, 72>::operator+=;
		using Collection<T, 72>::operator[];
		
		bool operator+=(const T& item) {

			if (Collection<T, 72>::operator+=(item)) {
				T temp;

				for (unsigned i = Collection<T, 72>::size() - 1; i > 0; i--)
				{
					for (unsigned j = 0; j < i; j++)
					{
						if (Collection<T, 72>::operator[](j) > Collection<T, 72>::operator[](j + 1)) {
							temp = Collection<T, 72>::operator[](j);
							Collection<T, 72>::operator[](j) = Collection<T, 72>::operator[](j + 1);
							Collection<T, 72>::operator[](j + 1) = temp;
						}
					}
				}
				return true;
			}
			else {
				return false;
			}
		};
	};
}

#endif // !SDDS_ORDEREDCOLLECTION_H