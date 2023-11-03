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


#pragma once
#ifndef SDDS_FILE_H
#define SDDS_FILE_H
#include <string>
#include "Resource.h"
#include "Flags.h"

namespace sdds
{
    class File : public Resource {
        std::string m_contents{""};
    public:
        File(const std::string& name, const std::string& contents = "");
        void update_parent_path(const std::string&);
        NodeType type() const;
        std::string path() const;
        std::string name() const;
        int count() const;
        size_t size() const;
    };
}

#endif