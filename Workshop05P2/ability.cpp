#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "ability.h"

// Cody MacDonald
// cmacdonald33@myseneca.ca
// 159702232
// February 14th, 2024

namespace seneca {

	Ability::Ability(const char* name, int strength)
	{
		if ((name != nullptr || name[0] != '\0') && strength > 0)
		{
			strcpy(a_abilityName, name);
			a_strength = strength;
		}
		else
		{
			a_abilityName[0] = '\0';
			a_strength = 0;
		}
	}

	Ability::operator bool() const
	{
		return (a_strength > 0) ? true : false;
	}

	Ability::operator const char* () const
	{
		return (*this) ? a_abilityName : "Ability does not Exist";
	}

	Ability:: operator int() const
	{
		return (*this) ? a_strength : 0;
	}
}