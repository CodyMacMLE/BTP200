#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "ability.h"

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
		if (*this)
			return a_abilityName;
	}

	Ability:: operator int() const
	{
		if (*this)
			return a_strength;
	}
}