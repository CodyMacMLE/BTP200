#ifndef SENECA_HERO_H
#define SENECA_HERO_H

#include "ability.h"

namespace seneca {
	class Hero {

		/// <summary>
		/// Dynamic array that stores the name of the hero
		/// </summary>
		char* m_name;

		/// <summary>
		/// A Dynamic array that stores all the abilities of the hero
		/// </summary>
		Ability* m_abilities;

		/// <summary>
		/// An int that stores the count of abilites in m_abilities
		/// </summary>
		int m_cntAbilities;

		/// <summary>
		/// Stores the level of the hero (higher level = great power). Empty state is when level is 0.
		/// </summary>
		int m_level;

	public:

		/// <summary>
		/// Initializes the object to an empty state
		/// </summary>
		Hero();

		Hero(const char* name, const Ability* abilities, int cntAbilities);

		/// <summary>
		/// checks whether Hero exists: true if exists, false otherwise.
		/// </summary>
		operator bool() const;
	};
}

#endif // !SENECA_HERO_H
