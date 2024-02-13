#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Hero.h"

namespace seneca {

	Hero::Hero() : m_name{ nullptr }, m_abilities{ nullptr }, m_cntAbilities{ 0 }, m_level{ 0 }
	{}

	Hero::Hero(const char* name, const Ability* abilities, int cntAbilities)
	{
		*this = Hero();
		if (name != nullptr || name[0] != '\0')
		{
			m_name = new char[strlen(name) + 1];
			strcpy(m_name, name);
			m_abilities = new Ability[cntAbilities];
			for (auto i = 0; i < cntAbilities; ++i)
			{
				if(abilities[i])
				m_abilities[i] = abilities[i];
			}

		}
	}

	Hero::operator bool() const
	{
		return (m_level > 0) ? true : false;
	}
}