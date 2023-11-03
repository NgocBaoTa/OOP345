/*/////////////////////////////////////////////////////////////////////////
						  Workshop - #6 (P2)
Full Name  : Bao Ngoc Ta
Student ID#: 116038225
Email      : bta@myseneca.ca
Date	   : 03/11/2023
Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/


#ifndef SDDS_FILESYSTEM_H
#define SDDS_FILESYSTEM_H

#include <string>
#include "Directory.h"

namespace sdds
{
	class Filesystem
	{
		Directory* m_root{};
		Directory* m_current{};

		void addResource(std::string&, const std::string & = "");
	public:
		Filesystem(const char*, const std::string & = std::string());
		Filesystem(Filesystem&&) noexcept;
		Filesystem& operator=(Filesystem&&) noexcept;
		Filesystem& operator+=(Resource*);
		Directory* change_directory(const std::string & = "");
		Directory* get_current_directory() const;
		~Filesystem();
		Filesystem& operator=(Filesystem&) = delete;
		Filesystem(Filesystem&) = delete;
	};

	void trimString(std::string&);
}

#endif