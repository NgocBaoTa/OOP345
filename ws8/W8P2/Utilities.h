// Workshop 8 - Smart Pointers
// Name: Bao Ngoc Ta
// Seneca Student ID: 116038225
// Seneca email: bta@myseneca.ca
// Date of completion: 11/18/2023
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.


#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H
// Workshop 8 - Smart Pointers

#include "DataBase.h"
#include "Profile.h"

namespace sdds
{
	DataBase<Profile> excludeRaw(const DataBase<Profile>& allProfiles, const DataBase<Profile>& bannedProfiles);
	DataBase<Profile> excludeSmart(const DataBase<Profile>& allProfiles, const DataBase<Profile>& bannedProfiles);
}

#endif
