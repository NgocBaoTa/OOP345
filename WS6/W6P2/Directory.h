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
#ifndef SDDS_DIRECTORY_H
#define SDDS_DIRECTORY_H
#include <string>
#include <vector>
#include "Resource.h"
#include "Flags.h"


namespace sdds
{
    class Directory : public Resource {
        std::vector<Resource*> m_contents;
    public:
        Directory(const std::string& name);
        void update_parent_path(const std::string&);
        NodeType type() const;
        std::string path() const;
        std::string name() const;
        int count() const;
        size_t size() const;
        Directory& operator+=(Resource*);
        Resource* find(const std::string& resourceName, const std::vector<OpFlags>& flags = {});
        ~Directory();
        Directory(const Directory&) = delete;
        Directory& operator=(const Directory&) = delete;
        Directory(Directory&&) = delete;
        Directory& operator=(Directory&&) = delete;
        void remove(const std::string& name, const std::vector<OpFlags>& flags = {});
        void display(std::ostream& os, const std::vector<FormatFlags>& flags = {}) const;
    };
}

#endif