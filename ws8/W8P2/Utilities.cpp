// Workshop 8 - Smart Pointers
// 2019/11 - Cornel
// Name: Bao Ngoc Ta
// Seneca Student ID: 116038225
// Seneca email: bta@myseneca.ca
// Date of completion: 11/18/2023
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include <memory>
#include <utility>
#include "DataBase.h"
#include "Profile.h"
#include "Utilities.h"

using namespace std;

namespace sdds {
	DataBase<Profile> excludeRaw(const DataBase<Profile>& allProfiles, const DataBase<Profile>& bannedProfiles) {
		DataBase<Profile> result;
		// TODO: Add your code here to build a collection of Profiles.
		//         The result should contain only profiles from `allProfiles`
		//         which are not in `bannedProfiles` using Raw Pointers.
		bool found = false;
		for (size_t i = 0; i < allProfiles.size(); ++i) {
			found = false;
			for (size_t j = 0; j < bannedProfiles.size(); ++j) {
				if (allProfiles[i].m_name.last_name == bannedProfiles[j].m_name.last_name &&
					allProfiles[i].m_name.first_name == bannedProfiles[j].m_name.first_name &&
					allProfiles[i].m_age == bannedProfiles[j].m_age) {
					found = true;
					break;
				}
			}

			if (!found) {
				Profile* pf = new Profile(allProfiles[i].m_name, allProfiles[i].m_address, allProfiles[i].m_age);
				try {
					pf->validateAddress();
					result += pf;
					delete pf;
					pf = nullptr;
				}
				catch (const std::string& error) {
					delete pf;
					pf = nullptr;
					throw std::string("*** Invalid Address ***");
				}
			}
		}

		return result;
	}


	DataBase<Profile> excludeSmart(const DataBase<Profile>& allProfiles, const DataBase<Profile>& bannedProfiles) {
		DataBase<Profile> result;
		bool found = false;

		for (size_t i = 0; i < allProfiles.size(); ++i) {
			found = false;
			for (size_t j = 0; j < bannedProfiles.size(); ++j) {
				if (allProfiles[i].m_name.last_name == bannedProfiles[j].m_name.last_name &&
					allProfiles[i].m_name.first_name == bannedProfiles[j].m_name.first_name &&
					allProfiles[i].m_age == bannedProfiles[j].m_age) {
					found = true;
					break;
				}
			}

			if (!found) {
				std::unique_ptr<Profile> pf(new Profile(allProfiles[i].m_name, allProfiles[i].m_address, allProfiles[i].m_age));
					pf->validateAddress();
					result += pf;
			}
		}

		return result;
	}
}
