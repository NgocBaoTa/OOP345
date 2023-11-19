// Workshop 8 - Smart Pointers
// 2019/11 - Cornel

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
}
