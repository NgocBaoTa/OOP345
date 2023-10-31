#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <string>
#include <algorithm>
#include "Directory.h"
using namespace std;

namespace sdds {
	Directory::Directory(const std::string& name) : m_name(name) {};

	void Directory::update_parent_path(const std::string& path) {
		m_parentPath = path;
		for (Resource* res : m_contents) {
			if (res) {
				res->update_parent_path(Directory::path());
			}
		}
	}

	NodeType Directory::type() const {
		return NodeType::DIR;
	}

	std::string Directory::path() const {
		if (m_name.empty()) {
			return m_parentPath;
		}
		return m_parentPath + '/' + m_name;
	}

	std::string Directory::name() const {
		return m_name;
	}

	int Directory::count() const {
		return static_cast<int>(m_contents.size());;
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
		resource->update_parent_path(path());
		m_contents.push_back(resource);
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
		for (Resource* resource : m_contents) {
			delete resource;
		}
	}
}