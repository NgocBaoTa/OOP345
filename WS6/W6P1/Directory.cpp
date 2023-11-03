/*/////////////////////////////////////////////////////////////////////////
						  Workshop - #6 (P1)
Full Name  : Bao Ngoc Ta
Student ID#: 116038225
Email      : bta@myseneca.ca
Date	   : 03/11/2023
Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/


#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <string>
#include <algorithm>
#include "Directory.h"
using namespace std;

namespace sdds {
	Directory::Directory(const std::string& name)
	{
		m_name = name;
	}

	void Directory::update_parent_path(const std::string& path)
	{
		m_parent_path = path;
		for (auto item : m_contents)
		{
			item->update_parent_path(path + m_name);
		}
	}

	std::string Directory::path() const
	{
		return m_parent_path + m_name;
	}

	NodeType Directory::type() const {
		return NodeType::DIR;
	}

	std::string Directory::name() const {
		return m_name;
	}

	int Directory::count() const {
		return (int)m_contents.size();
	}

	size_t Directory::size() const {
		size_t total = 0u;
		for (Resource* res : m_contents) {
			if (res) {
				total += res->size();
			}
		}
		return total;
	}

	Directory& Directory::operator+=(Resource* resource) {
		for (Resource* res : m_contents) {
			if (res) {
				if (res->name() == resource->name()) {
					throw std::runtime_error("Resource with the same name already exists in the directory.");
				}
			}
		}
		m_contents.push_back(resource);
		resource->update_parent_path(m_parent_path + m_name);
		return *this;
	}


	Resource* Directory::find(const std::string& resourceName, const std::vector<OpFlags>& flags) {
		// Check if the RECURSIVE flag is set
		bool isRecursive = std::find(flags.begin(), flags.end(), OpFlags::RECURSIVE) != flags.end();


		// Search for the resource in the directory
		for (Resource* resource : m_contents) {
			if (resource && resource->name() == resourceName) {
				return resource;
			}

			// If the resource is a directory and the RECURSIVE flag is set, recursively search within that directory
			if (isRecursive && resource && resource->type() == NodeType::DIR) {
				Directory* subDirectory = dynamic_cast<Directory*>(resource);
				if (subDirectory) {
					Resource* foundResource = subDirectory->find(resourceName, flags);
					if (foundResource) {
						return foundResource;
					}
				}
			}
		}

		return nullptr; // Resource not found
	}


	Directory::~Directory() {
		for (auto item : m_contents)
			delete item;
	}
}






