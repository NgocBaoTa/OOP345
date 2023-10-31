#pragma once
#ifndef SDDS_FILE_H
#define SDDS_FILE_H
#include <string>
#include "Resource.h"
#include "Flags.h"

namespace sdds
{
    class File : public Resource {
        std::string m_name{""};
        std::string m_contents{""};
        std::string m_parentPath{""};
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